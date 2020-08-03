/*

A word is considered elfish if it contains the letters:
e, l, and f in it, in any order. For example, we would say
that the following words are elfish: whiteleaf, tasteful, unfriendly,
and waffles, because they each contain those letters.
Write a predicate function called elfish such that, given a word,
tells us if that word is elfish or not.

*/

/*

Solution:
1. We check each character of string using an if condition.
2. We maintain a variable 'count' which is incremented whenever an 'e', 'l', 'f' is found. In the end
   we check if value of 'count' is >= 3, 3 cuz 'e','l','f' all occur in string than count will be minimum
   3.
3. Recursion occurs in following way:
    We pass string and index value to check from the string.
    Whenever match for 'elf' is found, we increment count and recurse for next position
    We recurse till we reach the end of the string.

*/

#include <stdio.h>
#include <stdbool.h>
#define SIZE 6 //size of char array

bool elfish(char word[], int start_pos); //method to check

int count = 0; //variable to indicate occurence of 'elf' as stated above

int main()
{

    char word[SIZE] = "elfish";

    elfish(word, 0); //calling method to check string and passing index value from where to start checking

    if (count >= 3) //explained in solution comment block
        printf("\nElfish\n");
    else
        printf("\nNot Elfish\n");

    return 0;
}

bool elfish(char word[], int start_pos)
{
    int n = start_pos;
    while (n < SIZE) //To go until end of string
    {
        if (word[n] == 'e' || word[n] == 'l' || word[n] == 'f') //condition to check if 'e','l','f'
        //is present or not
        {
            count++;             //incrementing count as stated in solution block
            elfish(word, n + 1); //recursing for next position
        }
        n++; //if checked character is not among 'elf' than increment n and pass it as position to recurse
        elfish(word, n);
    }
}