/*

Change case of String

Solu

*/

#include <stdio.h>
#define SIZE 5

int main()
{
    char str[] = "HeLlO";

    printf("\n%s", str);

    for (int i = 0; i < SIZE; i++)
    {
        int a = str[i];

        if (a >= 65 && a <= 122)
        {
            if (a < 96)
                a = a + 7 + 25;
            else
                a = a - 7 - 25;

            str[i] = a;
        }
    }

    printf("\n%s",str);

    return 0;
}