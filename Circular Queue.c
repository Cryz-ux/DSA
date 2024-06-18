#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int front;
    int rear;
} CircularQ;

//initialize the circular queue
void initQueue(CircularQ *q) {
    q->front = 0;
    q->rear = -1;
}

//check if the queue is empty
int isEmpty(CircularQ *q) {
    return (q->rear + 1) % MAX == q->front;
}

//check if the queue is full
int isFull(CircularQ *q) {
    return (q->rear + 2) % MAX == q->front;
}

//enqueue an element
void enqueue(CircularQ *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }

    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = value;
    printf("Enqueued %d\n", value);
}

//dequeue an element
int dequeue(CircularQ *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }

    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX;
    printf("Dequeued %d\n", value);
    return value;
}

//display the elements of the queue
void display(CircularQ *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    int i = q->front;
    while (i != (q->rear + 1) % MAX) {
        printf("%d ", q->data[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    CircularQ q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    display(&q);

    dequeue(&q);
    display(&q);

    enqueue(&q, 5);
    enqueue(&q, 6);
    display(&q);

    return 0;
}

