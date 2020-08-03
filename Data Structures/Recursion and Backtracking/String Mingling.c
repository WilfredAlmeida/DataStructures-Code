/*

Pawel and Shaka recently became friends. They believe their friendship will last forever if they
merge their favorite strings.

The lengths of their favorite strings are the same, n. Mingling two strings, P=p1p2p3..pn and
Q=q1q2q3..qn, both of length n, will result in the creation of a new string R of length 2*n.
It will have the following structure:
        R=p1q1p2q2p3q3..pnqn

You are given two strings  (Pawel's favorite) and  (Shaka's favorite), determine the mingled string.

*/

/*

Solution:
1. We pass our strings into a function with a position from where we want to start mingling.
2. The function is recursive, it pushes the values from the specified position into a stack and
   if position is not the end of string, recursive function is called with position = position+1.

*/

#include <stdio.h>
#define SIZE 4

char mingled[SIZE * 2]; //Stack to push mingled values
int top = -0;           //top variable for stack

int main()
{
    //Strings to be mingled
    char s1[SIZE] = "abcd";
    char s2[SIZE] = "pqrs";

    printf("\nMingled String is:\n");

    function_mingled(s1, s2, 0); //calling function to mingle strings

    for (int i = 0; i <= SIZE * 2; i++) //Printing mingled String
    {
        printf("%c", mingled[i]);
    }

    return 0;
}

void function_mingled(char s1[], char s2[], int pos) //Recursive function to mingle strings
{
    if (pos == SIZE) //we have reached end of strings, return
        return;
    else
    {
        //push characters at position 'pos' into stack into required order
        push(s1[pos]);
        push(s2[pos]);

        //call recursive function for further values
        function_mingled(s1, s2, pos + 1);
    }
}

void push(char c) //function to push characters into stack
{
    top++;
    mingled[top] = c;
}