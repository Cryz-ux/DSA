#ifndef STACK_ARRAY
#define STACK_ARRAY

#include<stdbool.h>
#define MAX 100


typedef struct{
	int data[MAX];
	int top;
} StackArrayList;

void initStack(StackArrayList *s);
StackArrayList createStack();

bool stack_push(StackArrayList *s, int elem);
bool stack_pop(StackArrayList *s);
bool isEmpty(StackArrayList s);
bool isFull(StackArrayList s);
int stack_peek(StackArrayList s);

void display(StackArrayList s);
void visualize(StackArrayList);

//others 
//

#endif
