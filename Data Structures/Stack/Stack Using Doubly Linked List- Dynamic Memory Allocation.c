/*

Stack Using Doubly Linked List- Dynamic Memory Allocation

*/
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct stack//stack element
{
    struct stack* prev;
    int data;
    struct stack* next;
};

struct stack* top = NULL;

int main()
{
    while(true)
    {
        int ch;
        printf("\nEnter Choice:\n 1. Push\n 2. Pop\n 3. Traverse\n 4. Exit\n");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
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
    if(top == NULL)//when top is null, no elements in stack, stack is empty
        return true;

    return false;
}

void push()
{
    struct stack* temp = (struct stack*) malloc(sizeof(struct stack));//element to push
    temp->prev = NULL;
    temp->next = NULL;

    printf("\nEnter value to push\n");//element to be pushed's data
    scanf("%d",&temp->data);

    if(top == NULL)//if stack is empty, top will our new element
        top = temp;
    else
    {
        top->next = temp;//stack has some elements, top will point to temp & temp will point to top where temp is element to be pushed
        temp->prev = top;

        top = temp;//updating 'top' variable
    }

    printf("\nValue Pushed\n");
}

void pop()
{
    if(!is_empty())//stack has some elements so pop
    {
        if(top->prev == NULL && top->next == NULL)//only one element in stack, make top null
            top = NULL;
        else
        {
            top = top->prev;//shift 'top' variable one element backwards
            top->next->prev = NULL;//top cha next cha prev munje jo element delete karaich ahe tyacha 'prev' = NULL
            top->next = NULL;//top cha 'next' = NULL munje last element of stack disconnected, top now points to topmost element
        }

        printf("\nValue Popped\n");
    }
    else
        printf("\nStack Empty\n");
}

void traverse()
{
    if(is_empty())
        printf("\nStack Empty\n");
    else
    {
        struct stack* temp = top;

        printf("\nStack Elements are:\n");

        while(temp != NULL)//shift backwards and print data of elements till the last element
        {
            printf(" %d ",temp->data);

            temp = temp->prev;//temp is top at first, we printed its data, now we go to the element before it and print
            //its data until we eventually reach the end. :)
        }
        printf("\n");
    }
}
