/*

Refer: Abdul Bari DS

*/

#include <stdio.h>
#include <limits.h>
#define I MAX_INT
int cost[8][8] = {
                  {I, I, I, I, I, I, I, I},
                  {I, I, 25, I, I, I, 5, I},
                  {I, 25, I, 12, I, I, I, 10},
                  {I, I, 12, I, 8, I, I, I},
                  {I, I, I, 8, I, 16, I, 14},
                  {I, I, I, I, 16, I, 20, 18},
                  {I, 5, I, I, I, 20, I, I},
                  {I, I, 10, I, 14, 18, I, I}
                  };

int t[2][7];
int near[8];

int main()
{
    int i,j,k,u,v,min = I;

    for(i=1;i<=7;i++)
    {
        for(j=1;j<=i;j++)
        {
            if(cost[])
        }
    }
    
    return 0;
}