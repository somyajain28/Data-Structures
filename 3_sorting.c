#include<stdio.h>
#include<stdlib.h>

int selection(int a[10],int);
int bubble(int a[10],int);
int insertion(int a[10],int);

void main()
{
	int a[10],i,n,ch,t;
	do
	{
		printf("\n**--MENU--**\n");
		printf("1.Selection sort\n2.Bubble sort\n3.Insertion sort\n4.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter number of elements in array:");
				scanf("%d",&n);
				printf("\nEnter array elements:");
				for(i=0;i<n;i++)
					scanf("%d",&a[i]);
				t=selection(a,n);
				printf("Passes:%d\n",t);
				printf("Sorted array is:\n");
				for(i=0;i<n;i++)
					printf("%d\t",a[i]);
				break;
			case 2:
				printf("Enter number of elements in array:");
				scanf("%d",&n);
				printf("\nEnter array elements:");
				for(i=0;i<n;i++)
					scanf("%d",&a[i]);
				t=bubble(a,n);
				printf("Passes:%d\n",t);
				printf("Sorted array is:\n");
				for(i=0;i<n;i++)
					printf("%d\t",a[i]);
				break;
			case 3:
				printf("Enter number of elements in array:");
				scanf("%d",&n);
				printf("\nEnter array elements:");
				for(i=0;i<n;i++)
					scanf("%d",&a[i]);
				t=insertion(a,n);
				printf("Passes:%d\n",t);
				printf("Sorted array is:\n");
				for(i=0;i<n;i++)
					printf("%d\t",a[i]);
				break;
			case 4:
				exit(0);
			default:
				printf("Invalid Choice");
		}
	}while(1);
}

int selection(int a[10],int n)
{
	int i,j,min,t;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
				min=j;
		}
		if(min!=i)
		{
			t=a[i];
			a[i]=a[min];
			a[min]=t;
		}
	}
	return i;
}

int bubble(int a[10],int n)
{
	int i,j,f,t;
	for(i=0;i<n-1;i++)
	{
		f=0;
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				f=1;
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
		if(f==0)
			return i+1;
	}
	return i;
}

int insertion(int a[10],int n)
{
	int i,j,t;
	for(i=1;i<n;i++)
	{
		t=a[i];
		for(j=i-1;j>=0&&t<a[j];j--)
			a[j+1]=a[j];
		a[j+1]=t;
	}
	return i;
}