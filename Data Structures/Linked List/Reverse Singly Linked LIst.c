//Reverse Singly Linked List
//refer youtube naresh it.

#include<stdio.h>
#include<stdlib.h>
#define SIZE 6

struct Node
{
    int data;
    struct Node* link;
};

struct Node* root = NULL;

int main()
{
    create_nodes();

    display();
    printf("\nD1 End\n");

    reverse();
    printf("\nReverse End\n");

    display();
    printf("\nDisplay 2 End");

    return 0;
}

void create_nodes()
{
    int i;
    for(i=0;i<SIZE;i++)
    {
        struct Node* temp;

        temp = (struct Node*)malloc(sizeof(struct  Node));

        temp->link = NULL;

        printf("\nEnter Node %d Data:\n",i+1);
        scanf("%d",&temp->data);

        if(root == NULL)
            root = temp;

        else
        {
            struct Node* p = root;

            while(p->link != NULL)
            {
                p = p->link;
            }

            p->link = temp;

            printf("\nNode Inserted");
        }
    }
}

void reverse()
{
    struct Node* p = root;
    struct Node* q = root;

    int i=0,j=SIZE-1;

    while(i < j)
    {
        int k = 0;

        while(k < j)
        {
            q = q->link;
            k++;
        }

        struct Node* temp;
        temp->data = p->data;
        p->data = q->data;
        q->data = temp->data;

        i++;
        j--;

        p = p->link;
        q = root;
    }
}

void display()
{
    struct Node* p = root;

    printf("\nList Elements are:\n");

    for(int i=0;i<SIZE;i++)
    {
        printf("%d-->",p->data);
        p = p->link;
    }
    printf("NULL");
}
