#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int array[MAX];
int *nArray = array;

int top = -1; // empty stack

int stackIsFull(){

    if(top == sizeof(nArray)){
        int newArray[MAX * 2];
        for(int i = 0; i < sizeof(nArray); i++){
            newArray[i] = array[i];
        }
        nArray = newArray;
    }
}

void push(int x){
    
    stackIsFull();
    top++;
    nArray[top] = x;

}

void isEmpty(){
    if(top == -1){
        printf("Stack is empty");
        return;
    }
}

void topStack(){
    isEmpty();
    printf("Top item in stack: %d", nArray[top]);
}

void pop(){
    isEmpty();
    top--;
}

void print() { // FOR TESTING PURPOSE
	int i;
	printf("Stack: ");
	for(i = 0; i <= top; i++){
		printf("[%d] ", nArray[i]);
    }
}

int main(){

    push(10);
    push(5);
    push(20);
    push(21);
    print();
    pop();
    topStack();
}