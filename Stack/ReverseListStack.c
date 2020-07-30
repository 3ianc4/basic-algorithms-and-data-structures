#include <stdio.h>
#include <string.h>

#define MAX 50

char string[MAX];
int top = -1;

void push(char s){
    top++;
    string[top] = s;

}

void pop(){
    top--;
}

void print(){
    printf("%c", string[top]);
}

int main(){
    printf("Enter string: ");
    scanf("%s", string);

    int n = strlen(string);
    for(int i = 0; i < n; i++){
        push(string[i]);
    }

    for(int i = 0; i < n; i++){
        print();
        pop();
    }
    printf("\n");
    return 0;
}