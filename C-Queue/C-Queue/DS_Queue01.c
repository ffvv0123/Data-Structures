#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 20

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int rear;
	int front;
} Queue;

void init_queue(Queue *q);
int is_empty(Queue* q);
int is_full(Queue* q);
void enqueue(Queue* q, element item);
element dequeue(Queue* q);
element peek(Queue* q);
void print_queue(Queue* q);

int main() {
	Queue q;
	init_queue(&q);

	enqueue(&q, 10);
	enqueue(&q, 20); 
	enqueue(&q, 30);
	print_queue(&q);

	peek(&q);
	print_queue(&q);

	dequeue(&q);
	dequeue(&q);
	print_queue(&q);
	
	return 0;
}

void init_queue(Queue* q) {
	q->rear = -1;
	q->front = -1;
}

int is_empty(Queue* q) {
	return (q->rear == q->front);
}

int is_full(Queue* q) {
	return (q->rear == MAX_QUEUE_SIZE - 1);
}

void enqueue(Queue* q, element item) {
	if (is_full(q)) {
		fprintf(stderr, "WARNINGS: LINEAR_QUEUE_FULL!\n");
		exit(1);
	}
	q->data[++(q->rear)] = item;
	printf("Enqueue %d in queue\n", item);
}

element dequeue(Queue* q) {
	if (is_empty(q)) {
		fprintf(stderr, "WARNINGS: LINEAR_QUEUE_EMPTY!\n");
		exit(1);
	}
	element item = q->data[++(q->front)];
	printf("dequeue out queue (item): %d\n", item);
	return item;
}

element peek(Queue* q) {
	if (is_empty(q)) {
		fprintf(stderr, "WARNINGS: LINEAR_QUEUE_EMPTY!\n");
		exit(1);
	}
	element data = q->data[q->front + 1];
	printf("Peek out queue (item): %d\n", data);
	return data;
}

void print_queue(Queue* q) {
	printf("\n<<<<<<<<<< Printing Linear Queue >>>>>>>>>>\n");
	printf("Index: ");
	for (int i = q->front + 1; i <= q->rear; i++) printf("%-4d", i);
	printf("\nValue: ");
	for (int i = q->front + 1; i <= q->rear; i++) printf("%-4d", q->data[i]);
	printf("\nRear: %d, Front: %d", q->rear, q->front);
	printf("\n\n");
}