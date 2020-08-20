/*

Refer: Abdul Bari DS Sorting videos 19-20

Scroll for detailed explaination ;)
*/

#include <stdio.h>

void print_array(int *a,size_t s);
int *merge_arrays(int *a,size_t a_size, int *b, size_t b_size);

int main()
{
    int a1[] = {1, 3, 5, 7, 9};
    size_t a1_size = sizeof(a1) / sizeof(a1[0]);//Size of array calculated using sizeof
    //needs to be stored in variable of type size_t.
    //Can't calculate size when array is received in a function as a parameter

    int a2[] = {2, 4, 6, 8, 15};
    size_t a2_size = sizeof(a2) / sizeof(a2[0]);

    printf("\nArray 1:");
    print_array(a1, a1_size);

    printf("\nArray 2:");
    print_array(a2, a2_size);

    int *a3 = merge_arrays(a1, a1_size, a2, a2_size);

    printf("\nMerged Array:");
    print_array(a3,a1_size+a2_size);

    return 0;
}

void print_array(int *a,size_t s)
{
    printf("\n");
    for (int i = 0; i < s; i++)
        printf(" %d ", a[i]);
}

int c[100];//taken global cuz if created in function and returned than would get
//destroyed when function ends.

int *merge_arrays(int *a,size_t a_size, int *b, size_t b_size)
{
    /*
    Idea of merging is that take 'i','j' pointing to initial index of arrays to be merged
    'a','b' here. Take k pointing to initial index of auxillary array 'c' here.

    Compare a[i] and b[j] and whichever is smaller, put it in c[k], increment 'k'
    and either 'i' or 'j' whichever was index of the smaller element.

    Repeat this until any one array 'a', 'b' finishes. After that copy remaining
    elements from the other array into 'c'. Done :)
    */

    int i = 0, k = 0, j = 0;
    size_t m = a_size;
    size_t n = b_size;

    while (i < m && j < n)
    {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    for(;i<m;i++)//if one list gets over than putting elements of other list into
    //combined list.
        c[k++] = a[i];
    
    for(;j<n;j++)
        c[k++] = b[j];

    return c;
}