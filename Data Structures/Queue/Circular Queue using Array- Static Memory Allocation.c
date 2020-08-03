/*

Circular Queue using Array- Static Memory Allocation

Note:
As we know, for queue there are 2 ways:
1. When Dequeue is performed, move 'front' variable forwards
2. Shift elements lest one by one and update rear.

As googled, asked on stackoverflow, both are correct and can use any.

We have followed 2nd approach for all other queue implementations, however it is not possible to implement circular queue
using this approach so we use 1st approach here.


*/

#include<stdio.h>
#include<stdbool.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int main()
{

    int ch;
    while(true)
    {
        printf("\nEnter Choice:\n 1. Enqueue\n 2. Dequeue\n 3. Traverse\n 4. Exit\n");
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

bool is_empty()//Check queue is empty or not
{
    if(front == -1 && rear == -1)//if empty than they wont point anywhere
        return true;

    return false;
}

bool is_full()
{
    if(rear+1 == front ||  (rear == SIZE-1 && front == 0))//As it is a circular queue, it can be full just like a linear
        //queue and being circular, if rear and front are consecutive it means queue is full :)
        return true;

    return false;
}

void enqueue()
{
    if(is_full())
        printf("\nQueue Full\n");
    else
    {
        int data;

        printf("\nEnter value to enqueue:\n");
        scanf("%d",&data);

        if(front == -1 && rear == -1)//if queue is empty, do just like linear queue
        {
            front++;
            rear++;

            queue[rear] = data;
        }

        else if(rear == SIZE-1 && front != 0)///rear is last element of queue and front is not zero which means front has
            ///moved forward indicating that there is some space before it and thus, as front begins from 0, even if only one
            ///space exists it would be at index 0 and increase gradually :)
        {
            rear = 0;

            queue[rear] = data;
        }

        else///insertion like linear queue
        {
            rear++;

            queue[rear] = data;
        }
        printf("\nValue Enqueued\n");
    }
}

void dequeue()
{
    if(is_empty())
        printf("\nQueue Empty\n");
    else
    {
        if(front == rear && rear == SIZE-1)///if both point at last element
        {
            front = -1;
            rear = -1;
        }

        else if(front == SIZE-1 && rear < front)///front is pointing to last index and rear points to some element then
            ///being a circular queue, there are some elements present and thus front will point to 0th index
            front = 0;

        else///linear queue deletion
        {
            front++;

            if(front > SIZE-1)///if front == index which is not present in queue than make it 0, just like linear queue
                front = 0;
        }

        printf("\n Value Dequeued\n");
    }
}

void traverse()
{
    if(is_empty())
        printf("\nQueue Empty\n");

    else
    {
        printf("\nQueue Elements are:\n");

        if(front < rear)///printing linear queue
        {
            for(int i=front;i<=rear;i++)
                {printf(" %d ",queue[i]);}
        }

        else///printing queue in pieces, imagine this and you'll get it.
        {
            for(int i=front;i<SIZE;i++)///from front to last index
                printf(" %d ",queue[i]);

            for(int j=0;j<=rear;j++)///0 to rear
                printf(" %d ",queue[j]);
        }
    }
}
