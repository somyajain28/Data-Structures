#include <stdio.h>
#include <stdlib.h>
#define size 5

typedef struct circular_queue
{
    int front, rear;
    int arr[size];
}cque;

void cenq(cque *q, int v);
int cdeq(cque *q);
void display(cque q);
int isempty(cque q);
int isfull(cque q);

void main()
{
    cque q;
    q.front = -1;
    q.rear = -1;
    int ch, v;

    do
    {
        printf("\n*--MENU--*\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &v);
                cenq(&q, v);
                break;
            case 2:
                v = cdeq(&q);
                printf("Dequeued element: %d\n", v);
                break;
            case 3:
                display(q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);
}

void cenq(cque *q, int v)
{
    if(isfull(*q))
    {
        printf("Queue is full\n");
        return;
    }
    if(q->front == -1)
        q->front = 0;
    q->rear = ((++q->rear) % size);  
    q->arr[q->rear] = v;
}

int cdeq(cque *q)
{
    int v;
    v = -999;
    if(isempty(*q))
    {
        printf("Queue is empty\n");
        return v;
    }
    if(q->front == q->rear)
    {
        v = q->arr[q->front]; // Save the value to return
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        v = q->arr[q->front];
        q->front = (++q->front) % size;  
    }
    return v; 
}

void display(cque q)
{
    int i;
    i = q.front;
    if(isempty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    while(i != q.rear)
    {
        printf("%d ", q.arr[i]);
        i = (i+1) % size;
    }
    printf("%d ", q.arr[q.rear]); // Print the last element
}
int isempty(cque q)
{
    return (q.front == -1);
}

int isfull(cque q)
{
    return (q.front == (++q.rear) % size);
} 