 #include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct {
	element *data;
	int capacity;
	int top;
} Stack;


void init_stack(Stack* s);
int is_empty(Stack* s);
int is_full(Stack* s);
void push(Stack* s, element item);
element pop(Stack* s);
element peek(Stack* s);
void print_stack(Stack* s);
void delete_stack(Stack* s);

int main() {
	Stack s;
	init_stack(&s);

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	print_stack(&s);

	pop(&s);
	print_stack(&s);

	push(&s, 4);
	push(&s, 5);
	print_stack(&s);

	peek(&s);
	print_stack(&s);

	delete_stack(&s);
	return 0;
}

void init_stack(Stack* s) {
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(sizeof(element) * s->capacity);
}

int is_empty(Stack* s) {
	return (s->top == -1);
}

int is_full(Stack* s) {
	return (s->top == (s->capacity - 1));
}

void push(Stack* s, element item) {
	if (is_full(s)) {
		s->capacity *= 2;
		s->data = (element *)realloc(s->data, sizeof(element) * s->capacity);
	}

	printf("Pushing %d in stack\n", item);
	s->data[++(s->top)] = item;

}

element pop(Stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "WARNINGS: STACK_EMPTY!\n");
		exit(1);
	}
	else {
		printf("Pop out stack (item): %d\n", s->data[s->top]);
		return (s->data[(s->top)--]);
	}
}

element peek(Stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "WARNINGS: STACK_EMPTY!\n");
		exit(1);
	}
	else {
		printf("Peek out stack (item): %d\n", s->data[s->top]);
		return (s->data[(s->top)]);
	}
}

void print_stack(Stack* s) {
	printf("\n<<<<<<<<<< Printing Dynamic Stack >>>>>>>>>>\n");
	printf("Index: ");
	for (int i = 0; i <= s->top; i++) printf("%-4d", i);
	printf("\nValue: ");
	for (int i = 0; i <= s->top; i++) printf("%-4d", s->data[i]);
	printf("\n\n");
}

void delete_stack(Stack* s) {
	free(s->data);
}