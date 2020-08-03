/*

Given an array of elements of length N, ranging from 0 to N – 1. All elements may not be present in the array.
If element is not present then there will be -1 present in the array.
Rearrange the array such that A[i] = i and if i is not present, display -1 at that place.

*/

/*

Solution:
We copy existing array and search in that array if 'i' is present and if yes than we A[i]=i else A[i]=-1

*/

#include<stdio.h>
#define SIZE 10

int main()
{
    int array[SIZE] = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};//orignal array
    int temp[SIZE];

    for(int i=0;i<SIZE;i++)//array copy
        temp[i] = array[i];

    for(int i=0;i<SIZE;i++)
    {
        if(present(temp,i))//check if 'i' is present in array
            array[i] = i;
        else
            array[i] = -1;
    }

    for(int i=0;i<SIZE;i++)//printing
    {
        printf(" %d ",array[i]);
    }
    return 0;
}

int present(int arr[],int a)
{
    for(int i=0;i<SIZE;i++)//linear search to search 'i' in array
         if(arr[i] == a)
             return 1;

    return 0;
}
