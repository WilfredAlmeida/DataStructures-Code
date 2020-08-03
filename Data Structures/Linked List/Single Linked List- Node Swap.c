//Single Linked List Node Swap
//Refer YouTube naresh it

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* link;
};

struct Node* root = NULL;

int main()
{

    int ch;

    while(1)
    {
        printf("\nEnter Choice:\n 1. Add Elements\n 2. Swap Elements\n 3. Display List\n");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            addElements();
            break;
        case 2:
            swap();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("\nInvalid Choice\n");
        }
    }

    return 0;
}

void addElements()
{
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));

    temp->link = NULL;

    printf("\nEnter Node Data:\n");
    scanf("%d",&temp->data);

    if(root == NULL)
    {
        root = temp;
        printf("\nNode Inserted\n");
    }
    else
    {
        struct Node* p = root;

        while(p->link != NULL)
        {
            p = p->link;
        }

        p->link = temp;

        printf("\nElement Inserted\n");
    }
}

void display()
{
    if(root == NULL)
        printf("\nList Empty\n");
    else
    {
        struct  Node* p = root;

        printf("\nList Elements are:\n");

        while(p != NULL)
        {
            printf("%d-->",p->data);

            p = p->link;
        }
        printf("NULL");
    }
}

void swap()
{
    if(root == NULL)
    {
        printf("\nList Empty\n");
    }
    else
    {
        int loc = 3;

        struct Node* p = root;
        struct Node* q = root;
        struct Node* r = root;

        int a = 1;
        int b = 1;

        while(a < loc-1)
        {
            q = p->link;
            a++;
        }

        while(b < loc)
        {
            r = r->link;
            b++;
        }

        q->link = r->link;
        r->link = p;
        p->link = q;

        printf("\nElements Swapped\n");
    }
}

int length()
{
    struct Node* p = root;
    int count;

    while(p->link != NULL)
    {
        count++;
        p = p->link;
    }
}
