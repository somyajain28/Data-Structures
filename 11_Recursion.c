#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 20

long fact(int n);
int sum (int n);
void rev(char str[size], int l);
int fibn(int n);
void toh(int n,char from, char to, char aux);

void main()
{
	int n,ch,s,l,i;
	char str[size];
	do
	{
		printf("\n*--MENU--*\n");
		printf("1.Factorial\n");
		printf("2.Sum of n numbers\n");
		printf("3.Reverse a string\n");
		printf("4.Fibonacci term\n");
		printf("5.Tower of Hanoi\n");
		printf("6.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter a number:");
				scanf("%ld",&n);
				printf("The factorial of %d is: %ld",n,fact(n));
				printf("\n");
				break;
			case 2:
				printf("Enter a number:");
				scanf("%d", &n);
				s=sum(n);
				printf("the sum is: %d", s);
				printf("\n");
				break;
			case 3:
				printf("Enter a string:");
				scanf("%s", str);
				l = strlen(str);
				rev(str,l);
				printf("\n");
				break;
			case 4:
				printf("Enter a number: ");
				scanf("%d",&n);
				printf("Fibonacci term: %d",fibn(n));
				printf("\n");
				break;
			case 5:
				printf("Enter number of disks:");
				scanf("%d",&n);
				toh(n,'A','B','C');
				break;
			case 6:
				exit(0);
			default:
				printf("\nInvalid choice\n");
		}
	}while(1);	
}

long fact(int n)
{
	if(n == 1)
		return;
	return n*fact(n-1);
}

int sum (int n)
{
	int s;
	if(n == 0)
		return 0;
	s = n + sum(n-1);
	return s;
}

void rev(char str[size], int l)
{
	if(l<0)
		return;
	printf("%c",str[l-1]);
	rev(str,l-1);
}

int fibn(int n)
{
	if(n <= 1)
		return n;
	return fibn(n-1) + fibn(n-2);
}

void toh(int n,char from, char to, char aux)
{
	if(n == 1)
	{
		printf("\nMove disk 1 from rod %c to rod %c\n", from, to);
		return;
	}
	toh(n-1,from,aux,to);
	printf("\nMove disk %d from rod %c to rod %c\n",n,from,to);
	toh(n-1,aux,to,from);
}
