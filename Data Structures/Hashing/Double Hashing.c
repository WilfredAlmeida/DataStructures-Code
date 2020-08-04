/*

Refer: Abdul Bari DS

Instead using one hash function, 2 are used here, hence double hashing

First function is h1(x) = x % SIZE
    If collision occurs, use function h(x) = (h1(x) + i * h2(x)) % SIZE
    where h2 is below and i = 0,1,2...

Second hash function is h2(x) = R - (x % R) where R is the greatest prime number
closest to SIZE.

*/

#include<stdio.h>
#include<stdbool.h>
#define SIZE 10

int h1(int x)
{
    return x % SIZE;
}

bool is_prime(int n)
{
    for(int i=2;i<n;i++)
    {
        if(i%n == 0)
            return false;
    }
    return true;
}

int find_prime(int n)
{
    for(int i=n;i>=2;i--)
    {
        if(is_prime(i))
            return i;
    }
}

int h2(int x)
{
    int r = find_prime(SIZE);
    return (r - (x % r));
}

int insert(int *HT, int x)
{
    if(HT[h1(x)] == NULL)
    {
        HT[h1(x)] = x;
    }
    else
    {
        int i=0;
        int index = (h1(x) + i * h2(x)) % SIZE;

        while(i < SIZE && HT[index] != NULL)
            i++;
        
        HT[index] = x;
    }
}

int main()
{
    int HT[SIZE] = {NULL};

    insert(HT,12);
    insert(HT,34);
    insert(HT,22);

    return 0;
}