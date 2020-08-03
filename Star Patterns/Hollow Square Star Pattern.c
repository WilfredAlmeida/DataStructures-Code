/*

Pattern to be printed:

*****
*   *
*   *
*   *
*****

*/

#include<stdio.h>

int main()
{

    for(int i=0;i<=5;i++)
    {
        if(i == 0 || i == 5)
        {
            printf("\n");
            for(int j=0;j<5;j++)
                printf("*");
        }
        else
        {
            printf("\n");
            printf("*   *");
        }
    }

    return 0;
}
