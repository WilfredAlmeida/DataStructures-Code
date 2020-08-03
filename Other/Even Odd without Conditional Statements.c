//Even Odd without Conditional Statements

#include<stdio.h>

int main()
{

    int a=23;

    while(a%2==0)
    {
        printf("Even");
        break;
    }
    while(a%2!=0)
    {
        printf("Odd");
        break;
    }

    return 0;
}
