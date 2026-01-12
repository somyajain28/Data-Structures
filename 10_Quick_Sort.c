#include<stdio.h>
#define size 5

int partition (int a[size], int l, int h);
void quicksort(int a[size], int l, int h);

void main()
{
	int i,a[size];
	printf("Enter array elements: ");
	for(i=0;i<size;i++)
		scanf("%d",&a[i]);
	quicksort(a,0,size-1);
	printf("Sorted array is:");
	for(i=0;i<size;i++)
		printf("%d ",a[i]);
}

int partition(int a[size], int l, int h)
{
	int i,j,p,temp;
	i=l+1;
	j=h;
	p=a[l];
	while(i<=j)
	{
		while(i <= h && a[i] <= p)
			i++;
		while(a[j] > p)
			j--;
		if(i<j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	if(l != j)
	{
		temp = a[l];
		a[l] = a[j];
		a[j] = temp;
	}
	return j;
}

void quicksort(int a[size],int l, int h)
{
	int p;
	if(l<h)
	{
		p = partition(a,l,h);
		quicksort(a,l,p-1);
		quicksort(a,p+1,h);
	}
}
