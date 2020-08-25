/*

Bitwise operators perform operations at bit level

*/

#include<stdio.h>

int main()
{
    int a = 4, b = 7;

    printf("\nBitwise AND(&) of %d and %d is: %d\n",a,b,(b&a));
    //What happens here is, a and b get converted into binary,
    //0100 -> 4,
    //0111 -> 7.
    //than AND operation of boolean algebra is performed and answer obtained is
    //converted back to int.
    //0100 -> 4

    printf("\nBitwise OR(|) of %d and %d is:%d\n",a,b,(a|b));
    //Same thing as above happens

    printf("\nBitwise NOT(~) of %d is: %d and %d is:%d\n",a,~a,b,~b);
    /*
    Bitwise not takes all bits and inverses them is theory, but after that, for the
    number, its MSB indicating sign 0->positive, 1->negative is set to 1 and
    now computer will treat that number as a negative number and follow its
    standard procedure of converting -ve to decimal which is, taking 2's compliment
    of that number. 2's compliment is taken by inversing all bits and adding 1 to
    LSB. Note that addition is binary addition and follows its rules. The resultant
    number is then converted into decimal taking the last 4 bits only. The thing
    is although there are 64-bits in memory, theminimal  number of bits required
    to represent operand i considered here. For eg: To represent 17(10001), 5 bits
    are required and in the result of its NOT, only least 5 bits will be converted.
    */

   printf("\nBitwise XOR(^) of %d and %d is: %d",a,b,(a^b));
   //XOR gives 1 when operands are not equal, so for (1,0) and (0,1) it will return 1,
   //for everything else (0,0) and (0,1) it will result 0.
   //So 4(0100) ^ 7(0111) = 3(0011)

   printf("\nBitwise left shift(<<) of %d by %d bits is: %d\n",a,b,(a<<b));
   //Lets say 5<<2. So left shift operation shifts all bits to the left of 5 for 2
   //times. The leftmost bit is lost and 0 is put at the rightmost bit.
   //Also, left shif of a number = number * 2^right_operand. (^ = power here).
   //So answer of 5<<2 = 5 * 2^2 = 5*4 = 20

   printf("\nBitwise right shift(>>) of %d by %d bits is:%d\n",a,b,(a>>b));
   //Shifts bits to right. Note that the MSB which is to be filled is filled with 
   //the bit that was previously the MSB,  this is done to preserve the sign of the
   //operand. 1111 1111 1111 1111 1111 1111 1111 1011
   //Formula: number / 2^right_operand.
   //So answer of 5>>2 = 5 / 2^2 = 5/4 = 1 
   //For -ve numbers, 1110

   return 0;
}