//Reverse Array Elements

#include<stdio.h>
#define SIZE 7

int main()
{
    int a[SIZE] = {1,2,3,4,5,6,7};

    printf("\nOrignal is:\n");

    for(int i=0;i<SIZE;i++)
    {
        printf("%d ",a[i]);
    }

    //Reversing logic: We will swap the first and last element. 'i' indicates first element and 'j' indicates last element

    int i = 0;
    int j = SIZE-1;

    while(i < j)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        i++;
        j--;
    }

    printf("\nReversed Array is:\n");

    for(int i=0;i<SIZE;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
