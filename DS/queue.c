#include "queue.h"

queue_p get_queue()
{
	queue_p queue = calloc(1, sizeof(queue_t));
	queue->head = calloc(1, sizeof(dlist_p *));
	return queue;
}

bool enqueue(queue_p queue, void *val)
{
	dlist_p nodeptr = calloc(1, sizeof(dlist_t));
	nodeptr->data = val;
	if (add_head_dlist(queue->head, nodeptr))
		return TRUE;
	else
		return FALSE;
}

void * dequeue(queue_p queue)
{
	void *data = get_tail_dlist(queue->head);

	if (delete_tail_dlist(queue->head) == -1)
		printf("head or first node is NULL!\n");

	return data;
}

bool destroy_queue(queue_p queue)
{
	if (destroy_dlist(queue->head) == -1)
		return FALSE;

	free(queue->head);
	free(queue);

	return TRUE;
}

int current_log_level = DEBUG;

#if 1
int main()
{
	int count = 5;
	int arr[5] = {0, 1, 2, 3, 4};
	int * val;

	queue_p queue = get_queue();
	while (count--) {
		if (enqueue(queue, &arr[count]) == FALSE) {
			printf("Error\n");
			destroy_queue(queue);
			return -1;
		}

		printf("Node added\n");
	}

	count = 5;

	while (count--) {
		if ((val = dequeue(queue)) != NULL) {
			printf("arr[%d] = %d\n", count, (int)*val);
		} else
			printf("Received NULL\n");
	}

	destroy_queue(queue);

	return 0;
}
#endif

#if 0
int main()
{
	int count = 5;

	dlist_p *head_pp = calloc(1, sizeof(dlist_p *));
	while (count--) {
		dlist_p node_p = calloc(1, sizeof(dlist_t));
		printf("node address %p\n", node_p);
		if (add_head_dlist(head_pp, node_p) == -1) {
			printf("Error\n");
			return -1;
		}

		printf("Node added\n");
	}

	printf("Total nodes1: %d\n", count_nodes_dlist(head_pp));

	if (delete_head_dlist(head_pp)) {
		printf("Total nodes after head delete: %d\n", count_nodes_dlist(head_pp));
	} else {
		printf("Error: delete_head_dlist()\n");
		return -1;
	}

	printf("Total nodes2: %d\n", count_nodes_dlist(head_pp));

	if (delete_tail_dlist(head_pp)) {
		printf("Total nodes after tail delete: %d\n", count_nodes_dlist(head_pp));
	} else {
		printf("Error: delete_tail_dlist()\n");
		return -1;
	}

	printf("Nodes destroyed: %d\n", destroy_dlist(head_pp));
	printf("Total nodes: %d\n", count_nodes_dlist(head_pp));

	free(head_pp);

	return 0;
}
#endif