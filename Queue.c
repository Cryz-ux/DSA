#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} Node, *NodePtr;

typedef struct {
	NodePtr first;
	NodePtr rear;
} Queue;

// initialize queue
void initQueue(Queue* q){
	q->first = NULL;
	q->rear = NULL;
}

// check if queue is empty
int isEmpty(Queue* q){
	return q->first == NULL;
}

// Enqueue
void enqueue(Queue* q, int value){
	NodePtr newNode = (NodePtr)malloc(sizeof(Node));
	if(newNode == NULL){
		printf("Memory Allocation Failed\n");
		exit(1);
	}
	newNode->data = value;
	newNode->next= NULL;
	if (isEmpty(q)){
		q->first = newNode;
	} else {
		q->rear->next = newNode;
	}
	q->rear = newNode;
}

// Dequeue
int dequeue(Queue* q){
	if (isEmpty(q)){
		printf("The Queue is empty, cannot dequeue.\n");
		exit(1);
	}
	
	NodePtr temp = q->first;
	int value = temp->data;
	q->first = q->first->next;
	
	if(q->first == NULL){
		q->rear = NULL;
	}
	free(temp);
	return value;
}

//get front element
int front(Queue* q){
	if(isEmpty(q)) {
		printf("Queue is empty.\n");
		exit(1);
	}
	return q->first->data;
}

//get rear element
int rear(Queue* q){
	if(isEmpty(q)){
		printf("Queue is empty.\n");
		exit(1);
	}
	return q->rear->data;
}

int main(){
	Queue q;
	initQueue(&q);
	
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	
	printf("Front element: %d\n", front(&q));
	printf("Rear element: %d\n", rear(&q));
	
	printf("Dequeued: %d\n", dequeue(&q));
	
	printf("Front element: %d\n", front(&q));
	printf("Rear element: %d\n", rear(&q));
}

