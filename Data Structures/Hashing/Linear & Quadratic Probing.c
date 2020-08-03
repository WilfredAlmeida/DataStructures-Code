/*

Refer: Abdul Bari DS
Linear Probing:
    Idea here is to utilize the space given only, no extra space, so what we do is 
calculate index using hash function and if that index is occupied we insert the
element at next free space. Same for searching, search until it is found or a free
space is encountered. Probe function below, solve that expression on paper and you'll
get it. :)

Quadratic Probing:
    Same as Linear just instead of storing at next free space, we store with a gap.
The probing formula is HT[(index+i)%SIZE] where i starts from 0 and increments by
onr for Linear Probing and is squared for Quadratic Probing.

*/

#include<stdio.h>
#define SIZE 10

int hash(int key)
{
    return key%10;
}

void probe(int *HT, int key)
{
    int i = 0, index = hash(key);

    while(HT[(index + i)%SIZE] != NULL)
        i++;

    HT[(index+i)%SIZE] = key;
}

void insert(int *HT, int key)
{
    int index = hash(key);

    if(HT[index] == NULL)
        HT[index] = key;
    
    else
        probe(HT,key);
}

int search(int *HT, int key)
{
    if(HT[hash(key)] == key)
        return key;
    
    else
    {
        int i=0, index = hash(key);
        while(i < SIZE && (HT[(index+i)%SIZE] != key))
            i++;
    
        if(HT[(index+i)%SIZE] == key)
            return key;
        else
            return NULL;
    }
    return NULL;
}

int main()
{
    int HT[SIZE] = {NULL};

    insert(HT,12);
    insert(HT,26);
    insert(HT,22);

    int flag = NULL;
    flag = search(HT,25);

    if(flag != NULL)
        printf("\nFound %d",flag);
    
    else
        printf("\nNot Found");

  return 0;



}