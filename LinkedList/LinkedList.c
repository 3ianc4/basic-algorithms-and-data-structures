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

void insertElementEnd(int x){ 

    struct Node *temp = head; 
    struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node));
    temp1->data = x;
    temp1->next = NULL;
    
    while (temp->next != NULL){
        temp = temp->next; 
    }
    
    temp->next = temp1; 
}

void InsertNthPosition(int x, int n){
    
    struct Node *temp1 = head; 
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    int count = 0; 
    while(count < n-1){
        temp1 = temp1->next;
        count++;
    }
    
    temp->next = temp1->next;
    temp1->next = temp;
}

void deleteElement(int n){
    
    struct Node *temp = head;
    int count = 0;
    while(count < n-1){
        temp = temp->next;
    }
    temp->next = temp->next->next;
        
}

void printList(){
    
    struct Node *temp = head;
    printf("List: ");
    
    while (temp != NULL) {
        printf("[%d]", temp->data);
        temp = temp->next;
    }
}

int main(){
    
    head = NULL;
    
    insertElementBeggining(3);
    InsertNthPosition(2, 1);
    insertElementEnd(4);
    InsertNthPosition(7, 1);
    printList();
    deleteElement(2);
    printList();

}