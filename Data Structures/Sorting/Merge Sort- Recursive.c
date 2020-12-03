/*

Refer: Abdul Bari DS

*/

#include <stdio.h>

void print_array(int *a, int n);
void merge_sort(int *a, int l, int h);
void merge(int *a, int l, int m, int h);

int main()
{
                    
    int arr[] = {6, 5, 4, 3, 2, 1};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    printf("\nUnsorted Array:");
    print_array(arr, n);

    merge_sort(arr, 0, n - 1);

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

void merge_sort(int *a, int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;

        merge_sort(a, l, mid);
        merge_sort(a, mid + 1, h);
        merge(a, l, mid, h);
    }
}

void merge(int *a, int l, int m, int h)
{
    int i = l, j = m+1, k = l;

    int aux[100];

    while (i <=m  && j <= h)
    {
        if (a[i] < a[j])
            aux[k++] = a[i++];
        else
            aux[k++] = a[j++];
    }

    for (; i <= m; i++)
        aux[k++] = a[i];

    for (; j <= h; j++)
        aux[k++] = a[j];

    for (int x = l; x <= h; x++)
        a[x] = aux[x];
}