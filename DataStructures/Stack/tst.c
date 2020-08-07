#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* top = NULL;

void push(int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}
int pop()
{
    int data;
    struct node* temp = top;
    if(top == NULL)
    {
        return -1;
    }
    temp = top;
    data = top->data;
    top = top->next;
    free(temp);
    return data;
}
bool isoperator(char x)
{
    if(x=='+'||x=='-'||x==''||x=='/')
    return true;
    return false;
}
bool isnumericdigit(char x)
{
    if(x>='0'&&x<='9')
    return true;
    return false;
}
int preop(char x,int operand1,int operand2)
{
    if(x=='+'){
        return operand1+operand2;
    }else if(x=='-'){
        return operand1-operand2;
    }else if(x==''){
        return operand1operand2;
    }else if(x=='/'){
        return operand1/operand2;
    }else{
        printf("invalid operator\n");
        return -1;
    }
}
int evalpostfix(char arr,int len)
{
    int i;
    for(i=0;i<len;i++)
    {
    if((arr+i)==' '||(arr+i)==','){
        continue;
    }else if(isnumericdigit((arr+i)))
    {
        int operand = 0;
        while(i<len && isnumericdigit((arr+i)))
        {
            operand = ((arr+i)-'0');
            i++;
        }
        i--;
        push(operand);
    }
    else if(isoperator((arr+i)))
    {
        int res;
        int operand2 = pop();
        int operand1 = pop();
        res = preop(*(arr+i),operand1,operand2);
        push(res);
    }

    return top->data;
}

int main()
{
    char arr[20];
    int res,length;
    printf("enter the postfix expression: ");
    gets(arr);
    puts(arr);
    length = strlen(arr);
    printf("%d\n",length);
    res = evalpostfix(arr,length);
    printf("result = %d",res);
    return 0;
}