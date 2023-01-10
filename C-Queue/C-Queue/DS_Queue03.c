#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct {
	int rear, front;
	int count;
	int capacity;
	element* data;
} Queue;

void init_queue(Queue* q);
int is_empty(Queue* q);
int is_full(Queue* q);
void enqueue(Queue* q, element item);
element dequeue(Queue* q);
element peek(Queue* q);
void print_queue(Queue* q);
int get_count(Queue* q);
void delete_queue(Queue* q);

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

	//delete_queue(&q);
	return 0;
}

void init_queue(Queue* q) {
	q->rear = q->front = 0;
	q->count = 0;
	q->capacity = 1;
	q->data = (element*)malloc(q->capacity * sizeof(element));
}

int is_empty(Queue* q) {
	return q->rear == q->front;
}

int is_full(Queue* q) {
	return (q->count == q->capacity - 1);
}

void enqueue(Queue* q, element item) {
	if (is_full(q)) {
		q->capacity *= 2;
		q->data = (element*)realloc(q->data, q->capacity * sizeof(element));
	}

	printf("Enqueue %d in queue\n", item);

	q->data[++(q->rear)] = item;
	q->count++;
}

element dequeue(Queue* q) {
	if (is_empty(q)) {
		fprintf(stderr, "WARNINGS: DYNAMIC_QUEUE_EMPTY!\n");
		exit(1);
	}
	element data = q->data[++(q->front)];
	q->count--;
	printf("dequeue out queue (item): %d\n", data);

	return data;
}

void print_queue(Queue* q) {
	printf("\n<<<<<<<<<< Dynamic Linear Queue >>>>>>>>>>\n");
	printf("Index: ");
	for (int i = q->front + 1; i <= q->rear; i++) printf("%-4d", i);
	printf("\nValue: ");
	for (int i = q->front + 1; i <= q->rear; i++) printf("%-4d", q->data[i]);
	printf("\nRear: %d, Front: %d\nNumber of items: %d\n", q->rear, q->front, q->count);
	printf("\n\n");
}

void delete_queue(Queue* q) {
	free(q->data);
}

int get_count(Queue* q) {
	return q->count;
}

element peek(Queue* q) {
	if (is_empty(q)) {
		fprintf(stderr, "WARNINGS: DYNAMIC_QUEUE_EMPTY!\n");
		exit(1);
	}
	element data = q->data[q->front + 1];
	printf("Peek out queue (item): %d\n", data);
	return data;
}