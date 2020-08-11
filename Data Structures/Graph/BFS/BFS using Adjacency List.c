/*

Refer: Abdul Bari DS

*/

#include<stdio.h>
#include"Linked_List.h"
#include"Stack.h"
#include"Queue.h"
#define SIZE 4

void read_graph(struct Node *graph[SIZE]);
void print_graph(struct Node *graph[SIZE]);
void BFS(struct Node *graph[SIZE],int n);

int main()
{
    struct Node *graph[SIZE] = {NULL};    

    read_graph(graph);

    print_graph(graph);

    BFS(graph,3);

}

void read_graph(struct Node *graph[SIZE])
{
    char reply;

    for(int i=1;i<SIZE;i++)
    {
        for(int j=1;j<SIZE;j++)
        {
            if(i != j)
            {
                printf("\nAre Vertices %d and %d adjacent? (Y/N)\n",i,j);
                scanf(" %c",&reply);

                if(reply == 'Y' || reply == 'y')
                {
                    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
                    t->data = j;
                    t->next = NULL;

                    if(graph[i] == NULL)
                        graph[i] = t;
                    else
                    {
                        struct Node *p = graph[i];

                        while(p->next != NULL)
                            p = p->next;
                        
                        p->next = t;
                    }
                    
                }
            }
        }
    }
}

void print_graph(struct Node *graph[SIZE])
{
    printf("\nGraph is:\n");

    for(int i=1;i<SIZE;i++)
    {
        struct Node *p = graph[i];

        while(p != NULL)
        {
            printf(" %d ",p->data);
            p = p->next;
        }

        printf("\n");
    }
}

void BFS(struct Node *graphx[SIZE],int n)
{
    struct Node *stack = NULL, *queue = NULL;

    printf("\nBFS:\n");
    printf(" %d ",n);

    stack_push(&stack,n);
    queue_enqueue(&queue,n);

    while(!is_empty_queue(queue))
    {
        int p = queue_dequeue(&queue);

        for(int i=1;i<SIZE;i++)
        {
            if(linked_list_search(graphx[p],i) && !stack_search(stack,i))
            {
                printf(" %d ",i);
                stack_push(&stack,i);
                queue_enqueue(&queue,i);
            }
        }
    }
}