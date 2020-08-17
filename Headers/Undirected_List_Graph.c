#ifndef Undirected_List_Graph

#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
#define SIZE 100

int read_list_graph(struct Node *graph[SIZE],int vertices[], int n)//read which vertex is adjacent to whom
{
    struct Node *p = NULL, *q = NULL;

    char reply;

    for (int i = 0; i < n; i++)//i for vertices
    {
        if(graph[i] == NULL)
        {
            struct Node *t = (struct Node*)malloc(sizeof(struct Node));
            t->data = vertices[i];
            t->next = NULL;

            graph[i] = t;
        }
        for (int j = 0; j < n; j++)//j for edges
        {
            if (i != j)//We are not considering cyclic so vertex can't have edge to
            //itself.
            {
                printf("\nAre vertices %d and %d adjacent? (Y/N)",
                 vertices[i], vertices[j]);
                
                scanf(" %c", &reply);

                if (reply == 'y' || reply == 'Y')
                {
                    //Node to insert indicating edge. Watch video if u can't understand
                    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
                    t->data = vertices[j];
                    t->next = NULL;

                    if (graph[i] == NULL)//if there is no edge till now
                    {
                        graph[i] = t;
                    }
                    else//if there are some edges present
                    {
                        p = graph[i];

                        while (p != NULL)
                        {
                            q = p;
                            p = p->next;
                        }
                        q->next = t;
                    }
                }
            }
        }
    }
    return 0;
}

int undirected_list_graph(struct Node *graph[SIZE])
{
    int n=0, vertices[100], a=0;

    printf("\nEnter Number of vertices:\n");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        printf("\nEnter vertex: %d\n",i+1);
        scanf("%d",&vertices[a++]);
    }
}

void print_list_graph(struct Node *graph[SIZE], int n)
{
    printf("\nGraph is:");
    for(int i=0;i<n;i++)
    {
        struct Node *p = graph[i]->next;

        if(p != NULL)
        {
            printf("\n%d -> ",graph[i]->data);
            while(p != NULL)
            {
                printf(" %d ",p->data);
                p = p->next;
            }
        }
    }

    printf("\n\nVertices \t Degree");
    for(int i=0;i<n;i++)
    {   
        struct Node *q = graph[i]->next;
        if(q != NULL)
        {
            int degree = 0, t = graph[i]->data;

            while(q!=NULL)//To traverse edges
            {
                degree++;

                q = q->next;
            }

            printf("\n   %d \t\t    %d",t,degree);
        }
    }
}

#define Undirected_List_Graph
#endif