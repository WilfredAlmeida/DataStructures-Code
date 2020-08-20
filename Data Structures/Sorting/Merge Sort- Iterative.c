/*

Refer: Abdul Bari DS for explaination, code from GFG

*/

#include <stdio.h>

void print_array(int arr[], int n);
void merge_sort(int arr, int n);
void merge(int arr[], int l, int m, int h);
void swap(int *a, int *b);

int main()
{
    int arr[] = {100, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    printf("\nUnsorted List:\n");
    print_array(arr, n);

    merge_sort(arr, n);

    printf("\nSorted List:\n");
    print_array(arr, n);

    return 0;
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf(" %d ", arr[i]);
}

void merge_sort(int arr, int n)
{
    for (int i = 1; i <= n - 1; i *= 2)
    {
        for (int j = 0; j < n - i; j += i * 2)
        {
            int l = j;
            int m = min(j + i - 1, n - 1);
            int h = min(l + i + i - 1, n - 1);
            merge(arr, l, m, h);
        }
    }
}

void merge(int arr[], int l, int m, int h)
{
    int i = l, j = m + 1, k = l;

    int b[100];

    while (i <= m && j <= h)
    {
        if (arr[i] < arr[j])
            b[k++] = arr[i++];
        else
            b[k++] = arr[j++];
    }

    for (; i <= m; i++)
        b[k++] = arr[i];

    for (; j <= h; j++)
        b[k++] = arr[j];

    for (int x = l; x <= h; x++)
        arr[x] = b[x];
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}