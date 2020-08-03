/*

Stack using Array - Static Memory Allocation

Operations performed on Stack are:
1. Creation
2. Push
3. Pop
4. Peek - View the topmost element without deleting it.
5. Traverse
6. Is Empty
7. Is Full

*/

#include<stdio.h>
#include<conio.h>
#define CAPACITY 5 //Defining constant in C. Written in caps for understanding, no language rule abt it.

int top = -1;
int stack[CAPACITY];

int main()
{
    /*

    int a = 3;
    int v[a] = {11,2,3};//This line is not possible in C. 'a' in this case needs to be a constant.

    */

    while(1)
    {
        int choice;

        printf("\n\nSelect your Choice:\n 1. Push\n 2. Pop\n 3. Peek\n 4. Traverse\n 5. Is Empty\n 6. Is Full\n 7. Exit\n");
        scanf("%d",&choice);

        switch(choice)
            {
            case 1:
                {
                    int n;

                    printf("\nEnter vale to be pushed:\n ");
                    scanf("%d",&n);

                    push(n);
                    break;
                }
            case 2:
                {
                    int n = pop();
                    printf("\nPopped Value is:\n %d",n);
                    break;
                }
            case 3:
                {
                    int n = peek();
                    printf("\nPeeked Value is:\n %d",n);
                    break;
                }
            case 4:
                {
                    traverse();
                    break;
                }
            case 5:
                {
                    printf("\nIs Empty: %d",isEmpty());
                    break;
                }
            case 6:
                {
                    printf("\nIs Full: %d",isFull());
                    break;
                }
            case 7:
                exit(1);
            }
    }
}

int isFull()
{
    if(top==CAPACITY-1)
        return 1;
    return 0;
}

int isEmpty()
{
    if(top==-1)
        return 1;
    return 0;
}

void push(int n)
{
    if(isFull())
    {
        printf("\nStack is Full!");
    }
    else
    {
        top++;
        stack[top]=n;
        printf("\nValue Pushed");
    }
}

int pop(int n)
{
    if(isEmpty())
    {
        printf("\nStack is Empty!");
    }
    else
    {
        int a = stack[top];
        top--;
        return a;
    }
}


int peek()
{
    if(isEmpty())
    {
        printf("\nStack is Empty!");
        return -1;
    }
    else
    {
        return stack[top];
    }
}

void traverse()
{
    if(isEmpty())
        printf("\nStack is Empty!");
    else
    {
        printf("\nStack elements are:");

        for(int i=0;i<=top;i++)
        {
            printf("\n%d",stack[i]);
        }
    }
}
