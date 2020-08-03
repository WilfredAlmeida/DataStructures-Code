/*

Pattern to be printed:

*****
** **
* * *
** **
*****


*/
#include<stdio.h>

int main()
{

    int n;
    printf("\nEnter number of rows to print\n");
    scanf("%d",&n);

    int pos = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==1 || j==1 || i==n || j==n || i==j || j==(n-i+1))
            {
                printf("*");
            }
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
