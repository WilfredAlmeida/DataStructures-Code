/*

Refer: Abdul Bari DS

Complete Binary Tree: Binary tree when represented in an array should not contain
                      any blank spaces. Nodes are represented in the array level-by-
                      level, and if for any level there is no node than a blank space
                      is left in the array. For eg: A binary tree at level 2 will
                      have at max 4 nodes but has 3.

Heap: A Heap is a complete binary tree and:
      1. Every node should be greater than or equal than its descendents. -> Max Heap
      2. Every node should be less than or equal than its descendents. -> Min Heap

Operations Performed:
1. Creation
2. Insertion
3. Deletion -> Only root can be deleted
5. Traversal

*/

#include <stdio.h>
#define SIZE 10

void insert_into_heap(int *H,int n);
int delete_from_heap(H, i);

int main()
{

    int H[] = {0, 10, 20, 30, 25, 5, 40, 35, 654, 15};
    // 40,25,35,10,5,20,30 -> Formed Heap
    //Heap is created from index 1, index 0 is blank, ignore it.

    for (int i = 2; i <= 7; i++)
        insert_into_heap(H, i);

    printf("\nDeleted Value is: %d",delete_from_heap(H,6));

    printf("\n");

    for (int i = 1; i <= 7; i++)
        printf("%d ", H[i]);

    printf("\n");

    return 0;
}

void insert_into_heap(int *H,int n)
{
    int temp = H[n], i = n;

    while(i > 1 && temp > H[i/2])
    {
        H[i] = H[i/2];
        i = i/2;
    }

    H[i] = temp;
}

int delete_from_heap(int *H,int n)
{
    int i = 1, j = i*2;
    int val = H[1];
    H[1] = H[n];
    H[n] = val;
    while(j < n-1)
    {
        if(H[j] < H[j+1])
            j = j+1;

        if(H[i] > H[j])
        {
            int t = H[i];
            H[i] = H[j];
            H[j] = t;

            i = j;
            j = j*2;
        }
        else
            break;
    }
    return val;
}