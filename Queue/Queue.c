#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int array[MAX];
int *aux = array;
int front = -1;
int rear = -1;

int first(){
    printf("%d", array[front]);
}

int isEmpty(){
    (front == -1 && rear == -1);
}

void isFull(){

    if(rear == sizeof(aux)){
    
        int newArray[MAX * 2];
        for(int i = 0; i < MAX; i++){
            newArray[i] = aux[i];
        }
        aux = newArray;
    }

}

int enqueue(int x){

    isFull();
    if(isEmpty()){
        front++;
        rear++;
        array[rear] = x;
    } else{
        rear++;
        array[rear] = x;
    }
}

void dequeue(){
    if(isEmpty()){
        return;
    } else if(front == rear){
        front = -1;
        rear = -1;
    } else{
        front++;
    }
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