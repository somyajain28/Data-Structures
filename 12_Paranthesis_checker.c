#include<stdio.h>
#include<ctype.h>
#define size 20

typedef struct Stack
{
	int top;
	char a[size];
}stack;

int paran(char a[size]);
void push(stack *s, char v);
void pop(stack *s);
char peek (stack s);

void main()
{
	char a[size];
	printf("Enter the expresion:");
	scanf("%s",a);
	if(paran(a))
		printf("Valid expression");
	else
		printf("Invalid expression");
}

int paran(char a[size])
{
	int i;
	stack s;
	s.top = -1;
	i = 0;
	while(a[i] != '\0')
	{
		if(a[i] == '(' || a[i] == '{' || a[i] == '[' )
			push(&s,a[i]);
			
		else if(a[i] == ')' || a[i] == '}' || a[i] == ']' )
		{
			if(s.top == -1)
				return 0;
				
			else if((a[i] == ')' && peek(s) == '(' ) || 
					(a[i] == '}' && peek(s) == '{' ) || 
					(a[i] == ']' && peek(s) == '[' ))
				pop(&s);
			else
				return 0;
		}
		else if(isalnum(a[i])||a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='^')
		{
			i++;
			continue;
		}
		i++;
	}
	if(s.top == -1)
		return 1;
	return 0;
}

void push(stack *s, char v)
{
	if (s->top==size-1)
	{
		printf("Stack is full\n");
		return;
	}
	s->a[++(s->top)]=v;
}

void pop(stack *s)
{
	char del;
	del=s->a[s->top--];
	return;
}

char peek (stack s)
{
	return s.a[s.top];
}
