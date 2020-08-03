/*

Kazama gave Shaun a string of even length, and asked him to swap the characters at the even
positions with the next character. Indexing starts at 0.

*/

/*

Solution:
1. Pass orignal string into recursive function which do permuting along with a position from where to
   start permuting.
2. The function will check if passed position is even or not and if even it will swap and move
   forward and if odd it will only move forward.

*/

#include <stdio.h>
#define SIZE 4

int main()
{
    char str[SIZE] = "abcd"; //string to be permuted

    printf("\nOrignal String\n");

    print_string(str);

    permute_string(str, 0); //call to recursive function that will permute string

    printf("\nPermutated String\n");
    print_string(str);

    return 0;
}

void print_string(char str[]) //will print the string
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%c", str[i]);
    }
}

void permute_string(char str[], int pos) //recursive function that will permute string
{
    if (pos > SIZE) //if position does not exist in string, return
        return;

    else
    {
        if (pos % 2 != 0) //check if position is even or odd
        {
            //if odd, move forward
            permute_string(str, pos + 1);
            return;
        }

        else
        {
            //if even swap and move forward
            char temp = str[pos];
            str[pos] = str[pos + 1];
            str[pos + 1] = temp;

            permute_string(str, pos + 1);
        }
    }
}