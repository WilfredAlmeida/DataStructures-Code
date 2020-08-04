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
                a = a + 7 + 25;//Uppercase ASCII end at 90, and uppercase beigin at 97
                //conversison idea is converting ASCII codes. So 7 is filling gap from
                //90 to 97. Adding 25 then gives exact reverse case of a letter.
            else
                a = a - 7 - 25;

            str[i] = a;
        }
    }

    printf("\n%s",str);

    return 0;
}