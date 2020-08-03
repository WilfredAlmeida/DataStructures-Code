/*

Refer: Abdul Bari DS

Algo:
1. Find the minimum value in the list
2. Swap it with the value in the current position
3. Repeat this process for all the elements until the entire array is sorted

*/

#include <stdio.h>
#define size 5
int main()
{
    
    int arr[size] = {5,4,3,2,1};

    printf("\nUnsorted List:");
    print_list(arr);

    selection_sort(arr);

    printf("\nSorted ListL");
    print_list(arr);
    
    return 0;
}

void print_list(int arr[])
{
    printf("\n");
    for(int i=0;i<size;i++)
        printf(" %d ",arr[i]);
}

void selection_sort(int arr[])
{
    int i,j,k;

    for(i=0;i<size;i++)
    {
        for(j=k=i;j<size;j++)
        {
            if(arr[j] < arr[i])
                k = j;
        }
        int t = arr[i];
        arr[i] = arr[k];
        arr[k] = t;
    }
}