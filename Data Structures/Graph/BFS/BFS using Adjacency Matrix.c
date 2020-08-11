/*

Refer: Abdul Bari DS

Here SIZE is 4, so vertices are 1,2,3

*/

#include <stdio.h>
#include "Queue.h"
#include "Stack.h"
#define SIZE 4

void print_graph(int graph[SIZE][SIZE]);
void read_graph(int graph[SIZE][SIZE]);
void BFS(int graph[SIZE][SIZE], int n);//grpah and starting vertex

int main()
{
    int graph[SIZE][SIZE];

    read_graph(graph);

    print_graph(graph);

    BFS(graph, 1);
}

void print_graph(int graph[SIZE][SIZE])
{
    printf("\nGraph is:\n");

    for (int i = 1; i < SIZE; i++)
    {
        for (int j = 1; j < SIZE; j++)
        {
            printf(" %d ", graph[i][j]);
        }
        printf("\n");
    }
}

void read_graph(int graph[SIZE][SIZE])//See Graph using Adjacency matrix file for 
//explaination
{
    char reply;

    for (int i = 1; i < SIZE; i++)
    {
        for (int j = 1; j < SIZE; j++)
        {
            if (i == j)
                graph[i][j] = 0;

            else
            {
                printf("\nAre vertices %d and %d adjacent? (Y/N)\n", i, j);
                scanf(" %c", &reply);

                if (reply == 'y' || reply == 'Y')
                    graph[i][j] = 1;
                else
                    graph[i][j] = 0;
            }
        }
    }
}

void BFS(int graph[SIZE][SIZE], int n) //n is starting vertex
{

/*
    Idea of BFS is, go to a vertex, traverse it, go to its connected vertices in
    any order. To acheieve this, we first take the starting vertex, print its data,
    enqueue it in a queue and push it in a stack. Queue is used to store 
    connected vertices of a vertex and stack is used to store vertices which are
    already traversed so that they are not traversed again.

    So in program, we take a vertex, check if its already traversed, if not than
    print it, enqueue its connected vertices in queue, push it into stack and 
    continue.
    
*/

    struct Node *queue = NULL;
    struct SNode *stack = NULL;

    printf("\nBFS:\n");
    printf(" %d ", n);//printing starting node

    stack_push(&stack, n);//pushing it in stack to indicate its printed already
    queue_enqueue(&queue, n);//enqueueing it.

    while (!is_empty_queue(queue))//connected vertices of all vertices in graph
    // will be in queue, we check them all.
    {
        int a = queue_dequeue(&queue);//Take a vertex from queue

        for (int i = 1; i < SIZE; i++)//check all connected vertices of that vertex
        {
            if (graph[a][i] == 1 && stack_search(stack, i) == false)
            //If a vertex is connected to our vertex and it is not yet traversed then,
            {
                printf(" %d ", i);//traverse it
                queue_enqueue(&queue, i);//enqueue it to check for its connections
                stack_push(&stack, i);//mark it traversed
            }
        }
    }
}