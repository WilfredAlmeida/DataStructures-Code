/*

Refer: Abdul Bari DS

Same as Find Duplicates in Single Case String using Hash Table.c, 
only converting uppercase to lowercase and counting.

*/

#include <stdio.h>
#define SIZE 8

int main()
{

    char s[SIZE] = "Jassjca";

    int HT[26];
    for (int i = 0; i < (int)(sizeof(HT) / sizeof(HT[0])); i++)
        HT[i] = 0;

    int j = 0;
    while (s[j] != '\0')
    {

        if (s[j] >= 65 && s[j] <= 90) //converting uppercase to lowercase and counting
        {
            int l = s[j] + 7 + 25;
            HT[l - 97]++;
        }
        else
            HT[s[j] - 97]++;

        j++;
    }

    printf("\nDuplicates are:\n");

    for (int i = 0; i < 26; i++)
    {
        if (HT[i] > 1)
            printf("\n%c or %c is %d times", i + 65, i + 97, HT[i]);
    }

    return 0;
}