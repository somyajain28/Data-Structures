#include <stdio.h>
#include <stdlib.h>
#define size 5

typedef struct linear_queue
{
    int front, rear;
    int arr[size];
}queue;

void enq(queue *q, int v);
int deq(queue *q);
void display(queue q);
int isempty(queue q);
int isfull(queue q);

void main()
{
    queue q;
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
                enq(&q, v);
                break;
            case 2:
                v = deq(&q);
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

void enq(queue *q, int v)
{
    if(isfull(*q))
    {
        printf("Queue is full\n");
        return;
    }
    if(q->front == -1)
        q->front = 0;
    q->arr[++(q->rear)] = v;
}

int deq(queue *q)
{
    int v;
    if(isempty(*q))
    {
        printf("Queue is empty\n");
        return -999;
    }
    v = q->arr[q->front];
    if(q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
        q->front++;
    return v;
}

void display(queue q)
{
    int i;
    if(isempty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for(i = q.front; i <= q.rear; i++)
        printf("%d ", q.arr[i]);
}

int isempty(queue q)
{
    return (q.front == -1 || q.front > q.rear);
}

int isfull(queue q)
{
    return (q.rear == size - 1);
}