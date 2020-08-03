//Greatest Common Divisor (GCD) using Recursion

#include<stdio.h>

int main()
{
    int a,b;
    printf("Enter 2 Numbers:\n");
    scanf("%d%d",&a,&b);

    int gcd = function_gcd(a,b);

    printf("GCD of %d and %d is: %d",a,b,gcd);
}
int function_gcd(int a,int b)
{
    if(a==b)
        return a;
    if(a%b==0)
        return b;
    if(b%a==0)
        return a;
    if(a>b)
        return function_gcd(a%b,b);
    else
        return function_gcd(a,b%a);
}
