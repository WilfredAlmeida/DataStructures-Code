/*

Multiply 2 numbers using only + and - operators

*/

/*

Solution:
1. Multiplication of a * b is what we know is adding a into a for b times.
2. Thats what we do here, add a into itself for b times

*/

#include<stdio.h>

int multiply(int a,int b);

int main()
{
    
    int a,b;

    printf("\nEnter 2 numbers to multiply:\n");
    scanf("%d %d",&a,&b);

    printf("\nMultipliaction of %d * %d = %d",a,b,multiply(a,b));
    
    return 0;
}

int multiply(int a, int b)
{
    if(b == 1)//this equals a*1
        return a;

    return a + multiply(a,b-1);
}