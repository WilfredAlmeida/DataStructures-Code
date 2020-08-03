/*

Given an array with negative and positive values at random positions, rearrange the
array such that all negative numbers are towards the left of all positive numbers

Example:
Given Array: {-4,2,-5,1,6,3,-9,-7}
Output: {-4,-5,-9,-7,2,1,6,3}

*/

#include <stdio.h>
#define SIZE 8

int main()
{
    int arr[8] = {-4, 2, -5, 1, 6, 3, -9, -7};

    print_array(arr);

    int i = 0, j = SIZE - 1;

    while(i < j)
    {
        while(arr[i] < 0)
            i++;
        while (arr[j] >0)
            j--;

        if(i<j)
            swap(&arr[i],&arr[j]);
    }

    print_array(arr);
}

void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void print_array(int arr[])
{
    printf("\n");
    for(int i=0;i<SIZE;i++)
    {
        printf(" %d ",arr[i]);
    }
}