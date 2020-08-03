/*

Reversing a String.

2 Ways toreverse a String:
1. Create an array same as size of orignal string, point i at last index of orignal
   string j at 0 of new array, loop and copy contents from i to j.

2. Point i at 0 of string and j at last index, swap i and j, increment i and 
   decrement j while i < j.

*/

#include <stdio.h>
#define SIZE 8
int main()
{
    char str[SIZE] = "Wilfred";

    printf("\nOrignal String: %s", str);

    reverse_method_1(str);

    printf("\nReversed using method 1: %s", str);

    reverse_method_2(str);

    printf("\nReversed using method 2: %s", str);
}

void reverse_method_1(char str[SIZE])
{
    char str2[SIZE];

    int i = 0, j = SIZE-2;

    for(int k=0;k<=SIZE-2;k++)
    {
        str2[i] = str[j];
        i++;
        j--;
    }

    for(int m=0;m<SIZE-1;m++)
    {
        str[m] = str2[m];
    }
}

void reverse_method_2(char str[SIZE])
{
    int i=0, j=SIZE-2;

    while(i<=j)
    {
        char t = str[i];
        str[i]=str[j];
        str[j]=t;
        i++;
        j--;
    }
}