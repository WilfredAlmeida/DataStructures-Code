/*

|1 0 0 0|
|0 2 0 0|
|0 0 3 0|
|0 0 0 4|

A 4x4 Diagonal Matrix
In diagonal matrix, only diagonal elements are used to store values, rest all are 0.

*/

#include<stdio.h>
#define SIZE 4
int main()
{
    int matrix[SIZE][SIZE] = {
                              {1,0,0,0},
                              {0,2,0,0},
                              {0,0,3,0},
                              {0,0,0,4}
                             };
    print_matrix(matrix);

    insert_into_matrix(matrix,66,2,2);

    print_matrix(matrix);

    return 0;
}

void print_matrix(int matrix[SIZE][SIZE])
{
    printf("\nMatrix is:\n");
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            printf(" %d ",matrix[i][j]);
        }
        printf("\n");
    }
}

void insert_into_matrix(int matrix[SIZE][SIZE],int val,int i,int j)
{
    if(i == j)
        matrix[i][j] = val;
}