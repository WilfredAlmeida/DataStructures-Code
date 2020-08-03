//Print 1 to 100 without loop

#include<stdio.h>

int main()
{
    int a = 1;

    void f1()
    {
        if(a<=100)
        {
            printf("\n%d",a);
            a++;

            f1();
        }
    }

    f1();
    return 0;
}
