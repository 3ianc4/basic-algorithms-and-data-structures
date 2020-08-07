#include <stdio.h>
#include <stdlib.h>

#define max 100

int array[max];
int *nArray = array;

int top = -1; // empty stack

int FullStack(){

    if(top == sizeof(nArray)){
        int mArray[max * 2];
        for(int i = 0; i < sizeof(nArray); i++){
            mArray[i] = array[i];
        }
        nArray = mArray;
    }
}

void Push(int x){
    
    FullStack();
    top++;
    nArray[top] = x;

}

void IsEmpty(){
    if(top == -1){
        printf("\nStack is empty.");
        return;
    }
}

void TopOfStack(){
    IsEmpty();
    printf("\nTop item in stack: %d", nArray[top]);
}

void Pop(){
    IsEmpty();
    top--;
}

void Print() { // FOR TESTING PURPOSE
	int i;
	printf("\nStack: ");
	for(i = 0; i <= top; i++){
		printf("[%d] ", nArray[i]);
    }
}

int main(){

    Push(10);
    Push(5);
    Push(20);
    Push(21);
    Print();
    Pop();
    Print();
    TopOfStack();
}