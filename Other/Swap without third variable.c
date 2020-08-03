//swap 2 variables without third variable.
#include<stdio.h>
#include<conio.h>
int main()
{

int a = 2;
int b = 1;

printf("a = %d",a);
printf("\nb = %d",b);

a = a+b;
b = a-b;
a = a-b;

printf("\na = %d",a);
printf("\nb = %d",b);

return 0;
}
