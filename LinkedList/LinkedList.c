#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node *next;
};

struct Node *head;

int listSize(){
    struct Node *temp = head;
    int counter = 0;
    while(temp != NULL){
        temp = temp->next;
        counter++;
    }
    return counter;
}

void insertBeggining(int x){

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}

void insertEnd(int x){ 

    struct Node *temp = head; 
    struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node));
    temp1->data = x;
    temp1->next = NULL;
    
    while (temp->next != NULL){
        temp = temp->next; 
    }
    
    temp->next = temp1; 
}

void insertNthPosition(int x, int n){
    
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

    if(n==0){
        head = temp->next;
        free(temp);
        return;
    }
    int count = 0;
    while(count < n-1){
        temp = temp->next;
        count++;
    }
    struct Node *temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
        
}

void reverse(){

    int size = listSize();
    if(size == 0){
        return;
    } else{
        struct Node *current, *newNext, *next;
        current = head;
        newNext = NULL;
        
        while(current != NULL){
            
            next = current->next;
            current->next = newNext;
            newNext = current;
            current = next;
        } 
        head = newNext;
    }
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
    
    insertBeggining(3);
    insertNthPosition(2, 1);
    insertNthPosition(4, 2);
    insertNthPosition(7, 1);
    insertNthPosition(7, 10);
    printList();
    deleteElement(2);
    printList();
    listSize();
    reverse();
    printList();

}
