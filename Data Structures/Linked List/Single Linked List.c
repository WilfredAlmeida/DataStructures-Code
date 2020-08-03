/*
refer: naresh it youtube
Single Linked List

Operations:
1. Creation
2. Insertion at specific position
3. Insertion at end- append
4. Insertion at beginning
5. Deletion
6. Length
7. Traverse

*/
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    //node elements
    int data;
    struct Node* link;
};

struct Node* root = NULL; //root node. will be first node and root node.

int main()
{

    int choice;
    while(1)
    {
        printf("\nEnter Your Choice:\n 1. Append\n 2. Insert at Position\n 3. Insert at Beginning\n 4. Delete\n 5. Length\n 6. Traverse\n 7. Exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            append();
            break;
        case 2:
            insert_at_position();
            break;
        case 3:
            insert_at_beginning();
            break;
        case 4:
            delete_node();
            break;
        case 5:
            printf("\nLength of list is: %d\n",length());
            break;
        case 6:
            traverse();
            break;
        case 7:
            exit(1);
        default:
            printf("Invalid Choice");
        }
    }

    return 0;
}

void append()
{
    struct Node* temp;

    temp = (struct Node*) malloc(sizeof(struct Node)); //creating a memory block for node and keeping its temporary reference
    //into tempt to assign it to last node in the list

    temp->link = NULL;

    printf("\nEnter Node Data:\n");// getting node data
    scanf("%d",&temp->data);

    if(root == NULL) //if there are no nodes in the list, root will be null and we thus make the node the root node
    {
        root = temp; //temp is a full fledged node, we just assign it to root and we are done
    }
    else
    {
        //if there are elements in the list, we dont know their positions, count. So we begin at root and check every node's
        //link field. If it is null then it is the last node and then we append our desired node.
        struct Node* p;
        p = root;

        while(p->link != NULL)
        {
            //p is first root. Then it goes forward and checks link field of simultaneous node.
            //if it is not null and has address of some other node than p will point to that node.
            //link field has a memory address of next node and while loop then goes to that address.
            //when p will point to null, it will signify last node.

            p = p->link;// link field is a memory address. So we are assigning p the value stored at the memory of its link
            //which at the moment is pointing to the next node.
        }

        p->link = temp; // from above while loop, p is pointing to last node and now we just make it point to our desired node
        printf("\nNode Appended\n");
    }
}

int length()
{
    struct Node* temp;
    temp = root;

    int count=0;

    if(temp == NULL)//if list is empty
        return 0;
    else
    {
        while(temp != NULL)//As long there are elements in list increment count
        {
            count++;
            temp = temp->link; //explained in append method
        }
    }
    return count;
}

void traverse()
{
     struct Node* temp;
     temp = root;

     if(temp == NULL)
        printf("\nList is Empty\n");
    else
    {
        printf("\nList Elements are:\n");

        while(temp != NULL)
        {
            printf("%d-->",temp->data);
            temp = temp->link;
        }
        printf("NULL\n");
    }
 }

void delete_node()
{
    if(root == NULL)
        printf("\nList is Empty\n");

    else
    {
        struct Node* temp = root;
        struct Node* p;

        int i=1, position;

        printf("\nEnter position to delete:\n");
        scanf("%d",&position);

        if(position>length())
            printf("\nInvalid Position");

        else if(position == 1)
        {
            //if position it is root node and it needs to be handled little different than other nodes.
            struct Node* temp = root; //temp is root
            struct Node* p;

            p = temp->link; //p is element pointed by root which needs to be made as root so that the first node which is
            //root can be deleted.

            root->link = NULL; //Disconnecting root from list

            root = p; //making p as root

            printf("\nNode Deleted");
        }

        else
        {
            //for all other elements
            while(i < position-1)
            {
                temp = temp->link;
                i++;
            }//temp is now the element before the one which needs to be deleted

            p = temp->link; //p is the element to be deleted holding the pointing to the node after it

            temp->link = p->link; //temp now points to the node which is after the node to be deleted

            p->link = NULL; //Disconnecting p from list

            printf("\nNode Deleted\n");
        }
    }
}

void insert_at_position()
{
     //inserting at a position is in other words inserting after a certain node.

     if(root == NULL)
        printf("\nList is Empty\n");
     else
     {
         int position;
         printf("\nEnter position at which to insert: \n");
         scanf("%d",&position);

         if(position > length())
            printf("\nPosition greater than size of list.\n");

         else
         {
             struct Node* p; //node after which value is to be inserted
             p = root;

             int i = 1;//indicating first node in list. from here we will go to the node after which node is to be inserted.

             while(i < position-1)//'i' will stop the loop at the position after which value is to be inserted.
                //for eg: if position == 3, as per while loop condition, it will stop when i == 2 i.e. 'i' will be less  than
                //position
             {
                 p = p->link;//explained in append function
                 i++;
             }

             struct Node* temp = (struct Node*) malloc(sizeof(struct Node));//node to be inserted

             printf("\nEnter node data:\n");
             scanf("%d",&temp->data);

             temp->link = p->link; //temp will point to the node p is pointing
             p->link = temp; // p will point to temp and thus temp is in between p and other node

             printf("\nNode Inserted\n");

         }
     }

 }

void insert_at_beginning()
{
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));//node that needs to be inserted

    printf("\nEnter node data:\n");
    scanf("%d",&temp->data);

    struct Node* p,q;

    p = root; //consider p as root

    temp->link = p;//temp now points to root so now it has become root

    root = temp;//assigning value of variable temp to variable root so that it wont affect other functions.

    printf("\nNode Inserted at beginning\n");

}
