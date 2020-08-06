#ifndef Stack

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

void stack_push(struct Node *stack, int value)
{
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    t->data = value;
    t->next = NULL;

    if(stack == NULL)
        stack = t;
    else
    {
        struct Node *p = stack, *q = NULL;

        while(p != NULL)
        {
            q = p;
            p = p->next;
        }
        q->next = t;
    }
}

struct Node* stack_pop(struct Node *stack)
{
    struct Node *p = stack, *q = NULL;

    while(p->next != NULL)
    {
        q = p;

        p = p->next;
    }

    q->next = NULL;

    return p;
}

struct Node* stack_peek(struct Node *stack)
{
    struct Node *p = stack;

    while(p->next != NULL)
        p = p->next;

    return p;
}

bool is_empty_stack(struct Node *stack)
{
    if(stack == NULL)
        return true;
    return false;
}

#define Stack
#endif