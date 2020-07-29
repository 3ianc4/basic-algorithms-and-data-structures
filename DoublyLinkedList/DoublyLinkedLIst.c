#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *previous;
    struct Node *next;
};

struct Node *head;

void insertHead(int x){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->previous = NULL;
    temp->next = NULL;

    if(head == NULL){
        head = temp;
        return;
    }

    head->previous = temp;
    temp->next = head;
    head = temp;
}

void insertTail(int x){

    struct Node *temp1 = head;
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->previous = NULL;
    temp->next = NULL;

    if(head == NULL){
        head = temp;
        return;
    }

    while(temp1->next != NULL){
        temp1 = temp1->next;
    }

    temp1->next = temp;
    temp->previous = temp1;
}

void printList(){

    struct Node *temp = head;
    printf("List: ");

    while(temp != NULL){
        printf("[%d] ", temp->data);
        temp = temp->next;
    }

}

void printReverse(){

    struct Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    printf("Reversed list: ");
    while(temp != NULL){
        printf("[%d] ", temp->data);
        temp = temp->previous;
    }
}

void delete(int x){

    if(head->data == x){
        head = head->next;
        head->previous = NULL;
        return;
    }

    struct Node *temp = head;
    
    while(temp->data != x){
        temp = temp->next;
    }
    if(temp->next != NULL){
        temp->previous->next = temp->next;
        temp->next->previous = temp->previous;
    } else{
        temp->previous->next = NULL;
    }
        
        free(temp);
}

int main(){

    head = NULL;
    insertHead(10);
    insertHead(15);
    printList();
    insertTail(20);
    insertTail(30);
    insertTail(40);
    printList();
    delete(20);
    printList();
    printReverse();

}