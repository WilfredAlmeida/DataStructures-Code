/*

Binary Search Algorithm: Read it and you'll understand :)

1. Take 3 variables, " 'low', initial value = 0(index of first element)",
   " 'high', initial value = index of last element ",
   " 'mid', value = (low+high)/2 ".
2. If mid.value == required value exit.
3. If required value > mid, low = mid+1.
4. If required value < mid, high = mid-1.

*/

#include <stdio.h>
#include<stdbool.h>
#define SIZE 6

bool binary_search(int arr[], int val);

int main()
{
    int arr[SIZE] = {1, 2, 3, 4, 5, 6};

    int val;

    printf("\nEnter value to be searched:\n");
    scanf("%d", &val);

    if (binary_search(arr, val))
        printf("\nElement found\n");

    else
        printf("\nElement not found\n");

    return 0;
}

bool binary_search(int arr[], int val)
{
    int low = 0, high = SIZE-1;
    int mid = (low+high)/2;

    while(low < high)
    {
        int mid = (low+high)/2;

        if(arr[mid] == val)
            return true;
        else if(val > arr[mid])
            low = mid+1;
        else if(val < arr[mid])
            high = mid-1;
    }

    return false;
}