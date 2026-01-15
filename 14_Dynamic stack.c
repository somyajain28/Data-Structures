#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
}node;

node* create_node(int v);
void disp_list(node* top);
node* push(node* top,int v);
node* pop(node* top);
void peek(node* top);


void main()
{
	node* top = NULL;
	int v,ch;
	do
	{
		printf("\n*--MENU--*\n");
		printf("\n1.Push\n2.Pop\n3.Peek\n4.Traverse\n5.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the value:");
				scanf("%d",&v);
				top = push(top,v);
				break;
			case 2:
				top = pop(top);
				break;
			case 3:
				peek(top);
				break;
			case 4:
				disp_list(top);
				break;
			case 5:
				exit(0);
			default:
				printf("Invalid Choice");				
		}
	}while(1);
}

node* create_node(int v)
{
	node* nn;
	nn=(node*)malloc(sizeof(node));
	if(nn == NULL)
	{
		printf("ERROR! Memory can not be allocated\n");
		return nn;
	}
	nn->data = v;
	nn->next = NULL;
	return nn;
}

node* push(node* top, int v)
{
	node *nn;
	nn = create_node(v);
	if(top == NULL)
		top = nn;
	else
	{
		nn->next = top;
		top = nn;
	}
	return top;
}

node* pop(node* top)
{
	int v;
	node* temp;
	if(top == NULL)
	{
		printf("Stack is empty");
		return top;
	}
	temp = top;
	top = top->next;
	v = temp->data;
	free(temp);
	printf("Popped element: %d",v);
	return top;
}

void peek(node* top)
{
	if(top == NULL)
	{
		printf("Stack is empty");
		return;
	}
	printf("Top element is: %d",top->data);
}

void disp_list(node* top)
{
	node* p;
	if(top == NULL)
	{
		printf("Stack is empty");
		return;
	}
	p = top;
	while(p != NULL)
	{
		printf("%d\n",p->data);
		p = p->next;
	}
}

