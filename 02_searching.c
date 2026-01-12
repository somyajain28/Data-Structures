#include<stdio.h>
#include<stdlib.h>

int linear(int a[10], int, int);
int binary(int a[10],int,int);
void sort(int a[10],int);

void main()
{
	int a[10],n,k,i,ch,p;
	printf("Enter no of elements of array:");
	scanf("%d",&n);
	printf("\nEnter array elements");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);	
	do
	{
		printf("\n**--MENU--**\n");
		printf("1.Linear Search\n2.Binary search\n3.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter element you want to search:");
				scanf("%d",&k);
				p=linear(a,n,k);
				if(p==-1)
					printf("Value not found\n");
				else
					printf("Value found at index:%d\n",p);
				break;
			case 2:
				printf("\nEnter element you want to search:");
				scanf("%d",&k);
				p=binary(a,n,k);
				if(p==-1)
					printf("Value not found\n");
				else
					printf("Value found\n",p);
				break;
			case 3:
				exit(0);
			default:
				printf("Invalid Choice");
		}//switch
	}while(1);//dowhile		
}//main

int linear(int a[10], int n, int k)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==k)
			return i;
	}
	return -1;
}//linear

int binary(int a[10], int n, int k)
{
	sort(a,n);
	int mid,l,u;
	l=0;
	u=n-1;
	while(l<=u)
	{
		mid=(l+u)/2;
		if(a[mid]>k)
			u=mid-1;
		else if(a[mid]==k)
			return mid;
		else
			l=mid+1;
	}
	return -1;
}//binary

void sort(int a[10],int n)
{
	int i,j,min,t;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
				min=j;
		}//j
		if(min!=i)
		{
			t=a[i];
			a[i]=a[min];
			a[min]=t;
		}
	}//i
}//sort