/*

Refer: Abdul Bari DS

*/

#include<stdio.h>
#define SIZE 8

int main()
{
    char s1[SIZE] = "decimal";
    char s2[SIZE] = "medical";

    int HT[26];
    for(int i=0;i<26;i++)
        HT[i] = 0;

    for(int i=0;s1[i] != '\0';i++)
        HT[s1[i]-97]++;


    int j=0;
    for(j=0;s2[j] != '\0';j++)
    {
        HT[s2[j]-97]--;
        if(HT[s2[j]-97] == -1)
        {
            printf("\nNot Anagram\n");
            break;
        }
    }
    
    if(s2[j] == '\0')
        printf("\nAnagram\n");

    return 0;
}