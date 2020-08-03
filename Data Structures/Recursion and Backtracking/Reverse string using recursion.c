/*

Write a program to reverse string using recursion

*/

#include<stdio.h>
#define SIZE 20

int main()
{

    char sentence[SIZE] = "Wilfred Almeida";

    print_sentence(sentence);//prints string

    reverse_sentence(sentence);//reverses string

    print_sentence(sentence);

    return 0;
}

void print_sentence(char sentence[])
{
    int i = 0;
    while(i<SIZE)
    {
        printf("%c",sentence[i]);
        i++;
    }
}

void reverse_sentence(char sentence[])//calls recursive function to reverse string
{
    int start_pos = 0, end_pos = SIZE-1;
    reverse(sentence,start_pos,end_pos);
}


/*Swap character at index 0 and size-1, increment from 0 and decrement from size-1.
  When start becomes greater than end stop*/
void reverse(char sen[],int start,int end)
{
    if(start > end)
        return;
    
    char temp = sen[start];
    sen[start] = sen[end];
    sen[end] = temp;

    reverse(sen,start+1,end-1);
}