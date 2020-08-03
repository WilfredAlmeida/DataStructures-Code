/*

Check if an entered string has anything other than characters.

Solution: Check if ASCII codes lie in required range

*/

#include <stdbool.h>
#define SIZE 6

int main()
{
    char str[] = "9ello";

    printf("\nString Valid: %d", validate(str));

    return 0;
}
int validate(char str[])
{
    for (int i = 0; i <= SIZE - 2; i++)
    {
        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >=97 && str[i] <=122))
            continue;
        else
            return 0;
    }
    return 1;
}