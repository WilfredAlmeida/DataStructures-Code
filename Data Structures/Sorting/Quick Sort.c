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

void quick_sort(int *a, int l, int h)//Array to be sorted, lower & upper bounds of
//array
{
    //Idea here is take the first element as pivot, partition the list such that
    //elements smaller than pivot are to its less and elements greater than pivot
    //are to its right. We now have the pivot element at its appropriate place.
    //Then repeat the same for elements to its left and to its left
    
    int j;//The pivot element

    if (l < h)//There are at least 2 elements in the list
    {
        j = partition(a, l, h);//partition the list around pivot, pivot will
        //be taken element at index 'l'. Function will return index of pivot, use
        //to sort left and right sides

        quick_sort(a, l, j);//Sorting left side

        quick_sort(a, j + 1, h);//Sorting right side
    }
}

int partition(int *a, int l, int h)
{
    int pivot = a[l];//Element around which list will be partitioned

    int i = l, j = h;

    //Idea here is, take 2 pointers(logical not programatical) at index of pivot or
    //after pivot, 'i' here and one at end of list 'j' here. Increment 'i' until
    //an element greater than pivot is found and decrement 'j' until an element
    //greater than pivot is found. Swap elements at indexes 'i', 'j'.
    //Repeat this until i>j, i.e. whole list is traversed.
    //Now swap pivot and element at index 'j' and boom, we have piviot at its place.
    //Return piviot's position :)

    do
    {
        do{i++;}while(a[i] <= pivot);//Increment 'i' until greater element is found
        do{j--;}while(a[j] > pivot);//Decrement 'j' until smaller element is found

        if(i < j)//Check if we haven't finished checking the whole list cuz when we do
        //'i' will be greater than 'j'.
            swap(&a[i],&a[j]);//Swap elements at indexes 'i' and 'j'

    }while(i<j);//Repeat until whole list is visited

    swap(&a[l],&a[j]);//Swap element at 'j' and piviot for boom(piviot at its place)

    return j;//return piviot's index.
}

void swap(int *a, int *b)//Swapping variables :)
{
    int t = *a;
    *a=*b;
    *b=t;
}