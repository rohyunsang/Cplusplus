#include <stdio.h>
#include <stdlib.h> //malloc, free 메모리 할당, 해제
struct NODE
{
	struct NODE* next;
	int data;
};

int LinkedList() {

	struct NODE* head = (NODE*)malloc(sizeof (struct NODE));

	struct NODE* node1 = (NODE*)malloc(sizeof(struct NODE));
	if(head) head->next = node1;
	if(node1) node1->data = 10;

	struct NODE* node2 = (NODE*)malloc(sizeof(struct NODE));
	if(node1) node1->next = node2;
	if(node2) node2->data = 20;
	
	
	if(node2) node2->next = NULL;
	if(head) {
		struct NODE* cur = head->next;

		while (cur != NULL) {
			printf("%d \n", cur->data);
			cur = cur->next;
		}
	}

	free(node2);
	free(node1);
	free(head);

	return 0;
}
