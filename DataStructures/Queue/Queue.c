#include <stdio.h>
#include <stdlib.h>

#define MAX 101

int array[MAX];
int *aux = array;
int front = -1;
int rear = -1;

int first(){
    printf("Front: %d", aux[front]);
}

int isEmpty(){
    return (front == -1 && rear == -1);
}

void isFull(){

    if(rear == MAX-1){
        printf("Queue is full");
    }

}

int enqueue(int x){

    isFull();
    
    if(isEmpty()){
        front = 0;
        rear = 0;
    } else{
        rear = (rear + 1) % MAX; // circular array to fill empty space
    }
    aux[rear] = x;
}

void dequeue(){
    if(isEmpty()){
        return;
    } else if(front == rear){
        front = -1;
        rear = -1;
    } else{
        front = (front + 1) % MAX;
    }
}

int main(){

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(10);
    enqueue(11);
    enqueue(12);
    enqueue(13);
    enqueue(14);
    first();
    dequeue();
    first();
}