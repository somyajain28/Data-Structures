#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int inserting(int a[SIZE],int,int,int);
int deleting(int a[SIZE],int,int *n);
void traverse(int a[SIZE],int);

void main()
{
	int a[SIZE],n,ch,i,k,pos;
	printf("enter no of elements in the array:");
	scanf("%d",&n);
	printf("\nEnter elements of array:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	do
	{
		printf("\n*--MENU--*\n");
		printf("1.Inserting an element\n");
		printf("2.Deleting an element\n");
		printf("3.To traverse the array\n");
		printf("4.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the element to insert:");
				scanf("%d",&k);
				printf("\nEnter the position of insertion:");
				scanf("%d",&pos);
				n=inserting(a,k,pos,n);
				break;
			case 2:
				printf("\nEnter the position :");
				scanf("%d",&pos);
				k=deleting(a,pos,&n);
				printf("\nThe deleted element is:%d\n",k);
				break;
			case 3:
				traverse(a,n);
				break;
			case 4:
				exit(0);
			default:
				printf("\nInvalid choice\n");
		}
	}while(1);	
}

int inserting(int a[SIZE],int k,int pos,int n)
{
	int i;
	if(pos>=SIZE||n==SIZE)
	{
		printf("\nError\n");
		return n;
	}
	for(i=n-1;i>=pos;i--)
	{
		a[i+1]=a[i];
	}
	a[pos]=k;
	n++;
	return n;
} 

int deleting(int a[SIZE],int pos,int *n)
{
	int i,k=-999;
	if((*n)==0)
	{
		printf("\nArray is empty\n");
		return k;
	}
	k=a[pos];
	for(i=pos;i<(*n)-1;i++)
	{
		a[i]=a[i+1];
	}
	(*n)--;
	return k;
}

void traverse(int a[SIZE],int n)
{
	int i;
	if(n==0)
		printf("\nThe array is empty\n");
	else
	{
		printf("\nThe array is:\n");
		for(i=0;i<n;i++)
			printf("%d\t",a[i]);
	}
}