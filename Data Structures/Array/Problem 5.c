/*

Given an array (or string), the task is to reverse the array/string.

Question Source: Geeks For Geeks

*/
#include<stdio.h>
#define SIZE 7

int main()
{

    char array[SIZE] = {1,2,3,4,5,6,7};

    int temp[SIZE];

    int a=SIZE-1;
    int b=0;

    for(int i=SIZE-1;i>=0;i--)
    {
        temp[b] = array[a];
        a--;
        b++;
    }

    for(int k=0;k<SIZE;k++)
    {
        printf(" %d ",array[k]);
    }

    printf("\n");

    for(int k=0;k<SIZE;k++)
    {
        printf(" %d ",temp[k]);
    }

    return 0;
}
