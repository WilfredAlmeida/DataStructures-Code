/*

Refer: Abdul Bari DS Sorting video 19

Merging Idea here is take a variable mid = (low(0) + high(size-1))/2, treat the list
as 2 separate lists from low to mid and mid+1 to high.Merge them.

'mid' is basically the last index where one list ends and after it, the other list
begins.

*/

#include <stdio.h>

void print_list(int *a, int n);
void merge_array(int *a, int l, int m, int h);

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    int l = 0, h = size - 1, mid = (l + h) / 2;

    printf("\nUnmerged List:");
    print_list(arr, size);

    merge_array(arr, l,mid,h);

    printf("\nMerged List:");
    print_list(arr, size);

    return 0;
}

void print_list(int *a, int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
        printf(" %d ", a[i]);
}


void merge_array(int *a, int l,int m,int h)//Read the code, you'll understand or
//read comments from "2-Way Merging.c" file or watch video.
{
    int i = l,j=m+1,k=0;
    int c[h+1];

    while(i<=m && j<=h)
    {
        if(a[i] < a[j])
            c[k++] = a[i++];
        else
            c[k++] = a[j++];
    }

    for(;i<=m;i++)
        c[k++] = a[i];
    
    for(;j<=h;j++)
        c[k++] = a[j];

    for(int x = 0;x<=h;x++)
        a[x] = c[x];
}