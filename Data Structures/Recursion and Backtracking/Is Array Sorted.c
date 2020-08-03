/*

Check array is sorted or not using recursion

*/

#include<stdio.h>
#include<stdbool.h>
#define SIZE 5


bool is_array_sorted(int array[], int n);

int main()
{

    int array[SIZE] = {1,2,3,4,5};

    printf("Array is Sorted: %d \n",is_array_sorted(array,SIZE)?true:false);

    return 0;
}

bool is_array_sorted(int array[], int n)
{
    if(n == 1)
        return true;

    return array[n-1] < array[n-2]? false : is_array_sorted(array, n-1);
    //understand this statement and you will understand the code
}
