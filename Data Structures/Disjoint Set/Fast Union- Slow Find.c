/*

Refer: Abdul Bari YouTube, Karumachi book.

For Union by weight/size and union by rank/heigt, read karumachi book.

*/

#include<stdio.h>
#define SIZE 6

void make_set(int S[]);
int find(int S[], int n);
void set_union(int S[], int root1, int root2);
void print_set(int S[]);

int main()
{
    int S[SIZE] = {0,1,2,3,4,5};//Set

    //make_set(S);//Initializing set
    
    print_set(S);

    set_union(S,4,3);
    print_set(S);

    set_union(S,2,1);
    print_set(S);

    set_union(S,1,3);
    
    print_set(S);

    return 0;
}

void make_set(int S[])
{
    for(int i=0;i<SIZE;i++)
        S[i] = i+1;
}

int find(int S[], int n)
{
    if(!(n>=1 && n<SIZE))//if n is not within range 0 to size-1 i.e. last index of array
        return -1;

    if(S[n] == n) //If n is parent of itself, return n
        return n;

    else return find(S,S[n]);// Find parent of the element who is parent of n.
}

void set_union(int S[], int root1, int root2)
{
    if(find(S,root1) == find(S,root2))//If both have same parent, return, they are already in same set
        return;
    
    if(!((root1>=1 && root1<SIZE)&&(root2>=1 && root2<SIZE)))//if n is not within range 0 to size-1 i.e. last index of array
        return;

    S[find(S,root1)] = find(S,root2); //Make element1 parent of element2
}

void print_set(int S[])
{
    printf("\n");
    for(int i=1;i<SIZE;i++)
    {
        printf(" %d ",S[i]);
    }
}