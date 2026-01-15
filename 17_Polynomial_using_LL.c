#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Node
{
	int coeff;
	int exp;
	struct Node *next;
}node;

node* create_node(int c,int e);
node* create_poly(node* start);
void disp_poly(node* start);
int compute(node* start);
node* add_poly(node* poly1,node* poly2);

void main()
{
	node* start = NULL,*poly1 = NULL,*poly2 = NULL,*poly3 = NULL;
	int ch,sum;
	do
	{
		printf("\n*--MENU--*\n");
		printf("\n1.Enter the values\n2.Display\n3.Compute\n4.Add\n5.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				start = create_poly(start);
				break;
			case 2:
				disp_poly(start);
				break;
			case 3:
				sum = compute(start);
				printf("\nThe answer is: %d",sum);
				break;
			case 4:
				printf("\nEnter the first polynomial.\n");
				poly1 = create_poly(poly1);
				printf("\nEnter the second polynomial.\n");
				poly2 = create_poly(poly2); 
				poly3 = add_poly(poly1,poly2);
				disp_poly(poly3);
				break;
			case 5:
				exit(0);
			default:
				printf("Invalid Choice");				
		}
	}while(1);
}

node* create_node(int c,int e)
{
	node* nn;
	nn=(node*)malloc(sizeof(node));
	if(nn == NULL)
	{
		printf("ERROR! Memory can not be allocated\n");
		return nn;
	}
	nn->coeff = c;
	nn->exp = e;
	nn->next = NULL;
	return nn;
}

node* create_poly(node* start)
{
	node *nn, *p;
	int c,e,n,i=1;
	printf("Enter the number of terms:");
	scanf("%d",&n);
	while(i<=n)
	{
		printf("\nEnter the coeff and exponent of %d term respectively:",i);
		scanf("%d%d",&c,&e);
		nn = create_node(c,e);
		if(start == NULL)
		{
			start = nn;
			p = start;
		}
		else
		{
			p->next =nn;
			p =nn;
		}
		i++;
	}
	return start;
}

void disp_poly(node *start)
{
	node *p =start;
	if(p ==NULL)
	{
		printf("ERROR");
	}
	while(p)
	{
		if(p->coeff<0 ||p==start)
			printf(" %dx^%d ",p->coeff,p->exp);
		else
			printf("+ %dx^%d ",p->coeff,p->exp);
		p=p->next;
	}
}

int compute(node* start)
{
	node* p = start;
	int x, sum = 0;
	if(p == NULL)
	{
		printf("No equation");
		return -999;
	}
	printf("Enter the value of variable(x):");
	scanf("%d",&x);
	while(p)
	{
		sum += (p->coeff)*pow(x,p->exp);
		p = p->next;
	}
	return sum;
}

node* add_poly(node* poly1,node* poly2)
{
	int c,e;
	node *nn,*p1 = poly1,*p2 = poly2,*p3 = NULL,*poly3 = NULL;
	while(p1 && p2)
	{
		if(p1->exp == p2->exp)
		{
			c = p1->coeff + p2->coeff;
			e = p1->exp;
			p1 = p1->next;
			p2 = p2->next;
		}
		else if(p1->exp > p2->exp)
		{
			c = p1->coeff;
			e = p1->exp;
			p1 = p1->next;
		}
		else
		{
			c = p2->coeff;
			e = p2->exp;
			p2 = p2->next;
		}
		nn = create_node(c,e);
		if(poly3 == NULL)
		{
			poly3 = nn;
			p3 =poly3;
		}
		else
		{
			p3->next = nn;
			p3 = nn;
		}
	}
	while(p1)
	{
		nn = create_node(p1->coeff,p1->exp);
		p3->next = nn;
		p3 = nn;
		p1 = p1->next;
	}
	while(p2)
	{
		nn = create_node(p2->coeff,p2->exp);
		p3->next = nn;
		p3 = nn;
		p2 = p2->next;
	}
	return poly3;
}