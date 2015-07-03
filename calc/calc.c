/*
 * A fun calculator using a stack.
 *
 * Author: Arun Prakash Jana <engineerarun@gmail.com>
 * Copyright (C) 2015 by Arun Prakash Jana <engineerarun@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with tictactoe.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 34

int count = 0;
double poppedElem = 0;

struct node
{
	double info;
	struct node *ptr;
} *top, *top1, *temp;

void create()
{
	top = NULL;
}

int push(double data)
{
	if (top == NULL) {
		top = (struct node *) malloc(1*sizeof(struct node));
		if(top == NULL)
			return -1;
		top->ptr = NULL;
		top->info = data;
	} else {
		temp = (struct node *) malloc(1*sizeof(struct node));
		if(temp == NULL)
			return -1;
		temp->ptr = top;
		temp->info = data;
		top = temp;
	}

	count++;
	return 0;
}

int pop()
{
	top1 = top;

	if (top1 == NULL) {
		return -1;
	} else {
		top1 = top1->ptr;
	}

	poppedElem = top->info;
	//printf("Popped value : %f\n", top->info);
	free(top);
	top = top1;
	count--;
	return 0;
}

void destroy()
{
	while (top != NULL) {
		top1 = top;
		top = top->ptr;
		free(top1);
	}

	printf("All stack elements destroyed\n");
	count = 0;
}

int main()
{
	char input[MAXLEN] = {0};
	char ch = '0';
	double val = 0;
	int counter = 0;

	printf("Enter next: ");
	scanf("%33s", input);
	if (strlen(input) > (MAXLEN - 2)) {
		input[MAXLEN - 2] = '\0';
		while (getchar() != '\n' && !feof(stdin));
	}

	for (; input[counter] != '\0'; counter++) {
		if ((input[counter] >= '0' && input[counter] <= '9') || (input[counter] == '.') 
			|| (input[counter] == '+') || (input[counter] == '-') || (input[counter] == '*') 
			|| (input[counter] == '/') || (input[counter] == 'C')) {}
		else {
			printf("ERROR: Invalid input\n");
			return -1;
		}
	}

	ch = input[0];

	while (ch != 'C') {
		if ((ch == '+' || ch == '-' || ch == '*' || ch == '/') && (input[1] == '\0')) {
			if (pop() == 0)
				val = poppedElem;
			else {
				printf("ERROR: No value in stack\n");
				destroy();
				return 0;
			}

			if (ch == '+')
				printf("Adding %f + ", poppedElem);
			else if (ch == '-')
				printf("Subtracting %f - ", poppedElem);
			else if (ch == '*')
				printf("Multiplying %f * ", poppedElem);
			else if (ch == '/')
				printf("Dividing %f / ", poppedElem);

			while (pop() == 0) {
				switch (ch) {
				case '+':
					val += poppedElem;
					printf("%f + ", poppedElem);
					break;
				case '-':
					val -= poppedElem;
					printf("%f - ", poppedElem);
					break;
				case '*':
					val *= poppedElem;
					printf("%f * ", poppedElem);
					break;
				case '/':
					if (poppedElem == (float) 0) {
						printf("\nERROR: Division by 0\n");
						destroy();
						return -1;
					}
					val /= poppedElem;
					printf("%f / ", poppedElem);
					break;
				default:
					printf("ERROR: Should never reach here\n");
					destroy();
					return -1;
				}
			}

			printf("\b\b\b. Result is %f.\n", val);
		//} else if (ch == 'C') {
		//	destroy();
		//	return 0;
		} else {
			double real = atof(input);
			if (push(real) < 0) {
				printf("ERROR: Cannot push value into stack\n");
				destroy();
				return -1;
			}
		}

		memset(input, 0, MAXLEN);
		printf("Enter next: ");
		scanf("%33s", input);
		if (strlen(input) > (MAXLEN - 2)) {
			input[MAXLEN - 2] = '\0';
			while (getchar() != '\n' && !feof(stdin));
		}

		for (counter = 0; input[counter] != '\0'; counter++) {
			if ((input[counter] >= '0' && input[counter] <= '9') || (input[counter] == '.')
				|| (input[counter] == '+') || (input[counter] == '-') || (input[counter] == '*')
				|| (input[counter] == '/') || (input[counter] == 'C')) {}
			else {
				printf("ERROR: Invalid input\n");
				destroy();
				return -1;
			}
		}

		ch = input[0];
	}

	destroy();
	return 0;
}
