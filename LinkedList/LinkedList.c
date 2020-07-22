#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head;


void insertElementBeggining(int x){
    
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}

struct Node insertElementEnd(int x){
    
    struct Node *temp = head;
    struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node));
    temp1->data = x;
    temp1->next = NULL;
    
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = temp1;
    return struct Node head;
}

void deleteElement(){

}

void insertElementEnd(){

}

void printList(){
    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
}

int main(){
    head = NULL;

}