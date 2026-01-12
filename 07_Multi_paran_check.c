#include<stdio.h>
#define size 20

typedef struct Stack
{
    int top;
    char arr[size];
}stack;

void push(stack *s,char op);
char pop(stack *s);
int multi_paranthesis_checker(char arr[size]);
int isempty(stack s);
int isfull(stack s);

void main()
{
    char str[size];
    int res;
    printf("Enter the expression : ");
    scanf("%s",str);
    res = multi_paranthesis_checker(str);
    if(res)
        printf("Valid expression\n");
    else
        printf("Invalid expression\n");
}

int multi_paranthesis_checker(char str[size])
{
    char op;
    stack s;
    int i=0;
    s.top=-1;
    while(str[i] != '\0')
    {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
            push(&s,str[i]);
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if(s.top == -1)   // closing bracket without opening
                return 0;

            if((str[i] == ')' && s.arr[s.top] == '(') || (str[i] == '}' && s.arr[s.top] == '{') || (str[i] == ']' && s.arr[s.top] == '['))
                op = pop(&s);
            else
                return 0;  // mismatch found
        }
        i++;
    }
    if(s.top == -1)
        return 1;
    return 0;
}

void push(stack *s, char v)
{
    if(isfull(*s))
    {
        printf("Stack is full");
        return;
    }
    s->arr[++s->top]=v;
}

char pop(stack *s)
{
    char v;
    if(isempty(*s))
    {
        printf("Stack is empty");
        return '\0';
    }    
    v=s->arr[s->top--];
    return v;
}

int isempty(stack s)
{
    return s.top == -1;
}

int isfull(stack s)
{
    return s.top == size - 1;
}