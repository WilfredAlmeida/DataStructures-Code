/*
malloc is used to allocate dynamic memory block. It is included in <stdlib.h>.

malloc returns a pointer to the base address of the block allocated. The return type of malloc is void i.e. it returns
pointer of type void. before it is assigned into any variable we need to type cast it into relevant type.

Typecasting is done in the same way we do in java.

syntax: malloc(size_of_blocks_to_allocate)
here size cannot be a direct number and needs to be a datatype like int char float.

for more refer: YouTube: malloc in c naresh it
*/

/*

In the following program we are creating a structure and creating its object using malloc, taking and printing user input.

*/

#include<stdio.h>
#include<stdlib.h>

struct Student
{
    char student_name[20];
    int student_roll_number;
    int student_age;
};

int main()
{

    struct Student* student1 = (struct Student*) malloc(sizeof(struct Student));
    // Whenever we use a structure we defined we need to use 'struct' keyword, its a rule.
    //malloc will be returning pointer to memory block so we create a pointer variable of our structure.
    //malloc returns void pointer so we typecast it into the type of our structure. Typecasting in C and Java are done in the same
    //way.
    //malloc needs a size to allocate and the size must be of a datatype and a structure in c is a user defined datatype and sizeof
    //returns size of what we passed into it so we do what is done.

    printf("Enter Student Name, Roll Number, Age in sequence mentioned here:\n");
    scanf("%s%d%d",student1->student_name, &student1->student_roll_number, &student1->student_age);
    //%s for string, no '&' is written for student name because the variable itself is pointing to a base address of name array
    //and address pointing to a address is the same thing.
    //Whenever we access structure variable, we use '.'(dot) operator but whenever the object variable is a pointer we use
    //'->'(arrow) operator.

    printf("\nName: %s",student1->student_name);
    printf("\nRoll Number: %d",student1->student_roll_number);
    printf("\nAge: %d",student1->student_age);


    return 0;
}
