#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
}node;

node* create_node(int v);
node* sorted_list(node* start);
node* delete_list(node* start);
void disp_list(node* start);

void main()
{
	node* start = NULL;
	int ch;
	do
	{
		printf("\n*--MENU--*\n");
		printf("\n1.Insertion\n2.Deletion\n3.Traversing\n4.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				start = sorted_list(start);
				break;
			case 2:
				start = delete_list(start);
				break;
			case 3:
				disp_list(start);
				break;
			case 4:
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

node* sorted_list(node* start)
{
	int v;
	char ch;
	node *nn, *p;
	do
	{
		printf("Enter the value:");
		scanf("%d",&v);
		nn = create_node(v);
		if(start == NULL)
			start = nn;
		else if(start->data > nn->data)
		{
			nn->next = start;
			start = nn;
		}
		else
		{
			p = start;
			while(p->next && p->next->data <= nn->data)
				p =p->next;
			
			nn->next = p->next;
			p->next = nn;
		}
		printf("Do you want to add more (y/n):");
		fflush(stdin);
		scanf("%c",&ch);
	}while(ch == 'y' || ch == 'Y');
	return start;
}

node* delete_list(node* start)
{
	node *temp,*p;
	int v;
	if(start == NULL)
	{
		printf("List is empty\n");
		return start;
	}
	printf("Enter the value to delete:");
	scanf("%d",&v);
	if(start->data == v)
	{
		temp = start;
		start = start->next;
		free(temp);
	}
	else
	{
		p = start;
		while(p->next && p->next->data != v)
			p = p->next;
		if(p->next != NULL)
		{
			temp = p->next;
			p->next = p->next->next;
			free(temp);
		}
		else
			printf("value not in the list\n");
	}
	return start;
}

void disp_list(node* start)
{
	node* p;
	if(start == NULL)
	{
		printf("List is empty");
		return;
	}
	p =start;
	while(p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
}
