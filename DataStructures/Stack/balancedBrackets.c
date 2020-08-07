#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 10

int top = -1;
char stack[size];

void Push(char x){
    top++;
    stack[top] = x; 
}

void pop(){
    top--;
}

void CheckBalance(char *expression){

    for(int i = 0; i < strlen(expression); i++){

        if( expression[i]=='(' || 
            expression[i]=='[' || 
            expression[i]=='{') 
            {
            
            Push(expression[i]);

        }else if(expression[i]== ')'){

            if(stack[top]== '('){
                pop();
            } else{
                top--;
            }

        } else if(expression[i]== ']'){

            if(stack[top]== '['){
                pop();
            }else{
                top--;
            }

        } else if(expression[i]== '}'){
            
            if(stack[top]== '{'){
                pop();
            }else{
                top--;
            }
        }
    }
}

int main(){

    char expression[20];
    printf("Enter expression: \n");
    scanf("%s", expression);
    CheckBalance(expression);

    if(top == -1){
        printf("Valid expression.");
    } else {
        printf("Invalid expression.");
        return 0;
    }
}