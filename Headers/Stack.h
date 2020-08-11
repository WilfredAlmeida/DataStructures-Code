#ifndef Stack

#include<stdlib.h>
#include<stdbool.h>
#include"Node.h"

void stack_push(struct Node **stack, int value)
{
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    t->data = value;
    t->next = NULL;

    if(*stack == NULL)
        *stack = t;
    else
    {
        struct Node *p = *stack, *q = NULL;

        while(p != NULL)
        {
            q = p;
            p = p->next;
        }
        q->next = t;
    }
}

int stack_pop(struct Node **stack)
{
    struct Node *p = *stack, *q = NULL;

    while(p->next != NULL)
    {
        q = p;

        p = p->next;
    }

    q->next = NULL;

    return p->data;
}

int stack_peek(struct Node *stack)
{
    struct Node *p = stack;

    while(p->next != NULL)
        p = p->next;

    return p->data;
}

bool is_empty_stack(struct Node *stack)
{
    if(stack == NULL)
        return true;
    return false;
}

bool stack_search(struct Node *stack,int val)
{
    struct Node *p = stack;

    while(p != NULL && p->data != val)
        p = p->next;
    
    if(p != NULL && p->data == val)
        return true;
    
    return false;
}

#define Stack
#endif