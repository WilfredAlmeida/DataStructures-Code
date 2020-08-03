/*

Sum of n natural numbers sing c

*/

/*

Solution: Sum of n natural numbers id sum of n-1 natural numbers + 1.
Thats what we do here. Base case is when n==1, we know sum of 1 natural number is 1 so we return
1 and so on

*/
#include<stdio.h>

int main()
{
    
    int n;

    printf("\nEnter n:\n");
    scanf("%d",&n);

    printf("\nSum of %d Natural Numbers is\n%d",n,sum_of_n_natural_numbers(n));
    
    return 0;
}

int sum_of_n_natural_numbers(int n)
{
    if(n == 1)//base case
        return 1;

    return n + sum_of_n_natural_numbers(n-1);//recursion :)
    
}