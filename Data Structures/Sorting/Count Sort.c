/*

Refer: Abdul Bari DS

Basically we are counting the occurance of every element and putting them in a sorted
order.

Idea here is take an array whose size is equal to the biggest element in the array
to be sorted and initialize its all values with 0.
Traverse the array to be sorted and for every element increment the value at that 
index in the other array.
For the other array, if its element is >0 copy the index of that element in the array
to be sorted.

*/

#include <stdio.h>
#include <stdlib.h>

void print_array(int *a, int n);
int find_max(int *a,int n);
void count_sort(int *a, int n);

int main()
{

    int arr[] = {6, 5, 4, 3, 2, 1,6};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    printf("\nUnsorted Array:");
    print_array(arr, n);

    count_sort(arr,n);

    printf("\nSorted Array:");
    print_array(arr, n);

    return 0;

}

void print_array(int *a, int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
        printf(" %d ", a[i]);
}

int find_max(int *a,int n)
{
    int max = a[0];
    for(int i=1;i<n;i++)
        if(a[i] > max)
            max = a[i];
    
    return max;
}

void count_sort(int *a, int n)
{
    int max = find_max(a,n), i=0,j=0;

    int *aux = (int*) malloc(sizeof(a)+1);//auxillary array of highest indez equal to
    //max element of array to be sorted

    for(int i=0;i<=max;i++)//initializing auxillary array
        aux[i] = 0;

    for(int i=0;i<n;i++)//incrementing indexes which are elements in array to be sorted
        aux[a[i]]++;

    while(i <= max)//copying sorted elements to orignal array.
    {
        if(aux[i] > 0)
        {
            a[j++] = i;
            aux[i]--;
        }
        else
            i++;
    }

}