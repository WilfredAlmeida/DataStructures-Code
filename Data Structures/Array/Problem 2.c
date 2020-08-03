/*

Given an array, only rotation operation is allowed on array.
We can rotate the array as many times as we want. Return the maximum possible of summation of i*arr[i].

*/

#include<stdio.h>
#define SIZE 10

int array[SIZE] = {10,1,2,3,4,5,6,7,8,9};

int main()
{
    int array2[SIZE], top=0;

    int sum=0, max=0;


    for(int a=0;a<SIZE;a++)
    {
        for(int i=0;i<SIZE;i++)
        {
            sum = sum + (array[i]*i);
        }

        array2[top] = sum;
        top++;
        rotate();
        sum=0;
    }

    for(int i=0;i<SIZE;i++)
    {
        if(array2[i] > max)
            max = array2[i];
    }

    printf("\nMax sum is:\n%d",max);

    return 0;
}

void rotate()
{
    int temp = array[0];

    for(int i=0;i<SIZE;i++)
    {
        array[i] = array[i+1];
    }

    array[SIZE-1] = temp;
}
