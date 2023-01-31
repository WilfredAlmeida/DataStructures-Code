#include<stdio.h>
#include<string.h>
int main()
{
    char *c = "Hello";

    f1("Hi");
}

void f1(char *c)
{
    char *s;

    strcpy(s,c);

    printf("%s",s);
}