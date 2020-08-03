/*

Consider an array of distinct numbers sorted in increasing order. The array has been rotated (clockwise) k number of times.
Given such an array, find the value of k.

Question Source: GeeksForGeeks

*/

/*

Solution:
1. As array is sorted, smallest element will be at index 0.
2. Array is right rotated, so if rotated once the last element will be at index 0 and all other elements will move one step
   right.
3. Smallest element will be at index 1.
4. So here the index of smallest element is the number of times array is rotated.
5. So we first find the smallest element in array and then find its index and we have our answer.

*/

#include<stdio.h>
#define SIZE 5

int main()
{

    int array[SIZE] = {15,18,2,3,5,12};
    int k=0;
    int min;

    for(int i=0;i<SIZE;i++)
    {
        if(min > array[i])
        {
            min = array[i];
        }
    }

    for(int i=0;i<SIZE;i++)
    {
        if(array[i] == min)
            k=i;
    }

    printf("\nRotation Count:\n%d\n",k);

    return 0;
}
