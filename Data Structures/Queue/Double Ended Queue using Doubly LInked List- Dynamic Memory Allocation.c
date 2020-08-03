/*

Double Ended Queue using Doubly Linked List

*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

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
        break;
    }
}

void insert_at_front()
{
    struct queue* temp = (struct queue*) malloc(sizeof(struct queue));
    temp->prev = NULL;
    temp->next = NULL;

    printf("\nEnter value to insert\n");
    scanf("%d",&temp->data);

    if(is_empty())
    {
        front = temp;
        rear = temp;
    }
    else
    {
        temp->next = front;
        front->prev = temp;
        front = temp;

        printf("\nElement Inserted\n");
    }
}

void insert_at_rear()
{
    struct queue* temp = (struct queue*) malloc(sizeof(struct queue));
    temp->prev = NULL;
    temp->next = NULL;

    printf("\nEnter value to insert\n");
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

        printf("\nElement Inserted\n");
    }
}

void delete_element()
{
    if(is_empty())
        printf("\nQueue Empty\n");

    else
    {
        int ch;
        printf("\n1. Delete from:\n 1. Front\n 2. Rear\n");
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
    if(front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        front = front->next;
        front->prev->next = NULL;
        front->prev = NULL;
    }

    printf("\nElement Deleted\n");

}

void delete_at_rear()
{
    if(front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        rear = rear->prev;
        rear->next->prev = NULL;
        rear->next = NULL;
    }

    printf("\nElement Deleted\n");
}

void traverse()
{
    if(is_empty())
        printf("\nQueue Empty\n");
    else
    {
        struct queue* temp = front;

        printf("\nQueue Elements are:\n");

        while(temp != NULL)
        {
            printf(" %d ",temp->data);

            temp = temp->next;
        }

        printf("\n");
    }
}
