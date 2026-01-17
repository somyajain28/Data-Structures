#include <stdio.h>
#include <stdlib.h>
#define size 5

typedef struct Deque
{
    int front, rear;
    int arr[size];
}deque;

void enqfront(deque *dq, int v);
void enqrear(deque *dq, int v);
int deqfront(deque *dq);
int deqrear(deque *dq);
void display(deque dq);
int isempty(deque dq);
int is_full(deque dq);

void main()
{
    deque dq;
    dq.front = -1;
    dq.rear = -1;
    int ch, v;

    do
    {
        printf("\n*--MENU--*\n");
        printf("1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Display\n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &v);
                enqfront(&dq, v);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &v);
                enqrear(&dq, v);
                break;
            case 3:
                v = deqfront(&dq);
                printf("Deleted from front: %d\n", v);
                break;
            case 4:
                v = deqrear(&dq);
                printf("Deleted from rear: %d\n", v);
                break;
            case 5:
                display(dq);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);
}

// Insert at front
void enqfront(deque *dq, int v)
{
    if(is_full(*dq))
    {
        printf("Deque is full\n");
        return;
    }
    if(isempty(*dq))
    {
        dq->front = 0;
        dq->rear = 0;
    }
    else if(dq->front == 0)
    {
        dq->front = size - 1;
    }
    else
    {
        dq->front--;
    }
    dq->arr[dq->front] = v;
}

// Insert at rear
void enqrear(deque *dq, int v)
{
    if(is_full(*dq))
    {
        printf("Deque is full\n");
        return;
    }
    if(isempty(*dq))
    {
        dq->front = 0;
        dq->rear = 0;
    }
    else if(dq->rear == size - 1)
    {
        dq->rear = 0;
    }
    else
    {
        dq->rear++;
    }
    dq->arr[dq->rear] = v;
}

// Delete from front
int deqfront(deque *dq)
{
    int v;
    v = -999;
    if(isempty(*dq))
    {
        printf("Deque is empty\n");
        return v;
    }
    v = dq->arr[dq->front];
    if(dq->front == dq->rear)
    {
        dq->front = -1;
        dq->rear = -1;
    }
    else if(dq->front == size - 1)
    {
        dq->front = 0;
    }
    else
    {
        dq->front++;
    }
    return v;
}

// Delete from rear
int deqrear(deque *dq)
{
    int v;
    v = -999;
    if(isempty(*dq))
    {
        printf("Deque is empty\n");
        return v;
    }
    v = dq->arr[dq->rear];
    if(dq->front == dq->rear)
    {
        dq->front = -1;
        dq->rear = -1;
    }
    else if(dq->rear == 0)
    {
        dq->rear = size - 1;
    }
    else
    {
        dq->rear--;
    }
    return v;
}

// Display deque elements
void display(deque dq)
{
    int i;
    if(isempty(dq))
    {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    i = dq.front;
    while(1)
    {
        printf("%d ", dq.arr[i]);
        if(i == dq.rear) 
            break;
        i = (i + 1) % size;
    }
    printf("\n");
}

// Check if empty
int isempty(deque dq)
{
    return (dq.front == -1);
}

// Check if full
int is_full(deque dq)
{
    return ((dq.front == 0 && dq.rear == size - 1) || (dq.front == dq.rear + 1));
}
