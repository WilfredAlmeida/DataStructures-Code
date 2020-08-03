/*

Double Ended Queue using Array- Static Memory Allocation

In a Double Ended Queue, insertion and deletion is performed from front as well as back.

*/

#include<stdio.h>
#include<stdbool.h>
#define N 5

int queue[N];
int rear = -1;
int front = -1;

int main()
{
    while(true)
    {
        int ch;
        printf("\nEnter Choice:\n 1. Insert\n 2. Delete\n 3. Traverse\n 4. Exit\n");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            insert_element();
            break;
        case 2:
            delete_element();
            break;
        case 3:
            traverse();
            break;
        case 4:
            exit(1);
        default:
            printf("\nInvalid Choice\n");
            break;
        }
    }

    return 0;
}

void insert_element()
{
    if(rear == N-1)
        printf("\nQueue Full\n");

    else
    {
        int ch;
        printf("\nInsert at:\n 1. Front\n 2. Rear\n");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            insert_at_front();
            break;
        case 2:
            insert_at_rear();
            break;
        default:
            printf("\nInvalid Choice\n");
            break;
        }
    }
}

void insert_at_rear()
{
    int data;
    printf("\nEnter value to insert\n");
    scanf("%d",&data);

    if(rear==-1 && front == -1)
    {
        front++;
        rear++;
        queue[rear] = data;

        printf("\nValue Inserted\n");
    }
    else
    {
        rear++;
        queue[rear] = data;
    }
}

void insert_at_front()
{
    int data;
    printf("\nEnter value to insert\n");
    scanf("%d",&data);

    for(int i=rear;i>=front;i--)
        queue[i+1] = queue[i];

    queue[front] = data;
    rear++;

    printf("\nValue Inserted\n");
}

void delete_element()
{
    if(rear == -1)
        printf("\nQueue Empty\n");

    else
    {
        int ch;
        printf("\n 1. Delete from:\n 1. Front\n 2. Rear\n");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            delete_at_front();
            break;
        case 2:
            delete_at_rear();
            break;
        default:
            printf("\nInvalid Choice\n");
            break;
        }
    }

}

void delete_at_front()
{
    for(int i=front;i<rear;i++)
        queue[i] = queue[i+1];

    rear--;

    printf("\nValue Deleted\n");
}


void delete_at_rear()
{
    rear--;

    printf("\nValue Deleted\n");
}

void traverse()
{
    if(rear == -1)
        printf("\nQueue Empty\n");

    else
    {
        printf("\nQueue Elements are:\n");

        for(int i=front;i<=rear;i++)
            printf(" %d ",queue[i]);
    }
}
