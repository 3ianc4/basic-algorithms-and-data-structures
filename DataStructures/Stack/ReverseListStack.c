#include <stdio.h>
#include <string.h>

#define max 50

char string[max];
int top = -1;

void Push(char s){
    top++;
    string[top] = s;

}

void Pop(){
    top--;
}

void Print(){

    printf("Reversed string: ");
    int n = strlen(string);

    for(int i = 0; i < n; i++){
        printf("%c", string[top]);
        Pop();
    }

    printf("\n");
}

int main(){
    printf("Enter string: ");
    scanf("%s", string);

    int n = strlen(string);
    
    for(int i = 0; i < n; i++){
        Push(string[i]);
    }

    Print();

    return 0;
}