/*

Refer: Abdul BAri DS

In Insertion Sort, we assume that the first element of list is already sorted.
Then we take the next element and compare it with all the previous elements before it.
So let x be element to be inserted and i be the element being compared to.
Shift all elements greater than x and when we reach 0 or find an element greater
than x, insert x.

*/

#include <stdio.h>
#define SIZE 5

int main()
{
    int arr[SIZE] = {5,45,78,12,32};

    printf("\nUnsorted List:");
    print_list(arr);

    insertion_sort(arr);

    printf("\nSorted List:");
    print_list(arr);

    return 0;
}

void print_list(int *a)
{
    printf("\nList is:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n");
}

void insertion_sort(int arr[])
{
    for (int i = 1; i < SIZE; i++)
    {
        int j = i - 1, x = arr[i];

        while (j >= 0 && arr[j] > x)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}