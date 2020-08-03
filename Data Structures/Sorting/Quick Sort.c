/*

Refer: Abdul Bari DS

Algo:

1) If there are one or no elements in the array to be sorted, return.

2) Pick an element in the array to serve as the “pivot” point. (Usually the
   leftmost element in the array is used.)

3) Split the array into two parts – one with elements larger than the pivot
   and the other with elements smaller than the pivot.

4) Recursively repeat the algorithm for both halves of the original array.


*/

#include <stdio.h>
#define SIZE 6

void display_list(int *a);
void quick_sort(int *a, int l, int h);
int partition(int *a, int l, int h);
void swap(int *a, int *b);

int main()
{
    int arr[SIZE] = {48,78,3,45,35, __INT32_MAX__};

    printf("\nUnsorted List:");
    display_list(arr);

    quick_sort(arr, 0, SIZE - 1);

    printf("\nSorted List:");
    display_list(arr);

    return 0;
}

void display_list(int *a)
{
    printf("\n");
    for (int i = 0; i < SIZE-1; i++)
        printf(" %d ", a[i]);
}

void quick_sort(int *a, int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(a, l, h);
        quick_sort(a, l, j);
        quick_sort(a, j + 1, h);
    }
}

int partition(int *a, int l, int h)
{
    int pivot = a[l];
    int i = l, j = h;

    do
    {
        do{i++;}while(a[i] <= pivot);
        do{j--;}while(a[j] > pivot);

        if(i < j)
            swap(&a[i],&a[j]);

    }while(i<j);

    swap(&a[l],&a[j]);

    return j;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a=*b;
    *b=t;
}