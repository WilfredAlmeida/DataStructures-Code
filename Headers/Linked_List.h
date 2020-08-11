#ifndef Linked_List

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"node.h"

void linked_list_insert_at_end(struct Node **root, int data)
{
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    
    t->data = data;
    t->next = NULL;

    if(*root == NULL)
        *root = t;
    else
    {
        struct Node *p = *root;

        while(p->next != NULL)
            p = p->next;

        p->next = t;
    }
}

void linked_list_insert_at_start(struct Node **root, int data)
{
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    t->data = data;
    t->next = NULL;

    if(*root == NULL)
        *root = t;
    else
    {
        t->next = *root;
        *root = t;
    }
}

bool linked_list_search(struct Node *root, int val)
{
    struct Node *p = root;
    
    while(p!= NULL && p->data != val)
        p = p->next;

    if(p != NULL && p->data == val)
        return true;
    
    return false;
}

void linked_list_sorted_insert(struct Node **root, int data)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    t->next = NULL;

    if(*root == NULL)
        *root = t;
    
    else
    {
        struct Node *p = *root, *q = NULL;

        while(p!=NULL && p->data > data)
        {
            q = p;
            p = p->next;
        }

        if(q == NULL)
        {
            t->next = p;
            *root = t;
        }
        else
        {
            t->next = p;
            q->next = t;
        }
    }   
}

#define Linked_List
#endif