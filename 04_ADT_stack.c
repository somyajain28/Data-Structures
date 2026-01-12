#include <stdio.h>
#include<stdlib.h>
#define size 5

typedef struct Stack
{
    int top;
    int arr[size];
}stack;

void push(stack *s, int v);
int pop(stack *s);
void peek(stack);
void display(stack s);
int isempty(stack s);
int isfull(stack s);

void main()
{
    int ch,v;
    stack s;
    s.top = -1;

    do
    {
        printf("\n*--MENU--*\n");
        printf("1.push\n2.pop\n3.peek\n4.traverse\n5.exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter the value to push:");
                scanf("%d",&v);
                push(&s,v);
                break;
            case 2:
                v=pop(&s);
                printf("The deleted element is: %d",v);
                break;
            case 3:
                peek(s);
                break;
            case 4:
                display(s);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    } while (1);    
}

void push(stack *s, int v)
{
    if(isfull(*s))
    {
        printf("Stack is full");
        return;
    }
    s->arr[++s->top]=v;
}

int pop(stack *s)
{
    int v;
    if(isempty(*s))
    {
        printf("Stack is empty");
        return -999;
    }    
    v=s->arr[s->top--];
    return v;
}

void peek(stack s)
{
    if(isempty(s))
    {
        printf("Stack is empty");
        return;
    }
    printf("The top element is %d",s.arr[s.top]);
}

void display(stack s)
{
    int i;
    if(isempty(s))
    {
        printf("Stack is empty");
        return;
    }
    printf("Stack elements are:\n");
    for(i=s.top; i>=0; i--)
        printf("%d\n", s.arr[i]);
}

int isempty(stack s)
{
    return s.top == -1;
}

int isfull(stack s)
{
    return s.top == size - 1;
}
