#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1

typedef int element;

typedef struct QueueNode {
	element data;
	struct QueueNode* link;
} QueueNode;

typedef struct {
	QueueNode* rear, * front;
} LinkedQueueType;

void init_queue(LinkedQueueType* q);
int is_empty(LinkedQueueType* q);
void enqueue(LinkedQueueType* q, element item);
element dequeue(LinkedQueueType* q);
element peek(LinkedQueueType* q);
void print_queue(LinkedQueueType* q);

/*
	// To embody some special functions
	queue_size()	return number of queue's items
	queue_search()	to search with index in queue, return item
	queue_is_in()	to find if item is in the queue
*/

int queue_size(LinkedQueueType* q);
element queue_search(LinkedQueueType* q, int index);
int queue_is_in(LinkedQueueType* q, element item);

int main() {
	LinkedQueueType q;
	init_queue(&q);
	print_queue(&q);

	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	print_queue(&q);
	queue_size(&q);

	peek(&q);
	print_queue(&q);

	dequeue(&q);
	dequeue(&q);
	print_queue(&q);
	queue_size(&q);

	enqueue(&q, 40);
	enqueue(&q, 11);
	print_queue(&q);

	enqueue(&q, 4);
	enqueue(&q, 11);
	enqueue(&q, 7);
	print_queue(&q);
	queue_size(&q);
	queue_search(&q, 4);

	dequeue(&q);
	enqueue(&q, 11);
	print_queue(&q);
	queue_is_in(&q, 11);
	queue_is_in(&q, 0);

	return 0;

}

void init_queue(LinkedQueueType* q) {
	q->rear = q->front = 0;
}

int is_empty(LinkedQueueType* q) {
	return (q->front == NULL);
}

void enqueue(LinkedQueueType* q, element item) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = item;
	temp->link = NULL;

	if (is_empty(q)) {
		q->rear = temp;
		q->front = temp;
	}
	else {
		q->rear->link = temp;
		q->rear = temp;
	}
	printf("Enqueue %d in queue\n", item);
}

element dequeue(LinkedQueueType* q) {
	if (is_empty(q)) {
		fprintf(stderr, "WARNINGS: LINKED_QUEUE_EMPTY!\n");
		exit(1);
	}
	QueueNode* temp = q->front;
	element item = temp->data;
	q->front = q->front->link;
	if (!(q->front))
		q->rear = NULL;

	printf("dequeue out queue (item): %d\n", item);
	free(temp);
	return item;
}

element peek(LinkedQueueType* q) {
	if (is_empty(q)) {
		fprintf(stderr, "WARNINGS: LINKED_QUEUE_EMPTY!\n");
		exit(1);
	}
	element data = q->front->data;
	printf("Peek out queue (item): %d\n", data);
	return data;
}

void print_queue(LinkedQueueType* q) {
	int i = 0;
	printf("\n<<<<<<<<<< Printing Linked Queue >>>>>>>>>>\n");
	printf("Index: ");
	for (QueueNode* p = q->front; p != NULL; p = p->link) {
		printf("%-4d", i);
		i++;
	}
	printf("\nValue: ");
	for (QueueNode* p = q->front; p != NULL; p = p->link) printf("%-4d", p->data);
	printf("\n\n");
}

int queue_size(LinkedQueueType* q) {
	int size = 0;
	for (QueueNode* temp = q->front; temp != NULL; temp = temp->link)
		size++;
	printf("Queue size: %d\n", size);
	return size;
}

element queue_search(LinkedQueueType* q, int index) {
	if (is_empty(q)) {
		fprintf(stderr, "WARNINGS: QUEUE_EMPTY!\n");
		exit(1);
	}

	QueueNode* p = q->front;

	for (int i = 0; i < index; i++) {
		if (p == NULL) {
			fprintf(stderr, "WARNINGS: Incorrect Index!\n");
			exit(1);
		}
		p = p->link;
	}
	printf("Queue's index(%d) item: %d\n", index, p->data);
	return p->data;
}

int queue_is_in(LinkedQueueType* q, element item) {
	int i = 0;
	int check = 0;
	for (QueueNode* temp = q->front; temp != NULL; temp = temp->link) {
		if (temp->data == item) {
			printf("%d is in queue's %d'th index\n", item, i);
			check++;
		}
		i++;
	}
	if(check==0) printf("%d is in not in queue\n", item);

	return (check > 0) ? FALSE : TRUE;
}
