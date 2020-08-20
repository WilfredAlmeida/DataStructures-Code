/*

Refer: Abdul Bari DS

*/

#include <stdio.h>

void print_array(int arr[], int n);
void merge_sort(int arr, int n);
void merge(int arr[], int l, int m, int h);
void swap(int *a, int *b);

int main()
{
    int arr[] = {8, 7, 6, 5, 4, 3, 2, 1};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    printf("\nUnsorted List:\n");
    print_array(arr, n);

    merge_sort(arr, n);

    printf("\nSorted List\n");
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
    int l = 0, m = 0, h = 0, p = 0;

    for (p = 2; p <= n; p = p * 2)
    {
        for (int i = 0; i + p - 1 <= n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            m = (l + h) / 2;

            merge(arr, l, m, h);
        }
    }
    if (p / 2 < n)
        merge(arr, 0, p / 2 - 1, n);
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
    return (a>b)?a:b;
}