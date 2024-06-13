#ifndef STACK_ARRAY
#define STACK_ARRAY

#include<stdbool.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} StackArrayList;

//initialize the stack
void initStack(StackArrayList *s) {
    s->top = -1;
}

//create and return an initialized stack
StackArrayList createStack() {
    StackArrayList s;
    initStack(&s);
    return s;
}

//push an item onto the stack
bool stack_push(StackArrayList *s, int elem) {
    if (s->top == MAX - 1) {
        // Stack overflow
        return false;
    }
    s->data[++(s->top)] = elem;
    return true;
}

//pop an item from the stack
bool stack_pop(StackArrayList *s) {
    if (s->top == -1) {
        // Stack underflow
        return false;
    }
    s->top--;
    return true;
}

//peek at the top item of the stack
int stack_peek(StackArrayList s) {
    if (s.top == -1) {
        // Stack is empty
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return s.data[s.top];
}

//display the stack
void display(StackArrayList s) {
    if (s.top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i <= s.top; i++) {
        printf("%d ", s.data[i]);
    }
    printf("\n");
}

//visualize the stack
void visualize(StackArrayList s) {
    if (s.top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = s.top; i >= 0; i--) {
        printf("| %d |\n", s.data[i]);
    }
    printf("-----\n");
}


#endif
