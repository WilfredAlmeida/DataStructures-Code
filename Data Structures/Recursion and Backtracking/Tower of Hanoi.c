/*

Tower of Hanoi using recursion.

*/

/*

Solution:

1. Imagine we have 2 disks.
2. Move one disk at a time in following order:
    src -> aux
    src -> des
    aux -> des
3. Above number of steps can be followed for 'n' number of disks where n>0.

*/

#include<stdio.h>

int main()
{

    int n = 4;//number of disks
    int source = 1, auxillary = 2, destination = 3;//these are rods/towers/pegs

    tower_of_hanoi(n,source,destination,auxillary);

    return 0;
}

void tower_of_hanoi(int n,int source, int destination, int auxillary)
{
    if(n == 1)//if only 1 disk then move directly move from src->des
    {
        printf("\nMove from %d to %d\n",source,destination);
        return;
    }
    tower_of_hanoi(n-1,source,auxillary,destination);//remember method signature src, des, aux. This is src - >aux

    printf("\nMove from %d to %d\n",source,destination);//src->des

    tower_of_hanoi(n-1,auxillary,destination,source);//aux->des

}
