//Nothing to comment here, know the algorithm and thats all whats coded here :):)

#include<stdbool.h>
#include<stdio.h>

#define SIZE 5

bool search(int arr[], int val);
bool binary_search(int arr[], int val, int low, int mid, int high);

int main()
{
    int arr[SIZE] = {1,2,3,4,5};

    int val;

    printf("\nEnter Value to be searched\n");
    scanf("%d",&val);

    if(search(arr,val))
        printf("\nElement found\n");
    else 
        printf("\nElement not found\n");
    
    return 0;
}

bool search(int arr[], int val)
{
    int low = 0;
    int high = SIZE-1;
    int mid = (low+high)/2;

    return binary_search(arr,val,low,mid,high);
}

bool binary_search(int arr[], int val, int low, int mid, int high)
{
    if(arr[mid] == val)
        return true;
    
    else if(val > arr[mid] && low < high)
    {
        low = mid+1;
        mid = (low+high)/2;
        return binary_search(arr,val,low,mid,high);
    }

    else if(val < arr[mid] && low < high)
    {
        high = mid-1;
        mid = (low+high)/2;
        return binary_search(arr,val,low,mid,high);
    }

    return false;
}