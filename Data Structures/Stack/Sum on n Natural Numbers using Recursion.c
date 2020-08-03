//Sum of n Natural Numbers using Recursion

#include<stdio.h>

int main()
{
    int n;
    printf("Enter a number: \n");
    scanf("%d",&n);

    int sum = function_sum(n);

    printf("Sum of Natural Numbers from 1 to %d is: \n%d",n,sum);

}
int function_sum(int a)
{
    if(a==1)
        return(a);
    return(a+function_sum(a-1));
}
