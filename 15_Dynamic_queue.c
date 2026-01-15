#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
}node;

node* create_node(int v);
void disp_list(node* f);
node* enq(node** f,node** r,int v);
node* deq(node** f, node** r);


void main()
{
	node* f = NULL;
	node* r = NULL;
	int v,ch;
	do
	{
		printf("\n*--MENU--*\n");
		printf("\n1.Enqueue\n2.Dequeue\n3.Traverse\n4.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the value:");
				scanf("%d",&v);
				enq(&f,&r,v);
				break;
			case 2:
				deq(&f,&r);
				break;
			case 3:
				disp_list(f);
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

node* enq(node** f,node** r,int v)
{
	node *nn;
	nn = create_node(v);
	if(*r == NULL)
	{
		*f = nn;
		*r = nn;
	}
	else
	{
		(*r)->next = nn;
		*r = nn;
	}
}
node* deq(node** f, node** r)
{
	node *temp =*f;
	int v;
	if(*f == NULL)
	{
		printf("Queue is empty");
		return;
	}
	v = temp->data;
	printf("the dequed element is: %d",v);
	if(*f==*r)
	{
		*f=NULL;
		*r=NULL;
	}
	else
		*f=(*f)->next;
	free(temp);
}

void disp_list(node* f)
{
	node* p;
	if(f == NULL)
	{
		printf("Queue is empty");
		return;
	}
	p = f;
	while(p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
}