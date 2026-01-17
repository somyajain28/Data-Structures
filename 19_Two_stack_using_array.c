#include<stdio.h>
#define size 20

typedef struct STACK
{
	int arr[size];
	int top1, top2;
}stack;

int isfull(stack s);
int isempty(stack s, int id);
void push(stack *s,int id, int v);
int pop(stack *s,int id);
void peek(stack s,int id);
void display(stack s,int id);

void main()
{
	stack s;
	s.top1 = -1;
	s.top2 = size;
	int ch,v,id;
	do
	{
		printf("\n**MENU**");
		printf("\n1.Push\n2.Pop\n3.Peek\n4.Traverse\n5.Exit\n");
		printf("Select the operation you want to perform\n");
		scanf("%d",&ch);
		switch(ch)
		{
			
			case 1:
				printf("Enter the stack id:");
				scanf("%d",&id);
				printf("Enter the element you want to push\n");
				scanf("%d",&v);
				push(&s,id,v);
				break;
			case 2:
				printf("Enter the stack id:");
				scanf("%d",&id);
				v = pop(&s,id);
				printf("the popped element is: %d",v);
				break;
			case 3:
				printf("Enter the stack id:");
				scanf("%d",&id);
				peek(s,id);
				break;
			case 4:
				printf("Enter the stack id:");
				scanf("%d",&id);
				display(s,id);
				break;
			case 5:
				exit(0);
			default:
				printf("\nInvalid Choice\n");
		}
	}while(1);
}

int isfull(stack s)
{
	return (s.top1 == (s.top2)-1);
}
int isempty(stack s, int id)
{
	if(id == 1 && s.top1 == -1)
		return 1;
	else if(id == 2 && s.top2 == size)
		return 1;
	return 0;
}
void push(stack *s,int id, int v)
{
	if(isfull(*s))
		printf("Stack is full");
	else if(id == 1)
		s->arr[++(s->top1)] = v;
	else if(id == 2)
		s->arr[--(s->top2)] = v;
	else
		printf("Invalid id");
}
int pop(stack *s,int id)
{
	int v = -999;
	if(isempty(*s,id))
		printf("Stack is empty");
	else if(id == 1)
		v = s->arr[(s->top1)--];
	else if(id == 2)
		v = s->arr[(s->top2)++];
	else
		printf("Invalid id");
	return v;
}
void peek(stack s,int id)
{
	if(isempty(s,id))
		printf("Stack is empty");
	else if(id == 1)
		printf("Top element is %d\t",s.arr[s.top1]);
	else if(id == 2)
		printf("Top element is %d\t",s.arr[s.top2]);
}
	
void display(stack s,int id)
{
	int i;
	if(isempty(s,id))
		printf("Stack is empty");
	else if(id == 1)
	{
		printf("Stack elements are :\n");
		for (i=s.top1;i>=0;i--)
			printf("%d ",s.arr[i]);
	}
	else if(id == 2)
	{
		printf("Stack elements are :\n");
		for (i=s.top2;i<size;i++)
			printf("%d ",s.arr[i]);
	}
}