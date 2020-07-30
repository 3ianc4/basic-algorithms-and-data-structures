#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL; // empty stack

void isEmpty(){
    if(head == NULL){
        printf("Stack is empty");
        return;
    }
}

void push(int x){
    
    isEmpty();

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}

void topStack(){
    isEmpty();
    printf("Top item in stack: %d", head->data);
}

void pop(){
    isEmpty();
    head = head->next;
}

void print() { // FOR TESTING PURPOSE

    struct Node* temp = head;
	printf("Stack: ");
	while(temp != NULL){
		printf("[%d] ", temp->data);
        temp = temp->next;
    }
}

int main(){

    push(10);
    push(5);
    push(20);
    push(21);
    pop();
    print();
    topStack();
}