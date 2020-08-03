//Bubble Sort

#include <stdio.h>
#define SIZE 5

int main()
{
    int a[SIZE] = {5, 4, 3, 2, 1};

    printf("\nUnsorted List:\n");

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d  ", a[i]);
    }

    for (int i = 0; i < SIZE-1; i++)
    {
        for (int j = 0; j < SIZE-1-i; j++)
        {
            if (a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    printf("\nSorted List:\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d  ", a[i]);
    }

    return 0;
}
