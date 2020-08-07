#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top = -1;
int stack[50];

void push(int *x){
    top++;
    //int y = x + 1;
    //printf("O Y: %d", y);
    stack[top] = *x;
}

int pop(){
    int result = stack[top];
    printf("tp = %d\n", stack[top]);
    top --;
    return result;

}

int main(){
    printf("Enter expression: \n");
    char expr[10];
    scanf("%s", expr);
    int i = 0;
    while(i < strlen(expr)){
        if(expr[i] >= '0' && expr[i] <= '9'){
            int aux = atoi(&expr[i]);
            printf("aux = %d\n", aux);
            printf("EXPR 1 %c\n", expr[i]);
            push(&aux);
            printf("Atual = %c\n", expr[i]);
            printf("top stack: %d\n", stack[top]);
        } else{
            printf("Atual do else = %s\n", &expr[i]);
            int operand1 = pop();
            printf("operand 1 = %d", operand1);
            int operand2 = pop();
            printf("operand 2 = %d", operand2);
            int result;
            
            if(expr[i] == '+'){
                result = operand1 + operand2;
            } else if(expr[i] == '-'){
                result = operand1 - operand2;
            } else if(expr[i] == '*'){
                result = operand1 * operand2;
            } else if(expr[i] == '/'){
                result = operand1 / operand2;
            }
            printf("Result = %d", result);
        }
        i++;
    }

}