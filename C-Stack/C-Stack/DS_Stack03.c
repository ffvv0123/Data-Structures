#include <stdio.h>
#include <stdlib.h>
typedef int element;

typedef struct StackNode {
	element data;
	struct StackNode* link;
} StackNode;

typedef struct {
	StackNode* top;
} LinkedStackType;

void init_stack(LinkedStackType* s);
int is_empty(LinkedStackType* s);
void push(LinkedStackType* s, element item);
element pop(LinkedStackType* s);
element peek(LinkedStackType* s);
void print_stack(LinkedStackType* s);

int main() {
	LinkedStackType s;
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

	return 0;
}

void init_stack(LinkedStackType* s) {
	s->top = NULL;
}

int is_empty(LinkedStackType* s) {
	return (s->top == NULL);
}

void push(LinkedStackType* s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
	printf("Pushing %d in stack\n", item);
}

element pop(LinkedStackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "WARNINGS: STACK_EMPTY!\n");
		exit(1);
	}

	StackNode* temp = s->top;
	int data = temp->data;
	s->top = s->top->link;
	free(temp);
	printf("Pop out stack (item): %d\n", data);
	return data;
}

element peek(LinkedStackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "WARNINGS: STACK_EMPTY!\n");
		exit(1);
	}
	printf("Peek out stack (item): %d\n", s->top->data);
	return s->top->data;
}

void print_stack(LinkedStackType* s) {
	int i = 0;
	printf("\n<<<<<<<<<< Printing Linked Stack >>>>>>>>>>\n");
	printf("Index: ");
	for (StackNode* p = s->top; p != NULL; p = p->link) {
		printf("%-4d", i);
		i++;
	}
	printf("\nValue: ");
	for (StackNode *p = s->top; p != NULL; p = p->link) printf("%-4d", p->data);
	printf("\n\n");
}