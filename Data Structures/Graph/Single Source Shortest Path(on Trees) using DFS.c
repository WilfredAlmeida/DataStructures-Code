/*

Refer: Code N Code videos

Single Source Shortest Path is the number of edges btwn a given vertex and all other
vertices of a graph.

*/

#include<stdio.h>
#include"Stack.h"
#include"Undirected_List_Graph.h"
#define COUNT 3

int* find_sso(struct Node *graph[COUNT], int n);
int dfs(struct Node *vertex, int d);
int get_index(struct Node *graph[COUNT],int v);

int main()
{
    struct Node *graph[COUNT] = {NULL};

    undirected_list_graph(graph,COUNT);

    int n = graph[0]->data;
    printf("\nSingle Source Shortest Path of %d is:\n",n);

    int *sso = find_sso(graph,1);

    for(int i=0;i<COUNT;i++)
    {
        printf(" %d ",sso[i]);
    }
    
    return 0;
}

int sso[] = {NULL},a=0;

int* find_sso(struct Node *graph[COUNT], int n)
{
    sso[a++] = dfs(graph[get_index(graph,n)],0);

    return sso;
}

int dfs(struct Node *vertex, int d)
{
    static struct Node *visited = NULL;
    
    if(visited == NULL || !stack_search(visited,d))
    {
        stack_push(&visited,d);

        struct Node *p = vertex;

        while(p != NULL)
        {
            dfs(p,d+1);

            p = p->next;
        }
    }
    return d;
}

int get_index(struct Node *graph[COUNT],int v)
{
    for(int i=0;i<COUNT;i++)
    {
        struct Node *p = graph[i];

        while(p != NULL)
        {
            if(p->data == v)
                return i;

            p = p->next;
        }
    }
    return -1;
}