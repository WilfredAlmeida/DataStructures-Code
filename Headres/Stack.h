#ifndef Stack

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct SNode
{
    int data;
    struct SNode *next;
};

void stack_push(struct SNode **stack, int value)
{
    struct SNode *t = (struct SNode*)malloc(sizeof(struct SNode));
    t->data = value;
    t->next = NULL;

    if(*stack == NULL)
        *stack = t;
    else
    {
        struct SNode *p = *stack, *q = NULL;

        while(p != NULL)
        {
            q = p;
            p = p->next;
        }
        q->next = t;
    }
}

int stack_pop(struct SNode **stack)
{
    struct SNode *p = *stack, *q = NULL;

    while(p->next != NULL)
    {
        q = p;

        p = p->next;
    }

    q->next = NULL;

    return p->data;
}

int stack_peek(struct SNode *stack)
{
    struct SNode *p = stack;

    while(p->next != NULL)
        p = p->next;

    return p->data;
}

bool is_empty_stack(struct SNode *stack)
{
    if(stack == NULL)
        return true;
    return false;
}

bool stack_search(struct SNode *stack,int val)
{
    struct SNode *p = stack;

    while(p != NULL && p->data != val)
        p = p->next;
    
    if(p != NULL && p->data == val)
        return true;
    
    return false;
}

#define Stack
#endif