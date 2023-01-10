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

int main() {
	LinkedQueueType q;
	init_queue(&q);
	print_queue(&q);

	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	print_queue(&q);

	peek(&q);
	print_queue(&q);

	dequeue(&q);
	dequeue(&q);
	print_queue(&q);

	enqueue(&q, 40);
	enqueue(&q, 50);
	print_queue(&q);

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