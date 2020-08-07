#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 10

int top = -1;
char stack[size];

void push(char x){
    top++;
    stack[top] = x; 
}

void pop(){
    top--;
}

void checkBalance(char *exp){
    for(int i = 0; i < strlen(exp); i++){
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{') {
            push(exp[i]);
        }else if(exp[i]== ')'){
            if(stack[top]== '('){
                pop();
            } else{
                continue;
            }
        } else if(exp[i]== ']'){
            if(stack[top]== '['){
                pop();
            } else{
                continue;
            }
        } else if(exp[i]== '}'){
            if(stack[top]== '{'){
                pop();
            } else{
                continue;
            }
        }
    }
}

int main(){

    char exp[20];
    printf("Enter expression: \n");
    scanf("%s", exp);
    checkBalance(exp);

    if(top == -1){
        printf("Valid expression.");
    }else{
        printf("Invalid expression.");
        return 0;
    }
}