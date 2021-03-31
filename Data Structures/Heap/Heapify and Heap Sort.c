/*

Refer: Abdul Bari Algo Analysis video 2.6.3, code self written.

Complete Binary Tree: Binary tree when represented in an array should not contain
                      any blank spaces. Nodes are represented in the array level-by-
                      level, and if for any level there is no node than a blank space
                      is left in the array. For eg: A binary tree at level 2 will
                      have at max 4 nodes but has 3.

Heap: A Heap is a complete binary tree and:
      1. Every node should be greater than or equal than its descendents. -> Max Heap
      2. Every node should be less than or equal than its descendents. -> Min Heap

In a Complete Binary Tree, formulas are, for array beginning from index 0:

Leaf nodes are from { floor( n/2 ) to (n-1) } where n is number of nodes.
Left Child of a node is: (2 * i) + 1 where i is index of current node
Right Child of a node is: (2 * i) + 2 where i is index of current node.

In heapify, we check each subtree for above written 2 heap properties. For that, we take a node, check if it's greater/smaller than its children and if not, we swap the 2 nodes to make the greater/smaller node as parent. Now, since leaf nodes are not needed to be checked for this, we check only non-leaf nodes. As we know, in Complete Binary Tree, represented in array, leaf nodes are from {(n/2) to (n-1)}, it means non leaf nodes are from 0 to (n/2)-1.

So now, we always go in reverse order for heapifying tree, meaning, we'll first heapify the last non-leaf node which is found at (n/2)-1 and we'll go from there to 0 and boom, we'll have satisfied the 2 heap properties in respective case. This is done in below code at marker -->(1)


Heapsort:
Heap rule says we can delete only root element. So we delete that and to replace it, we need the next greatest/smallest element in tree now. For that, we'll first replace it with the last element in tree, which would also be last element in array and then adjust the tree. For adjusting, we'll find the biggest element among the children of root and swap and repeat this till we reach last non leaf node which will be the last subtree in the heap as after it, all will be leaf nodes.

Now, as we deleted root element and replaced it with last element in array, there's an empty space in the array so keep the deleted element there and perform this deletion operation for all items and boom, we have a soreted array. :)

*/

#include<stdio.h>

void heapify(int *heap, int n, int i);
void swap(int *a, int *b);
void print_heap(int *heap, int n);

//Last index of complete binary tree in array, after it, there will be empty spaces as we'll delete root and replace it with last element, required for sorting.
int last_index;

int main()
{
    int heap[] = {5,4,3,2,1};
    int n = (int) sizeof(heap)/sizeof(heap[0]);
    last_index = n-1;

    for(int i = (n/2)-1 ;i>=0;i--)//---------------------->(1)
    {
        heapify(heap,n,i);
    }
    
    printf("Before Sorting, Heapified:");
    print_heap(heap,n);

    heap_sort(heap,n);

    printf("\nAfter Sorting:");
    print_heap(heap,n);
    
    return 0;
}

void heapify(int *heap, int n, int i)
{
    //Find indexes of left and right children from formulas
    int left = (2*i) + 1;
    int right = (2*i) + 2;

    //We need to find largest among children, so we'll find its index, so we first consider parent as largest and change it below as per conditions.
    int largest = i;

    //If the calculated left index is within heap's indexes and the value there is greater than current largest then make largest index as left index
    if(left <= n && heap[left] > heap[largest])
        largest = left;
    
    //If the calculated right index is within heap's indexes and the value there is greater than current largest then make largest index as right index
    if(right <= n && heap[right] > heap[largest])
        largest = right;

    //if largest index is changed, swap the elements and obtain the heap property.
    if(i != largest)
        swap(&heap[i],&heap[largest]);
}

void heap_sort(int *H, int n)
{   
    for(int j=0;j<n;j++)//Loop for all elements in array
    {
        int t = H[0];//Delete root value
            
        H[0] = H[last_index];//Put last valeue in array as root.

        H[last_index--] = t;//Since last index is freed, keep deleted value there.

        int i = 0;//Index variable, we need it point to indexes as we go for navigation

        while(i < n/2)//As explained above, we adjust tree till we  reach last non-leaf element
        {
            int left = (2*i) + 1;//Left child of current node
            int right = (2*i) + 2;//Right child of current node

            int largest = i;//Make current non-leaf node as largest and change it below as per conditions

            //If the calculated left index is within heap's indexes and the value there is greater than current largest then make largest index as left index
            if(left <= last_index && H[left] > H[largest])
                largest = left;

            //If the calculated left index is within heap's indexes and the value there is greater than current largest then make largest index as left index
            if(right <= last_index && H[right] > H[largest])
                largest = right;

            //if largest index is changed, swap the elements and obtain the heap property.
            if(i != largest)
                swap(&H[i],&H[largest]);
            else//When we reach the ideal spot when heap conditions are satisfied, values of i and largest will be same, in such a situation, break out of loop
                break;

            //Now that if we have swapped elements, we need to go further in the tree and adjust stuff, for this, since we disrpted the tree where element at index 'largest' was parent, we need to adjust that subtree, so make our navigation index i point to the root of disrupted subtree and adjust.
            i = largest;
        }

    }
}


//Funcions to swap and print
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void print_heap(int *heap, int n)
{
    printf("\n");
    for(int i=0;i<n;i++)
        printf(" %d ",heap[i]);
}