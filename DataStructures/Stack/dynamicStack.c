#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL; // empty stack

void IsEmpty(){

    if(head == NULL){
        printf("Stack is empty.");
        return;
    }
}

void Push(int x){

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}

void TopOfStack(){
    IsEmpty();
    printf("\nTop item in stack: %d\n", head->data);
}

void Pop(){
    IsEmpty();
    struct Node *temp = head;
    head = temp->next;
    free(temp);
}

void Print() { // FOR TESTING PURPOSE

    struct Node* temp = head;
	printf("Stack: ");
	while(temp != NULL){
		printf("[%d] ", temp->data);
        temp = temp->next;
    }
}

int main(){

    Push(10);
    Push(5);
    Push(20);
    Push(21);
    Pop();
    Print();
    TopOfStack();
}