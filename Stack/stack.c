#include <stdio.h>
#include <stdlib.h>

int array[100];

int top = -1; // empty stack 

void push(int x){
    if(top == 100){
        printf("Stack is full");
        return; // implement stackoverflow handle
    }
    top++;
    array[top] = x;

}

void isEmpty(){
    if(top == -1){
        printf("Stack is empty");
        return;
    }
}

void topStack(){
    isEmpty();
    printf("Top item in stack: %d", array[top]);
}

void pop(){
    isEmpty();
    top--;
}

void print() { // FOR TESTING PURPOSE
	int i;
	printf("Stack: ");
	for(i = 0; i <= top; i++){
		printf("[%d] ", array[i]);
    }
}

int main(){

    push(10);
    push(5);
    print();
    pop();
    topStack();
    pop();

}