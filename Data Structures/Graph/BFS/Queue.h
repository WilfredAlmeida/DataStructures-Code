#ifndef Queue

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

void queue_enqueue(struct Node **queue, int val)
{
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    t->data = val;
    t->next = NULL;

    if(*queue == NULL)
    {
        *queue = t;
    }
    else
    {
        struct Node *p = *queue;

        while(p->next != NULL)
            p = p->next;
        
        p->next = t;
    }
}

int queue_dequeue(struct Node **queue)
{
    struct Node *p = *queue;
    *queue = (*queue)->next;
    return p->data;
}

bool is_empty_queue(struct Node *queue)
{
    if(queue == NULL)
        return true;

    return false;
}

#define Queue
#endif