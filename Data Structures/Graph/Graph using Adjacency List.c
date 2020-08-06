/*

Refer: Abdul Bari DS

*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 6

struct Node
{
    int vertex;
    struct Node *next;
};


int read_graph(struct Node *graph[SIZE]);
int directed_graph(struct Node *graph[SIZE]);

int main()
{
    struct Node *graph[SIZE] = {NULL};//array of linkedlists, see the image in
    //chaining folder if you can't visualize the arrangement.

    int ch;

    while (1)
    {
        printf("\nEnter Choice:\n 1. Directed\n 2. Undirected\n 3. Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            directed_graph(graph);
            break;
        
        case 2:
            undirected_graph(graph);
            break;

        case 3:
            exit(0);
            break;

        default:
            printf("\nInvalid Choice\n");
            break;
        }
    }
    return 0;
}

int read_graph(struct Node *graph[SIZE])//read which vertex is adjacent to whom
{
    struct Node *p = NULL, *q = NULL;

    char reply;

    for (int i = 1; i < SIZE; i++)//i for vertices
    {
        for (int j = 1; j < SIZE; j++)//j for edges
        {
            if (i != j)//We are not considering cyclic so vertex can't have edge to
            //itself.
            {
                printf("\nAre vertices %d and %d adjacent? (Y/N)", i, j);
                scanf(" %c", &reply);

                if (reply == 'y' || reply == 'Y')
                {
                    //Node to insert indicating edge. Watch video if u can't understand
                    struct Node *t = (struct Node *)malloc(sizeof(struct Node *));
                    t->vertex = j;
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

int directed_graph(struct Node *graph[SIZE])
{

    read_graph(graph);

    printf("\nVertex \t Indegree \t Outdegree");
    for (int i = 1; i < SIZE; i++)
    {
        int indegree = 0, outdegree = 0;

        //To find indegree, we will traverse edges of each vertex
        for (int j = 1; j < SIZE; j++)//for teaversing vertices
        {
            struct Node *p = graph[j];

            while(p != NULL)//to traverse edges of a vertex
            {
                if(p->vertex == i)
                    indegree++;
                
                p = p->next;
            }
        }

        //Outdegree is the number of edges pointed by a vertex, we count that
        struct Node *p = graph[i];
        while(p != NULL)
        {
            outdegree++;
            p = p->next;
        }

        printf("\n   %d \t   %d \t\t   %d",i,indegree,outdegree);
    }
    return 0;
}

int undirected_graph(struct Node *graph[SIZE])
{
    read_graph(graph);

    printf("\nVertices \t Degree");

    //Degree is edges connected to a node, we count edges for each node.
    for(int i=1;i<SIZE;i++)//To traverse each vertex
    {
        struct Node *p = graph[i];
        int degree = 0;

        while(p!=NULL)//To traverse edges
        {
            degree++;

            p = p->next;
        }

        printf("\n   %d \t\t    %d",i,degree);
    }
}