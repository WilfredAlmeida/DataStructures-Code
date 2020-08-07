#include<stdio.h>
#include"Queue.h"
#include"Stack.h"
#define SIZE 4

void print_graph(int graph[SIZE][SIZE]);
void read_graph(int graph[SIZE][SIZE]);
void BFS(int graph[SIZE][SIZE], int n);

int main()
{
    int graph[SIZE][SIZE];

    read_graph(graph);

    print_graph(graph);

    BFS(graph,3);
}

void print_graph(int graph[SIZE][SIZE])
{
    printf("\nGraph is:\n");

    for(int i=1;i<SIZE;i++)
    {
        for(int j=1;j<SIZE;j++)
        {
            printf(" %d ",graph[i][j]);
        }
        printf("\n");
    }
}

void read_graph(int graph[SIZE][SIZE])
{
    char reply;

    for(int i=1;i<SIZE;i++)
    {
        for(int j=1;j<SIZE;j++)
        {
            if(i == j)
                graph[i][j] = 0;
            
            else
            {
                printf("\nAre vertices %d and %d adjacent? (Y/N)\n",i,j);
                scanf(" %c",&reply);

                if(reply == 'y' || reply == 'Y')
                    graph[i][j] = 1;
                else
                    graph[i][j] = 0;
            }
        }
    }
}

void BFS(int graph[SIZE][SIZE], int n)//n is starting vertex
{
    struct Node *queue = NULL;
    struct SNode *stack = NULL;

    printf("\nBFS:\n");
    printf(" %d ",n);

    stack_push(&stack,n);

    queue_enqueue(&queue,n);

    while (!is_empty_queue(queue))
    {
        int a = queue_dequeue(&queue);

        for(int i=1;i<SIZE;i++)
        {
            if(graph[a][i] == 1 && stack_search(stack,i)==false)
            {
                queue_enqueue(&queue,i);
                printf(" %d ",i);
                stack_push(&stack,i);
            }
        }
    }
    
}