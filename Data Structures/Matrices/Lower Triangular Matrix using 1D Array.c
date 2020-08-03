/*
Refer: Abdul Bari DS

Lower Triangular Matrix using 1D Array:

Non-Zero vlaues are stored in an 1D array and when a normal operation on a matrix
like get element is performed, indices passed are in view of a normal matrix and
the index of requires element is calculated using formula.

There are 2 ways of storing values of a matrix into a 1D array:

1. Row-Major Method:
    Values are stored row by row into 1D array, 1st row followed by 2nd row and so on.
    To get a value from such storage arrangement formula is:
        I[j][i] = [ ( i * (i+1) ) / 2 ] + j
    where i represents row and  j represents column

2. Column-Major Method:
    Values are stored row by row into 1D array, 1st row followed by 2nd row and so on.
    To get a value from such storage arrangement formula is:
        I[i][j] = [ ( ( n * (j-1) ) - { ( (j-2) * (j-1) ) / 2 ) } ] + (i-j)
    Where i = row and j = column

|1  0  0  0   0|
|2  3  0  0   0|
|4  5  6  0   0|
|7  8  9  10  0|
|11 12 13 14 15|

*/

#include <stdio.h>
#define SIZE 15
#define n 5

int main()
{


    int row_major_matrix[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 
                                    9, 10, 11, 12, 13, 14, 15};

    int column_major_matrix[SIZE] = {1, 2, 4, 7, 11, 3, 5, 8,
                                     12, 6, 9, 13, 10, 14, 15};

    printf("\n2,2 using row major: %d",get_row_major(row_major_matrix,3,3));

    printf("\n2,2 using column major: %d",get_column_major(column_major_matrix,3,3));

    return 0;
}

int get_row_major(int matrix[SIZE],int i, int j)
{
    if(i<=j)
    {
        int index = ( ( i * (i+1) ) / 2 ) + j;
        return matrix[index];
    }
    return 0;
}

int get_column_major(int matrix[SIZE], int i, int j)
{
    if(i<=j)
    {
        //Formula wrong and I cant find/figure the correct one
        int index = n*(j-1)+(j-2)*(j-1)/2+i-j;
        return matrix[index];
    }
    return 0;
}