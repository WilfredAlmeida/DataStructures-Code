//Stack Using Singly LIst.
//refer youtube naresh it
//Operations Performed:
/*
1. Creation
2. Push
3. Pop
4. Peek
5. Length
6. Display
*/
//is full and empty is not done here cuz is empty is easy and due to dynamic memory allocation size has no limit.

#include<stdio.h>
#include<malloc.h>

struct Node
{
    int data;
    struct Node* link;
};

struct Node* top = NULL;

int main()
{
    while(1)
    {
        int ch;
        printf("\nEnter Choice:\n 1. Push\n 2. Pop\n 3. Peek\n 4. Display\n 5. Exit\n");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
        default:
            printf("\nInvalid Choice\n");
        }
    }
}

int length()
{
    struct Node* temp;
    temp = top;

    int count=0;

    if(temp == NULL)//if list is empty
        return 0;
    else
    {
        while(temp != NULL)//As long there are elements in list increment count
        {
            count++;
            temp = temp->link;
        }
    }
    return count;
}
void push()
{

    struct Node* temp;
    temp = (struct Node*) malloc(sizeof(struct Node));

    printf("\nEnter Node Data:\n");
    scanf("%d",&temp->data);

    if(top == NULL)
    {
        temp->link = NULL;
        top = temp;

        printf("\nValue Pushed\n");
    }

    else
    {
        temp->link = top;
        top = temp;

        printf("\nValue Pushed\n");
    }
}

void display()
{
    if(top == NULL)
    {
        printf("\nStack is Empty\n");
    }
    else
    {
        struct Node* p = top;

        printf("\Count = %d",length());

        printf("\nStack Elements are:\n");

        int i;
        for(i=0;i<length();i++)
        {
            printf("%d\n",p->data);
            p = p->link;
        }
    }
}
void pop()
{
    if(top == NULL)
        printf("\nStack is Empty\n");
    else
    {
        struct Node* p = top->link;

        top->link = NULL;

        top = p;

        printf("\nValue Popped\n");
    }
}
void peek()
{
    if(top == NULL)
    {
        printf("\nStack is Empty\n");
    }
    else
    {
        printf("\nPeeked Value is:%d\n",top->data);
    }
}
