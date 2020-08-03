/*
Refer: Abdul Bari DS
Lower Triangular Matrix: Matrix with non zero elements forming a lower triangle.

|1  0  0  0   0|
|2  3  0  0   0|
|4  5  6  0   0|
|7  8  9  10  0|
|11 12 13 14 15|

*/

#include<stdio.h>
#define SIZE 5

int main()
{
    int matrix[SIZE][SIZE] = {
                                {1,  0,  0,  0,   0},
                                {2,  3,  0,  0,   0},
                                {4,  5,  6,  0,   0},
                                {7,  8,  9,  10,  0},
                                {11, 12, 13, 14, 15}
                             };
    print_matrix(matrix);

    set(matrix,20,2,2);
    
    print_matrix(matrix);

    printf("\n 3,2 = %d",get(matrix,3,2));

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

void set(int matrix[SIZE][SIZE],int val, int i, int j)
{
    if(i<=j)
        matrix[i][j] = val;
}

int get(int matrix[SIZE][SIZE],int i, int j)
{
    return matrix[i][j];
}