/*

In a given sequence of characters, check whether the opening and closing parenthesis() are balanced.

*/

/*

Solution:
1. Traverse all elements of array
2. if element == ) push in into stack
3. if element == ( pop it from stack

*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool check(char str[],int size);
bool pop();

struct stack
{
    struct stack* next;
    char data;
};

struct stack* top = NULL;

int main()
{
    char str[] = {'(','a','+','b',')'};
    int size = (int) sizeof(str)/sizeof(str[0]);//size of array

    if(check(str,size))
        printf("\nBalanced\n");
    else
        printf("\nUnbalanced\n");
}

bool check(char str[],int size)
{
    bool b;

    for(int i=0;i<size;i++)
    {
        if(str[i] == '(' )
            push(str[i]);
        else if(str[i] == ')' )
            b = pop();
    }

    if(top == NULL && b == true)
        return true;

    return false;
}

void push(char c)
{
    struct stack* temp = (struct stack*) malloc(sizeof(struct stack));
    temp->data = c;
    temp->next = NULL;

    if(top == NULL)
        top = temp;
    else
        top->next = temp;
}

bool pop()
{
    if(top == NULL)
        return false;

    else if(top->next == NULL)
    {
        top = NULL;
        return true;
    }

    else
    {
        struct stack* p = top;
        struct stack* q;

        while(p)
        {
            q = p;

            p = p->next;
        }

        q->next = NULL;
        return true;
    }
}
