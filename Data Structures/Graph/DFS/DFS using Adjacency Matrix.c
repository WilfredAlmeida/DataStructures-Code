/*

Refer: Abdul Bari DS

*/

#include<stdio.h>
#include"Stack.h"
#define SIZE 6

void read_graph(int matrix[SIZE][SIZE]);
void print_graph(int graph[SIZE][SIZE]);
void DFS(int graph[SIZE][SIZE], int n);

int main()
{
    int graph[SIZE][SIZE];

    read_graph(graph);

    print_graph(graph);

    printf("\nDFS is:\n");
    DFS(graph,3);
}

void read_graph(int matrix[SIZE][SIZE]) //reading values of a graph, i.e. reading
//edges btwn vertices
{
    char reply;

    for (int i = 1; i < SIZE; i++) //i for rows i.e. vertices
    {
        for (int j = 1; j < SIZE; j++) //j for columns i.e. edges
        {
            if (i == j) //vertex can't have edge to itself, we are not considering
            //cyclic concept here
            {
                matrix[i][j] = 0;
            }
            else
            {
                printf("\nAre vertices %d and %d adjacent? (Y/N)\n", i, j); //finding which
                //vertex is adjacent to whom
                scanf(" %c", &reply);

                if (reply == 'Y' || reply == 'y')
                    matrix[i][j] = 1;
                else
                    matrix[i][j] = 0;
            }
        }
    }
}

void print_graph(int graph[SIZE][SIZE])
{
    printf("\nGraph is:");
    for(int i=1;i<SIZE;i++)
    {
        printf("\n%d -> ",i);
        
        for(int j=1;j<SIZE;j++)
            printf(" %d ",graph[i][j]);
    }
}

void DFS(int graph[SIZE][SIZE], int n)
//Idea of DFS is, take a vertex, traverse it, go to its some connected vertex,
//traverse it and come back to orignal vertex, go to some other connected vertex
//of it and do the same. For eg. A,B,C,D are a graphs node. Suppose A is connected
//to B & C and B id connected to D. Then for DFS, take A, traverse it, go to one
//of its connected node lets say B and traverse it, got to its some connected node
//say D and do the same. After end is reached, go back to vertex from where you
//came to D, i.e. B, then repeat the procedure and goto A, from A goto its other
//connected vertex C.
//In BFS, we traverse A, traverse its connections, taken out some vertex, do the
//same for it.
{
    static struct Node *stack = NULL;//To keep record of visited vertices

//What we do here is take a connected vertex of a vertex, check if it is previously
//traversed or not and if not traverse it, repeat for its some connected vertex
    if(stack == NULL || !stack_search(stack,n))
    {
        printf(" %d ", n);
        stack_push(&stack,n);

        for(int i=1;i<SIZE;i++)//Check is any vertex is connected to our vertex
            if(graph[n][i] == 1 && !stack_search(stack,i))//connected and not traversed
                DFS(graph,i);//if yes DFS it
    }
}