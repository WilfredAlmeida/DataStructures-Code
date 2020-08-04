/*

Refer: Abdul Bari DS

*/

#include<stdio.h>
#define SIZE 15

void permute(char *s, int k)
{
    static char res[SIZE] = {NULL};
    static int a[SIZE] = {0};

    if(s[k] == '\0')
    {
        res[k] = '\0';
        printf("\n%s",res);
    }
    else
    {
        int i;
        for(i=0;s[i] != '\0';i++)
        {
            if(a[i] == 0)
            {
                res[k] = s[i];
                a[i] = 1;
                permute(s,k+1);
                a[i]=0;
            }
        }
    }
    
}


int main()
{
    char str[SIZE] = "WilfredWilfred";
    permute(str,0);
    
    return 0;
}