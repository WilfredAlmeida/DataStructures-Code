/*

Refer: Abdul Bari DS

*/
#include<stdio.h>
#include"Stack.h"
#include"Linked_List.h"
#define SIZE 5

int read_graph(struct Node *graph[SIZE]);
void print_graph(struct Node *graph[SIZE]);
void DFS(struct Node *graph[SIZE], int n);

int main()
{
    struct Node *graph[SIZE] = {NULL};

    read_graph(graph);

    print_graph(graph);

    printf("\nDFS:\n");
    DFS(graph,1);
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
                    t->data = j;
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

void print_graph(struct Node *graph[SIZE])
{
    printf("\nGraph is:\n");

    for(int i=1;i<SIZE;i++)
    {
        struct Node *p = graph[i];
        printf("%d -> ",i);
        while(p != NULL)
        {
            printf(" %d ",p->data);
            p = p->next;
        }

        printf("\n");
    }
}

void DFS(struct Node *graph[SIZE], int n)
{//Detailed explaination in DFS using Adjacency Matrix

    static struct Node *stack = NULL;//To keep record if vertex is already visited
    //or not

    if(stack == NULL || !stack_search(stack,n))//Vertex not visited
    {
        printf(" %d ",n);//travsrse vertex
        stack_push(&stack,n);//push into stack to indicate it traversed
        
        //now for the given vertex, go to its connected vertices one by one
        struct Node *p = graph[n];
        while(p != NULL)
        {
            DFS(graph,p->data);//DFS each connected vertex
            p = p->next;
        }
    }
}
