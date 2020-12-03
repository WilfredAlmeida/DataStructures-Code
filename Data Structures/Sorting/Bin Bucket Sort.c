/*

Refer: Abdul Bari DS


1) Create n empty buckets (Or lists).

2) Do following for every array element arr[i].
    a)Perform sorted insert for arr[i] into bucket[n*arr[i]]. This formula
  decides memory consumption of the program and needs to be adjusted as per size of
  input. This formula works for decimal values btwn 0.0 to 1.0. We are doing it based
  on first digit of the number.

3) Sort individual buckets using insertion sort.

4) Concatenate all sorted buckets.

So radix sort and bucket sort are the same, radix sort is improvised version of
Bucket Sort and what we have done in this code is inbetween both. Watch Abdul's
video and you'll understand.

*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 12

struct Node
{
    int data;
    struct Node *next;
};

void print_array(int *a, int n);
void bin_bucket_sort(int *a, int n);
void insert(struct Node **bucket, int n);

int main()
{
    int arr[SIZE] = {11,45,78,32,799,451,787,3365,4758,5524,1212,669};

    printf("\nUnsorted Array:");
    print_array(arr, SIZE);

    bin_bucket_sort(arr, SIZE);

    printf("\nSorted Array:");
    print_array(arr, SIZE);
}

void print_array(int *a, int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
}

void bin_bucket_sort(int *a, int n)
{
    struct Node *buckets[SIZE + 1] = {NULL};//bucket

    int t = 0;//varialbe used while copying sorted array into orignal array

    for (int j = 0; j < n; j++)
    {
        int index_at_which_to_insert = (a[j]/1000)%10;//insertion index of bucket
        //and formula mentioned above

        insert(&buckets[index_at_which_to_insert], a[j]);
    }

    for (int k = 0; k < SIZE+1; k++)//copying sorted array values to orignal array
    {
        if (buckets[k] != NULL)
        {
            struct Node *p = buckets[k];
            while (p != NULL)
            {
                a[t++] = p->data;
                p = p->next;
            }
        }
    }
}

void insert(struct Node **bucket, int n)//insert values into bucket
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = n;
    t->next = NULL;

    struct Node *p = *bucket;
    struct Node *q = NULL;

    if (*bucket == NULL)
        *bucket = t;
    else
    {
        while (p != NULL && t->data > p->data)
        {
            q = p;
            p = p->next;
        }

        if (p == *bucket)
        {
            t->next = *bucket;
            *bucket = t;
        }
        else
        {
            t->next = p;
            q->next = t;
        }
    }
}