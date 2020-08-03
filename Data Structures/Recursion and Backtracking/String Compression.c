/*

Joseph and Jane are making a contest for apes. During the process, they have to communicate
frequently with each other. Since they are not completely human, they cannot speak properly.
They have to transfer messages using postcards of small sizes.

To save space on the small postcards, they devise a string compression algorithm:

If a character, ch, occurs n(>1) times in a row, then it will be represented by {ch}{n},
For example, if the substring is a sequence of  'a' ("aaaa"), it will be represented as "a4".

If a character, ch, occurs exactly one time in a row, then it will be simply represented as {ch}.
For example, if the substring is "a", then it will be represented as "a".

Help Joseph to compress a message, msg.

Sample Input:
aaabcceew

Sample Output:
a3bc2e2w

*/

/*

Solution:
1. In recursive function say f(), pass string to be compresed and starting position from where to 
   start compressing.
2. If passed position is greater than length of string, return
3. If adjacent characters are recurring, count them.
4. Push the recurring character once and immediately after it push its occuring count converted into
   char. Call the rucursing method and pass string and new position from where to start compressing.
5. For the new position stated in step 4, while counting occurences of recurring cahracter, increment
   a variable starting from position received in f() and pass it.
6. If character is not recurring push it alone in stack and call recursing method for next position.
7. If character is not recurring and is last character of string, push it in stack and return.


*/

#include <stdio.h>
#define SIZE 9

char stack[SIZE]; //Will contain compressed string
int top = -1;

void push(char value); //will push values into stack

int main()
{
    char str[SIZE] = "aaabcceew"; //String to be comrpessed

    printf("\nOrignal Message\n");

    print_string(str);

    compress_string(str, 0);

    printf("\nCompressed String\n");

    print_string(stack);

    return 0;
}

void print_string(char str[]) //Prints String
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%c", str[i]);
    }
}

void compress_string(char str[], int pos) //Recursive function wil compress string
{
    if (pos == SIZE) //Step 2 in solution block above
        return;

    else
    {
        if (str[pos] == str[pos + 1]) //step 3
        {
            char a = str[pos];      //temporary variable to iterate through string
            int count = 0, i = pos; //count of recurrences, step 5

            while (a == str[pos]) //until same character reoccures
            {
                count++;    //increment count
                i++;        //step 5
                a = str[i]; //move temp variable to next character in string
            }

            push(str[pos]);    //Step 4
            push(count + '0'); //Step 4

            compress_string(str, i); //Step 4
        }

        else if (pos == SIZE - 1) //Step 7
            push(str[pos]);

        else //step 6
        {
            push(str[pos]);
            compress_string(str, pos + 1);
        }
    }
}

void push(char value) //push values into stack
{
    top++;
    stack[top] = value;
}