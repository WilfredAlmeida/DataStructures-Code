//Fibonacci Series using Recursion.

#include<stdio.h>

int main()
{
    printf("First 10 Fibonacci Numbers are:\n");
    int i;
    for(i=1;i<=10;i++)
    {
        int fibonacci = function_fibonacci(i);
        printf("%d\t",fibonacci);
    }

    return 0;
}

int function_fibonacci(int a)
{
    if(a==1||a==2)
        return(1);
    return(function_fibonacci(a-1)+function_fibonacci(a-2));
}
