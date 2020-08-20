/*

Refer: Code N Code Videos

Bipartite/Bigraph is a graph in which u can divide vertices into 2 sets of any size
such that:
1. Each vertex belongs to exactly one of the two sets
2. Each edge connects vertices of 2 different sets

Explaination:
Condition 1 says that a vertex must be part of only one set.
Condition 2 says that vertices connected by any edge must be from different sets.

To implement this, when we dfs the vertices we assign them a value say color, for
each dfs called the value is toggled btwm 1 and 0, in the end we check all
vertices and if any vertex has same color as it parent vertex then condition 2 is
failed and we return false.

*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"Undirected_List_Graph.h"
#include"Stack.h"
#include"Linked_List.h"
#define COUNT 6

struct Color
{
    int c;
    struct Node *vertex;
    struct Color *next;
};

bool check_bipartite(struct Node *graph[COUNT]);
bool dfs(struct Node *vertex, int color);
void set_color(struct Color **col, struct Node *vertex, int color);
int get_color(struct Color **col, struct Node *vertex);

int main()
{
    struct Node *graph[COUNT] = {NULL};

    undirected_list_graph(graph,COUNT);

    bool is_bipartite = check_bipartite(graph);

    printf("Graph is Bipartite: %d", is_bipartite);
    
    return 0;
}

bool check_bipartite(struct Node *graph[COUNT])
{
    return dfs(graph[0],1);
}

bool dfs(struct Node *vertex, int color)
{
    static struct Node *visited = NULL;
    static struct Color *col = NULL;

    if(visited == NULL || !stack_search(visited,vertex->data))
    {
        stack_push(&visited,vertex->data);

        set_color(&col,vertex,color);

        struct Node *p = vertex;

        while(p != NULL)
        {
            if(stack_search(visited,p->data) && 
                (get_color(&col,vertex) == get_color(&col,p)))
            {    
                return false;
            }

            else if(!stack_search(visited,p->data))
            {
                return dfs(p,!color);
            }

            p = p->next;
        }

        return true;
    }
}

void set_color(struct Color **col, struct Node *vertex, int color)
{
    struct Color *t = (struct Color*)malloc(sizeof(struct Color));
    t->c = color;
    t->vertex = vertex;
    t->next = NULL;

    if(*col == NULL)
        *col = t;
    else
    {
        struct Color *p = *col;

        while(p != NULL)
        {
            p = p->next;
        }
        p->next = t;
    }
}

int get_color(struct Color **col, struct Node *vertex)
{
    struct Color *p = *col;

    if(p->vertex == vertex)
        return p->c;
    else
    {
        while(p->vertex != vertex)
            p = p->next;
        
        return p->c;
    }
}