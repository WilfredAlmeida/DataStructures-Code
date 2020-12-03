#include<stdio.h>

int main()
{
    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int i=0;
    int s = (sizeof(arr)/sizeof(int));
    int j=s-1;
    
    while(i<j)
    {
        while(arr[i]<0)
            i++;
        while(arr[j]>=0)
            j--;
        
        if(i<j){
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
        
    }
    
    for(int m=0;m<s;m++)
    {
        printf(" %d ",arr[i]);
    }
    
    return 0;
}