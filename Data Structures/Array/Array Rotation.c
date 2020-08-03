//Write a function rotate(arr[], d, n) that rotates array arr[] of size n by d elements.

#include<stdio.h>
#define SIZE 5

int main()
{

    int array[SIZE] = {1,2,3,4,5};
    int n;

    printf("\nOrignal Array:\n");

    for(int i=0;i<SIZE;i++)
    {
        printf(" %d ",array[i]);
    }

    printf("\nEnter number of elements to rotate:\n");
    scanf("%d",&n);

    rotate(array,SIZE,n);

    printf("\nRotated Array:\n");

    for(int i=0;i<SIZE;i++)
    {
        printf(" %d ",array[i]);
    }

    return 0;
}
void rotate(int arr[],int d, int n)
{
    for(int j=0;j<n;j++)
    {
        int temp = arr[0];

        for(int i=0;i<d;i++)
        {
            arr[i] = arr[i+1];
        }

        arr[d-1] = temp;
    }
}
