#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1
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

/*
	// To embody some special functions
	stack_size()	return number of stack's items
	stack_search()	to search with index in stack, return item
	stack_is_in()	to find if item is in the stack
	stack_add()		to add item in stack's n'th index
	stack_delete()	to delete n'th stack's item
*/

int stack_size(LinkedStackType *s);
int stack_search(LinkedStackType *s, int index);
int stack_is_in(LinkedStackType* s, element item);
void stack_add(LinkedStackType* s, element item, int index);
element stack_delete(LinkedStackType* s, int index);

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

	pop(&s);
	pop(&s);
	print_stack(&s);

	stack_size(&s);

	push(&s, 6);
	push(&s, 7);
	print_stack(&s);

	stack_search(&s, 0);
	stack_search(&s, 2);

	pop(&s);
	push(&s, 1);
	push(&s, 1);
	print_stack(&s);

	stack_is_in(&s, 1);
	stack_is_in(&s, 5);

	printf("\n");
	stack_add(&s, 100, 3);
	print_stack(&s);

	stack_delete(&s, 3);
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
	for (StackNode* p = s->top; p != NULL; p = p->link) printf("%-4d", p->data);
	printf("\n\n");
}

int stack_size(LinkedStackType* s) {
	int size = 0;
	for (StackNode* p = s->top; p != NULL; p = p->link) {
		size++;
	}
	printf("Stack size: %d\n", size);

	return size;
}

element stack_search(LinkedStackType* s, int index) {
	if (is_empty(s)) {
		fprintf(stderr, "WARNINGS: STACK_EMPTY!\n");
		exit(1);
	}

	StackNode* p = s->top;

	for (int i = 0; i < index; i++) {
		if (p == NULL) {
			fprintf(stderr, "WARNINGS: Incorrect Index!\n");
			exit(1);
		}
		p = p->link;
	}
	printf("Stack's index(%d) item: %d\n", index, p->data);
	return p->data;
}

int stack_is_in(LinkedStackType* s, element item) {
	int i = 0;
	int check = 0;
	for (StackNode* p = s->top; p != NULL; p = p->link) {
		if (p->data == item) {
			printf("%d is in stack's %d'th index\n", item, i);
			check++;
		}
		i++;
	}
	if (check == 0)
		printf("%d is in not in stack\n", item);

	return (check > 0) ? FALSE : TRUE;
}

void stack_add(LinkedStackType* s, element item, int index) {
	if (index <= 0) {
		fprintf(stderr, "WARNINGS: Incorrect Index!\n");
		exit(1);
	}

	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	StackNode* p = s->top;

	for (int i = 0; i < index - 1; i++) {
		if (p == NULL) {
			fprintf(stderr, "WARNINGS: Incorrect Index!\n");
			exit(1);
		}
		p = p->link;
	}

	temp->data = item;
	temp->link = p->link;
	p->link = temp;
	printf("Add %d in stack's %d'th item\n", item, index);
}

element stack_delete(LinkedStackType* s, int index) {
	if (index <= 0) {
		fprintf(stderr, "WARNINGS: Incorrect Index!\n");
		exit(1);
	}
	if (is_empty(s)) {
		fprintf(stderr, "WARNINGS: STACK_EMPTY!\n");
		exit(1);
	}

	StackNode* p = s->top;
	StackNode* temp;

	for (int i = 0; i < index - 1; i++) {
		if (p == NULL) {
			fprintf(stderr, "WARNINGS: Incorrect Index!\n");
			exit(1);
		}
		p = p->link;
	}
	element data = p->link->data;
	temp = p->link;
	p->link = temp->link;
	free(temp);
	printf("delete out stack (item, index): %d, %d\n", data, index);
	return data;
}