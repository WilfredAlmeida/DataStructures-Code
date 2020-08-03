//Factorial using Recursion
#include<stdio.h>
int function_factorial(int a);
int main()
{
    int n;
    printf("Enter number to find Factorial: \n");
    scanf("%d",&n);

    int factorial = function_factorial(n);

    printf("\nFactorial of %d id %d",n,factorial);

    return 0;
}

int function_factorial(int a)
{
    if(a==1)
        return 1;
    return a*function_factorial(a-1);
}