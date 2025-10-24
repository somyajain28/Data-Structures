#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define size 20

typedef struct Stack
{
    char arr[size];
    int top;
} stack;

void push(stack *s, char c);
char pop(stack *s);
char peek(stack s);
int isempty(stack s);
int precedence(char op);
int isRightAssociative(char op);
void infixToPostfix(char *infix, char *postfix);

void main() 
{
    char infix[size], postfix[size];
    printf("Enter infix: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
}

void push(stack *s, char c)
{
    s->arr[++s->top] = c;
}

char pop(stack *s)
{
    return s->arr[s->top--];
}

char peek(stack s)
{
    return s.arr[s.top];
}

int isempty(stack s)
{
    return (s.top == -1);
}

int precedence(char op)
{
    switch (op)
    {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

int isRightAssociative(char op)
{
    return op == '^'; // only ^ is right associative
}

void infixToPostfix(char *infix, char *postfix)
{
    stack s;
    s.top = -1;
    int i, k = 0;

    for (i = 0; infix[i] != '\0'; i++)
    {
        char c = infix[i];

        if (isalnum(c)) // operand
        {
            postfix[k++] = c;
        }
        else if (c == '(')
        {
            push(&s, c);
        }
        else if (c == ')')
        {
            while (!isempty(s) && peek(s) != '(')
            {
                postfix[k++] = pop(&s);
            }
            pop(&s); // remove '('
        }
        else // operator
        {
            while (!isempty(s) && precedence(peek(s)) > 0)
            {
                if ((isRightAssociative(c) && precedence(c) < precedence(peek(s))) ||
                    (!isRightAssociative(c) && precedence(c) <= precedence(peek(s))))
                {
                    postfix[k++] = pop(&s);
                }
                else
                    break;
            }
            push(&s, c);
        }
    }

    while (!isempty(s))
    {
        postfix[k++] = pop(&s);
    }

    postfix[k] = '\0';
}