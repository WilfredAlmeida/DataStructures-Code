/*

Double Ended Queue using Linked List- Dynamic Memory Allocation

*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct queue
{
    int data;
    struct queue* next;
};

struct queue* front;
struct queue* rear;

int main()
{

    while(1)
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

bool is_empty()
{
    if(front == NULL && rear == NULL)
        return true;

    return false;
}

void insert_element()
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
    }
}

void insert_at_front()
{
    struct queue* temp = (struct queue*) malloc(sizeof(struct queue));
    temp->next = NULL;

    printf("\nEnter value to insert\n");
    scanf("%d",&temp->data);

    if(front == NULL && rear == NULL)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        temp->next = front;
        front = temp;
    }

    printf("\nValue Inserted\n");
}

void insert_at_rear()
{
    struct queue* temp = (struct queue*) malloc(sizeof(struct queue));
    temp->next = NULL;

    printf("\nEnter value to insert\n");
    scanf("%d",&temp->data);

    if(front == NULL && rear == NULL)
    {
        front = temp;
        rear = temp;
    }
    else
        rear->next = temp;
        rear = temp;

    printf("\nValue Inserted\n");
}

void delete_element()
{
    if(is_empty())
        printf("\nQueue Empty\n");
    else
    {
        int ch;
        printf("\nDelete at:\n 1. Front\n 2. Rear\n");
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
        }
    }
}

void delete_at_front()
{
    if(front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
        front = front->next;

    printf("\nValue Deleted\n");
}

void delete_at_rear()
{
    if(front == rear)
    {
        front = NULL;
        rear = NULL;

        printf("\nValue Deleted");
    }
    else
    {
        struct queue* p = front;
        struct queue* q;

        while(p != rear)
        {
            q = p;

            p = p->next;
        }

        q->next = NULL;


        rear = q;

        printf("\nValue Deleted\n");
    }
}

void traverse()
{
    if(!is_empty())
    {
        struct queue* p = front;

        printf("\nQueue Elements are:\n");

        while(p != NULL)
        {
            printf(" %d ",p->data);
            p = p->next;
        }
    }
    else
        printf("\nQueue Empty\n");
}
