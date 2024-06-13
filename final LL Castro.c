#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[20];
	int idNum;
	int age;
} info;

typedef struct node {
	info data;
	struct node * next;
} Node, *NodePtr;

//create new node
NodePtr createNode(info data){
	NodePtr newNode = (NodePtr)malloc(sizeof(Node));
	if (newNode == NULL){
		printf("Memory Allocation failed!");
		exit(1);
	}
	
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//insert node to front
void insertFront(NodePtr* head, info data){
	NodePtr newNode = createNode(data);
	newNode->next = *head;
	*head = newNode;
}

void insertEnd(NodePtr* head, info data){
	NodePtr newNode = createNode(data);
	while(*head!=NULL){
		head=&(*head)->next;
	}
	*head = newNode;
}
	
	
	
	
//print
void printList(NodePtr head){
	NodePtr current = head;
	while (current != NULL) {
		printf("Name: %s, ID: %d, Age: %d\n", current->data.name, current->data.idNum, current->data.age);
		current = current->next;
	}
}



int main(){
	NodePtr head = NULL; //empty linked list
	
	info data1 = {"Yani", 1001, 21};
	insertEnd(&head, data1);
	
	info data2 = {"YaniA", 1002, 20};
	insertFront(&head, data2);
	
	info data3 = {"YaniB", 1003, 29};
	insertFront(&head, data3);
	
	info data4 = {"YaniC", 1004, 24};
	insertFront(&head, data4);
	
	printList(head);
}
