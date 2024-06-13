#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

bool stack_pop(StackArrayList *s){
	// Check if the stack is empty
    if (s->top == -1) {
        // Stack underflow
        return false;
    } else {
        // Decrement top to remove the top element
        s->top--;
        return true;
    }
}

bool stack_push(StackArrayList *s, int elem) {
    // Check if the stack is full
    if (s->top == MAX - 1) {
        // Stack overflow
        return false;
    } else {
        // Increment top and add element to the stack
        s->top++;
        s->data[s->top] = elem;
        return true;
    }
}

void display(StackArrayList s) {
    if (s.top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements:\n");
        for (int i = s.top; i >= 0; i--) {
            printf("%d ", s.data[i]);
        }
        printf("\n");
    }
}

//function calls

int main(){
	StackArrayList stack;
	initStack(&stack)
	
	stack_push(&stack, 5);
	
	display(stack)
	
	return 0;
}




