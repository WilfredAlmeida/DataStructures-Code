/*
Given an array that is sorted and then rotated around an unknown point.
Find if the array has a pair with a given sum ‘x’. It may be assumed that all elements in the array are distinct.

Question Source: GeeksForGeeks
*/

/*

Solution:

1. Take an element from array
2. Compare it with all elements after it and check if their sum is what is wanted
3. Do it for all elements

*/

#include<stdio.h>
#define SIZE 6

int main()
{

    int array[SIZE] = {11, 15, 6, 8, 9, 10};
    int x, found = 0;

    printf("\nEnter sum to search:\n");
    scanf("%d",&x);

    for(int i=0;i<SIZE;i++)
    {
        for(int j=i+1;j<SIZE;j++)
        {
            if(array[i] + array[j] == x)
            {
                printf("\nPair with sum %d is (%d,%d)",x,array[i],array[j]);
                found++;
            }
        }
    }

    if(found == 0)
    {
        printf("\nNot Found\n");
    }

    return 0;
}
