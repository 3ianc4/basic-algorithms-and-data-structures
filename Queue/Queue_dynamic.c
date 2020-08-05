#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

int first(){
    printf("Front = %d\n", front->data);
}

int isEmpty(){
    return (front == NULL);
}

void enqueue(int x){

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = x;
    temp->next = NULL;

    if(front == NULL & rear == NULL){
        front = temp;
        rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;

}

void dequeue(){

    struct Node* temp = front;
    if(isEmpty()){
        return;
    } else if(front == rear){
        front = NULL;
        rear = NULL;
    } else{
        front = front->next;
    }
    free(temp);
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    first();
    dequeue();
    first();
}