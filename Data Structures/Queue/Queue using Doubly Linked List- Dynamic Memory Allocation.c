/*

Queue using Doubly Linked List- Dynamic Memory Allocation

*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct queue
{
    int data;
    struct queue* prev;
    struct queue* next;
};

struct queue* front = NULL;
struct queue* rear = NULL;

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
            break;
        }
    }

    return 0;
}

bool is_empty()
{
    if(front == NULL && rear == NULL)
        return true;
    else
        return false;
}

void enqueue()
{
    struct queue* temp = (struct queue*) malloc(sizeof(struct queue));
    temp->prev = NULL;
    temp->next = NULL;

    printf("\nEnter value to Enqueue\n");
    scanf("%d",&temp->data);

    if(is_empty())
    {
        front = temp;
        rear = temp;
    }
    else
    {
        temp->prev = rear;
        rear->next = temp;
        rear = temp;
    }

    printf("\nValue Enqueued\n");
}

void dequeue()
{
    if(is_empty())
        printf("\nQueue Empty\n");
    else if(front == rear)
    {
        front = NULL;
        rear = NULL;

        printf("\nValue Dequeued\n");
    }
    else
    {
        front->next->prev = NULL;
        front = front->next;

        printf("\nValue Dequeued\n");
    }
}

void traverse()
{
    if(is_empty())
        printf("\nQueue Empty\n");
    else
    {
        struct queue* temp = front;

        printf("\nQueue elements are:\n");

        while(temp != NULL)
        {
            printf(" %d ",temp->data);

            temp = temp->next;
        }
        printf("\n");
    }
}
