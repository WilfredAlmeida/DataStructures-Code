//Queue using Array - Static Memory Allocation

#include<stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int main()
{
    for(;;)
    {
        int ch;

        printf("\nEnter Your Choice:\n 1. Enqueue\n 2. Dequeue\n 3. Traverse\n 4. Exit\n");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            traverse();
            break;
        case 4:
            exit(1);
        default:
            printf("\nInvalid Choice\n");
        }
    }
    return 0;
}
void enqueue()
{
    if(rear == SIZE-1)
        printf("\nQueue Overflow\n");
    else
    {
        int val;
        printf("\nEnter Value to insert:\n");
        scanf("%d",&val);

        if(rear ==-1 && front == -1)
        {
            rear = 0;
            front = 0;

            queue[rear] = val;
            printf("\nValue Inserted\n");
        }
        else
        {
            rear++;
            queue[rear] = val;
        }
    }
}
void dequeue()
{
    if(front > rear || front == -1)
        printf("\nQueue Underflow");
    else
    {
        queue[front] == NULL;

        front++;
    }
}
void traverse()
{
    printf("\nQueue Elements are:\n");
    for(int i=front;i<=rear;i++)
    {
        printf("%d  ",queue[i]);
    }
}
