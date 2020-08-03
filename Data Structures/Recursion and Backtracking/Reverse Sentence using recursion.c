/*

Reverse a sentence using recursion

Solution:

To Reverse the sentence, we are going to recursively call until we reach the last word.
Print the last word and return back to the previous word and repeat the same process.
Starting and ending index is marked for each word.

*/

#include<stdio.h>

void reverse();

int main()
{
   char sentence[]="Wilfred Almeida";
   
   reverse(sentence,0);            //call
   
   return 0;
}


void reverse(char sentence[],int n) 
{
   int start = n;                // starting index 
   int i;
   int end = start;               // ending index

   while(1)
   {
      if(sentence[end] =='\0')
         break;               // base condition

      else if(sentence[end] ==' ')
        { 
            reverse(sentence,end+1);     //recursive call if word ended
            break;
        }
       else
          end++;               // incrementing index if it is character
   }
   for( i =start;i<=end;i++)
   {
      printf("%c",sentence[i]);      // printing the word
   }
 
  return; 
}