/*

Refer: Code N Code videos

Components are groups of vertices in a graph. If there are 4 vertices say 1,2,3,4
and 1,2 and 3,4 are connected but no connection exists btwn 1<->3,1<->4,2<->3,2<->4
than we say there are 2 components in the graph.

In the count function below, we dfs a vertex, so that vertex and its connected
vertices get added into visited vertices list and so we increment count by one.
Now we dfs all vertices similarly and if any vertex is not pre-dfs'd or not traversed previously would mean that that vertex belongs to different component. So we dfs it and increment count.

*/

#include<stdio.h>
#include"Undirected_List_Graph.h"
#include"stack.h"
#define SIZE 4


void dfs(struct Node *vertex,struct Node **visited);
int count_connected_components(struct Node *graph[SIZE]);

int main()
{
    struct Node *graph[SIZE] = {NULL};

    undirected_list_graph(graph,SIZE);

    printf("\nNumber of connected components is %d\n",count_connected_components(graph));
    
    
    return 0;
}

int count_connected_components(struct Node *graph[SIZE])
{
    struct Node *visited = NULL;//stackof visited vertices

    int count = 0;

    for(int i=0;i<SIZE;i++)//check all vertices
    {
        if(visited == NULL || !stack_search(visited,graph[i]->data))
        {
            dfs(graph[i],&visited);
            count++;
        }
    }
    return count;
}

void dfs(struct Node *vertex,struct Node **visited)
{
    if(!stack_search(*visited,vertex->data))
    {
        stack_push(&(*visited),vertex->data);

        struct Node *p = vertex;
        while(p != NULL)
        {
            dfs(p,visited);
            
            p=p->next;
        }
    }
}