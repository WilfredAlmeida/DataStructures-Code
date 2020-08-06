/*

Refer: Abdul Bari DS

*/

#include <stdio.h>
#define SIZE 6 //Number of vertices and size of matrix

void read_graph(int matrix[SIZE][SIZE]);
void directed_graph(int matrix[SIZE][SIZE]);

int main()
{
    int adj_matrix[SIZE][SIZE];

    while (1)
    {
        int ch;
        printf("\nEnter Choice:\n 1. Directed Graph\n 2. Undirected Graph\n 3. Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            directed_graph(adj_matrix);
            break;
        case 2:
            undirected_graph(adj_matrix);
            break;
        case 3:
            exit(1);
            break;
        default:
            printf("\nInvalid Choice\n");
            break;
        }
    }

    return 0;
}

void directed_graph(int matrix[SIZE][SIZE])
{
    read_graph(matrix); //reading graph alues i.e. which node is adjacent to which node

    printf("\nVertices \t Indegree \t Outdegree");

    for (int i = 1; i < SIZE; i++) //i will denote rows i.e. vertices and j will denote
    //columns i.e. edges. graph[i][j] is hya vertex chi he edge
    {
        int indegree = 0, outdegree = 0;
        int j;

        //finding indegree
        //its easy to understand why j and i below, if u dont understand watch video
        for (j = 1; j < SIZE; j++)
            if (matrix[j][i] == 1)
                ++indegree;

        //finding outdegree
        //same as above comment, watch video
        for (j = 1; j < SIZE; j++)
            if (matrix[i][j] == 1)
                outdegree++;

        printf("\n   %d \t\t    %d \t\t    %d", i, indegree, outdegree); //formatted printing
    }
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

void undirected_graph(int matrix[SIZE][SIZE])
{ //same as directed
    read_graph(matrix);

    printf("\nVertices \t Degree");

    for (int i = 1; i < SIZE; i++)
    {
        int degree = 0, j;

        for (j = 1; j < SIZE; j++)
            if (matrix[i][j] == 1)
                degree++;

        printf("\n   %d \t\t   %d", i, degree);
    }
}