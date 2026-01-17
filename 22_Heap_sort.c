#include<stdio.h>
#include<stdlib.h>
#define size 10

void heapify(int arr[],int n, int i);
void heapsort(int arr[],int n);

void main()
{
	int i,ch,arr[size],n;
	printf("Enter no of elements:");
	scanf("%d",&n);
	for(i = 0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Array is:");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	heapsort(arr,n);
	printf("\nSorted array is:");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
}

void heapify(int arr[],int n, int i)
{
	int temp;
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	if(l < n && arr[l] > arr[largest])
		largest = l;
	if(r < n && arr[r] > arr[largest])
		largest = r;
	if(largest != i)
	{
		temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		heapify(arr,n,largest);
	}	
}

void heapsort(int arr[],int n)
{
	int temp ,i;
	for(i=n/2-1;i>=0;i--)
		heapify(arr,n,i);
	for(i=n-1;i>0;i--)
	{
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapify(arr,i,0);
	}
}
