/*

Fairly simple :)

*/

#include<stdio.h>

int main()
{
    int m1[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int m2[3][3] = {
        {9,8,7},
        {6,5,4},
        {3,2,1}
    };

    int r[3][3];

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            r[i][j] = 0;
            for(int k=0;k<3;k++)
            {
                r[i][j] += m1[i][k] *  m2[k][j];// Visualize this to understand.
            }
        }
    }

    for(int a=0;a<3;a++)
    {
        for(int b=0;b<3;b++)
        {
            printf(" %d ",r[a][b]);
        }
        printf("\n");
    }

    return 0;
}