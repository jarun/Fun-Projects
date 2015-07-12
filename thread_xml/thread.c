#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <string.h>
 
#define NUM_THREADS 3

/* shared data between threads */
pthread_mutex_t lock_x;
pthread_mutex_t lock_y;

void print_element_names(xmlDoc* doc, xmlNode * a_node, char* buf)
{
	xmlNode *cur_node = NULL;
	xmlAttr *cur_attr = NULL;

	for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
		if (cur_node->type == XML_ELEMENT_NODE) {
			if (strcmp((const char*) cur_node->name, "CarDealership") == 0) {
			}
			else if (strcmp((const char*) cur_node->name, "Car") == 0) {
				sprintf(buf, "\"Worker threadID 0x%lx: Found %s with", syscall(SYS_gettid), cur_node->name);
				for (cur_attr = cur_node->properties; cur_attr; cur_attr = cur_attr->next) {
					xmlChar *id;
					strcat(buf, " ID ");
					id = xmlGetProp(cur_node, cur_attr->name);
					strcat(buf, (const char*) id);
					strcat(buf, ", ");
				}
			} else {
				xmlChar *key = xmlNodeListGetString(doc, cur_node->xmlChildrenNode, 1);
				if (key[0] != 10) {
					if (strcmp((const char*) cur_node->name, "Model") == 0) {
						strcat(buf, (const char*) cur_node->name);
						strcat(buf, " ");
						strcat(buf, (char*)key);

						pthread_mutex_lock(&lock_y);
						printf("%s\"\n", buf);
						pthread_mutex_unlock(&lock_y);
					} else {
						strcat(buf, (const char*) cur_node->name);
						strcat(buf, " ");
						strcat(buf, (char*)key);
						strcat(buf, ", ");
					}
				}
				xmlFree(key);
			}
		}

        	print_element_names(doc, cur_node->children, buf);
	}
}
 
void *thr_func(void *arg)
{
	xmlDoc *doc = NULL;
	xmlNode *root_element = NULL;
	char* xml = "/home/arun/input.xml";
	char* buf = (char*) calloc(128, 1);

	pthread_mutex_lock(&lock_x);
	doc = xmlReadFile(xml, NULL, 0);
	pthread_mutex_unlock(&lock_x);

	sleep(10);

	if (doc == NULL) {
		printf("Error: could not parse file %s\n", xml);
		xmlFreeDoc(doc);
		xmlCleanupParser();
		pthread_exit(NULL);
		free(buf);
		return NULL;
	}

	root_element = xmlDocGetRootElement(doc);
	
	print_element_names(doc, root_element, buf);

	xmlFreeDoc(doc);
	xmlCleanupParser();

	pthread_exit(NULL);
	free(buf);
}
 
int main(int argc, char **argv)
{
	pthread_t thr[NUM_THREADS];
	int i, rc;

	pthread_mutex_init(&lock_x, NULL);
	pthread_mutex_init(&lock_y, NULL);

	for (i = 0; i < NUM_THREADS; ++i) {
		if ((rc = pthread_create(&thr[i], NULL, thr_func, NULL))) {
			fprintf(stderr, "error: pthread_create, rc: %d\n", rc);
			return -1;
		}
	}

	for (i = 0; i < NUM_THREADS; ++i) {
		pthread_join(thr[i], NULL);
	}

	pthread_mutex_destroy(&lock_y);
	pthread_mutex_destroy(&lock_x);

	return 0;
}
