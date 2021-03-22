/*

Refer: Java Apni Kaksha Video 31.30 for algo explaination

Question: Given an array, find two numbers whose sum is 'x'.

One way to solve this is let 2 pointers i = a[0] & j = a[1]. Check a[i]+a[j] via nested for loops. This takes O(n^2) time.

Using 2 pointers Algo:
    Sort the array. Take i = a[0] & j = a[length-1] and check a[i]+a[j]. If obtained sum is less than required sum, increment i and if obtained sum is greater than required sum, decrement j until i<j.

*/

#include<stdio.h>

int main()
{
    //For our case, we are taking presorted array.

    int a[] = {1,2,3,4,5}, required_sum = 7, i=0;

    int j = ((int) sizeof(a)/sizeof(a[0])) - 1;

    while(i<j)
    {
        if(a[i] + a[j] == required_sum)
        {
            printf("Two numbers are: %d, %d",a[i],a[j]);
            break;
        }
        else if((a[i] + a[j]) < required_sum)
            ++i;
        else if((a[i] + a[j]) > required_sum)
            --j;
    }

    return 0;
}