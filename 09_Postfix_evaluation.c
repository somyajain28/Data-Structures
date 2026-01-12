#include<stdio.h>
#include<ctype.h>
#define size 20

typedef struct Stack
{
	int top;
	char arr[size];
}stack;

void intopost(char infix[size],char postfix[size]);
int precedence(char);
void push(stack *s, char v);
char pop(stack *s);
char peek(stack);
int isempty(stack s);
int isfull(stack s);

void main()
{
	char infix[size], postfix[size];
	printf("Enter a valid infix expression:");
	scanf("%s",infix);
	intopost(infix,postfix);
	printf("The converted postfix expression is: %s", postfix);
}

void intopost(char infix[size], char postfix[size])
{
	char opt;
	int i, j;
	i = 0;
	j = 0;
	stack s;
	s.top = -1;
	while(infix[i] != '\0')
	{
		if(isalnum(infix[i]))
			postfix[j++] = infix[i];
			
		else if(infix[i] == '(' || isempty(s))
			push(&s, infix[i]);
		
		else if(infix[i] == ')')
		{
			while(peek(s) != '(')
			{
				postfix[j++] = pop(&s);
			}
			opt = pop(&s);
		}
		
		else
		{
			while(!isempty(s) && (precedence(infix[i]) <= precedence(peek(s))))
				postfix[j++] = pop(&s);
			push(&s, infix[i]);
		}
		i++;
	}
	while(!isempty(s))
		postfix[j++] = pop(&s);
	postfix[j] = '\0';
}

int precedence(char ch)
{
	switch(ch)
	{
		case '^':
			return 3;
		case '*':
		case '/':
		case '%':
			return 2;
		case '+':
		case '-':
			return 1;
		case '(':
			return 0;
	}
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

char peek(stack s)
{
    if(isempty(s))
    {
        printf("Stack is empty");
        return;
    }
    return s.arr[s.top];
}

int isempty(stack s)
{
    return s.top == -1;
}

int isfull(stack s)
{
    return s.top == size - 1;
}
