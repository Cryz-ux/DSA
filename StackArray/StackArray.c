#include <stdio.h>
#include <stdlib.h>
#include "StackArray.h"

// Initialize the stack
void initStack(StackArrayList *s) {
    s->top = -1;
}

// Create and return an initialized stack
StackArrayList createStack() {
    StackArrayList s;
    initStack(&s);
    return s;
}

// Push an item onto the stack
bool stack_push(StackArrayList *s, int elem) {
    if (s->top == MAX - 1) {
        // Stack overflow
        return false;
    }
    s->data[++(s->top)] = elem;
    return true;
}

// Pop an item from the stack
bool stack_pop(StackArrayList *s) {
    if (s->top == -1) {
        // Stack underflow
        return false;
    }
    s->top--;
    return true;
}

// Peek at the top item of the stack
int stack_peek(StackArrayList s) {
    if (s.top == -1) {
        // Stack is empty
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return s.data[s.top];
}

// Display the stack
void display(StackArrayList s) {
	int i;
    if (s.top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (i = 0; i <= s.top; i++) {
        printf("%d ", s.data[i]);
    }
    printf("\n");
}

// Visualize the stack
void visualize(StackArrayList s) {
	int i;
    if (s.top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (i = s.top; i >= 0; i--) {
        printf("| %d |\n", s.data[i]);
    }
    printf("-----\n");
}

