/*

Refer: Abdul Bari DS.

Can be done using 1D,2D array, have done using 1D array.

Tri-Diagonal Matrix:
    Matrix with 3 diagonals as non zero.

    1  2      3   4    5
1 | a11 a12   0   0    0   |
2 | a21 a22  a23  0    0   |
3 | 0   a32  a33 a34   0   |
4 | 0    0   a43 a44  a45  |
5 | 0    0    0  a54  a55  |

PS: a11 means element at address (1,1).

For a matrix of nxn, main diagonal consists of n elements, lower and upper 
diagonals contain n-1 elements.

For 1D array:
First lower diagonal, then main diagonal and than upper diagonal are stored.


To determine in which diagonal element is:
    1. if i-j = 1 -> Lower Diagonal.
    2. if i-j = 0 -> Main Diagonal.
    3. if i-j = -1 -> Upper Diagonal.


To calculate position w.r.t actual matrix, there are 3 cases:
1. Element is in main diagonal i.e i-j = 0:
    As per storing order stated above, there is a diagonal with n-1 elements before
    main diagonal so,
        Formula: n-1 + i-1
    i-1 by observing relations btwn indexes.

2. Element is in Lower Diagonal i.e. i-j = 1:
    As per storing order stated above, it is at the beginning of the array so,
    By obseration:
        Formula: i-1

3. Element is in Upper Diagonal i.e. i-j = -1:
    As per storing order stated above, it has n-1 elements of lower diagonal and
    n elements of upper diagonal before it so,
        Formula: n-1+n+i-1 = 2n-1+i-1 = 2n+i-2
    i-1 by observation.

Size of 1D array = n+(n-1)*2

Give input to following program as an actual matrix.
*/

#include <stdio.h>
#define SIZE 13
#define n 5

int main()
{
    int matrix[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

    print_matrix(matrix);

    set(matrix,55,3,3);

    print_matrix(matrix);

    printf("\n2,2 = %d",get(matrix,2,2));

    return 0;
}

void print_matrix(int *matrix)
{
    printf("\nMatrix is:\n");

    for (int i = 0; i < SIZE; i++)
        printf(" %d ", matrix[i]);
}

void set(int *matrix, int val, int i, int j)//to set values of matrix
{
    if (i - j == -1)
    {
        int pos = 2 * n + i - 1;
        matrix[pos] = val;
    }
    else if (i - j == 0)
    {
        int pos = n - 1 + i - 1;
        matrix[pos] = val;
    }
    else if (i- j == 1)
        matrix[i - 1] = val;
}

int get(int *matrix, int i, int j)//get value at index from matrix
{
    if (i - j == -1)
    return matrix[2 * n + i - 1];

    else if (i - j == 0)
        return matrix[n - 1 + i - 1];

    else if (i- j == 1)
        return matrix[i - 1];
    
    return 0;
}