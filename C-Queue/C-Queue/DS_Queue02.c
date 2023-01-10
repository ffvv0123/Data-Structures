#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int rear;
	int front;
	int count;
} Queue;

void init_queue(Queue* q);
int is_empty(Queue* q);
int is_full(Queue* q);
void enqueue(Queue* q, element item);
element dequeue(Queue* q);
element peek(Queue* q);
void print_queue(Queue* q);
int get_count(Queue* q);

int main() {
	Queue q;
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

void init_queue(Queue* q) {
	q->rear = q->front = 0;
	q->count = 0;
}

int is_empty(Queue* q) {
	return q->rear == q->front;
}

int is_full(Queue* q) {
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(Queue* q, element item) {
	if (is_full(q)) {
		fprintf(stderr, "WARNINGS: CIRCULAR_QUEUE_FULL!\n");
		exit(1);
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
	q->count++;
	printf("Enqueue %d in queue\n", item);
}

element dequeue(Queue* q) {
	if (is_empty(q)) {
		fprintf(stderr, "WARNINGS: CIRCULAR_QUEUE_EMPTY!\n");
		exit(1);
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	q->count--;
	printf("dequeue out queue (item): %d\n", q->data[q->front]);

	return q->data[q->front];
}

element peek(Queue* q) {
	if (is_empty(q)) {
		fprintf(stderr, "WARNINGS: LINEAR_QUEUE_EMPTY!\n");
		exit(1);
	}
	element data = q->data[(q->front + 1) % MAX_QUEUE_SIZE];
	printf("Peek out queue (item): %d\n", data);
	return data;
}

void print_queue(Queue* q) {
	printf("\n<<<<<<<<<< Printing Circular Queue >>>>>>>>>>\n");
	printf("Index: ");
	for (int i = 0; i < q->count; i++) printf("%-4d", i);
	printf("\nValue: ");
	int i = q->front;
	do {
		i = (i + 1) % MAX_QUEUE_SIZE;
		printf("%-4d", q->data[i]);
		if (i == q->rear)
			break;
	} while (i != q->front);
	
	printf("\nRear: %d, Front: %d\nNumber of items: %d\n", q->rear, q->front, q->count);
	printf("\n\n");
}

int get_count(Queue* q){
	return q->count;
}