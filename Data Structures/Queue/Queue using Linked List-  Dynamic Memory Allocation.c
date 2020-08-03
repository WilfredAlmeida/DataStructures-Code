/*

Queue using dynamic memory allocation

Operations performed:
1. Enqueue
2. Dequeue
3. Traverse
4. Length
5. Is Full(Overflow) -> Will not be performed as we are using dynamic memory allocation, we have unlimited memory
6. Is Empty(Underflow)

*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct queue
{
    int data;
    struct queue* next;
};

struct queue* front = NULL;
struct queue* rear = NULL;

int main()
{

    while(true)
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
                exit(true);
            default:
                printf("\nInvalid Choice\n");
                break;
        }
    }

    return 0;
}

int length()
{
    int l =0;

    struct queue* p = front;

    while(p != NULL)//Going from 'front' to 'rear', the address of next node is stored in 'next' variable of struct queue
        //so until it is not null(last node will have null) we increment 'l'
    {
        l++;

        p = p->next;
    }

    return l;
}

bool underflow()
{
    if(front == NULL)
        return true;

    return false;
}

void enqueue()
{
    struct queue* temp = (struct queue*) malloc(sizeof(struct queue));
    temp->next = NULL;

    printf("\nEnter data to enqueue:\n");
    scanf("%d",&temp->data);

    if(front == NULL && rear == NULL)//if no elements in queue, our node to be inserted will be front and rear both
    {
        front = temp;
        rear = temp;

        printf("\nElement Enqueued\n");
    }
    else//making current rear point to our new node and updating 'rear' variable
    {
        rear->next = temp;
        rear = temp;

        printf("\nElement Enqueued\n");
    }
}

void dequeue()
{
    printf("\nLength = %d\n",length());
    if(underflow())
        printf("\nQueue Empty\n");
    else
    {
        front = front->next;//updating 'front' variable to point to next variable

        if(front == NULL)//if 'front' becomes NULL then there are no elements in the queue, so rear should also be NULL
            rear = NULL;

        printf("\nElement Dequeued\n");
    }
}

void traverse()
{
    printf("\nLength = %d\n",length());
    if(length() <= 0)
        printf("\nQueue Empty\n");
    else
    {
        struct queue* p = front;

        printf("\nQueue Data:\n");

        while(p != NULL)//Going from 'front' to 'rear', the address of next node is stored in 'next' variable of struct queue
        //so until it is not null(last node will have null) we print its data
        {
            printf(" %d ",p->data);

            p = p->next;
        }
        printf("\n");
    }
}
