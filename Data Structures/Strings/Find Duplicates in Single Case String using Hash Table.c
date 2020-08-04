/*

Refer: Abdul Bari DS

Here we count occurance of each letter using its ASCII code.
Idea here is to take an array of size 26 that equals to number of alphabets.


*/

#include <stdio.h>
#define SIZE 8

int main()
{
    char s[SIZE] = "aabbcdc";

    int HT[26];

    for (int i = 0; i < (int)(sizeof(HT) / sizeof(HT[0])); i++)
        HT[i] = 0;

    int j = 0;

    while (s[j] != '\0')
    {
        HT[s[j] - 97]++;//Change 97 to 65 for Uppercase
        j++;
    }

    printf("\nDuplicate Elements are:\n");

    for (int i = 0; i < 26; i++)
        if (HT[i] > 1)
            printf("\n%c is %d times\n", i+97, HT[i]);//Change 97 to 65 for Uppercase
}