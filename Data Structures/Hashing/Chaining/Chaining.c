/*

Refer: Abdul Bari DS

For theory, read book or watch video

See the image in folder to get visualization of chaining
*/

#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

void SortedInsert(struct Node **H, int x)//Performs sorted insert
{
    //**H is a pointer storing the address of another pointer and thus **,
    //Usage is as normal pointer tho, if you forgot pointers, read book located at
    //D:\Study\Data Structures\Books\Pointers in C.pdf

    struct Node *t, *q = NULL, *p = *H;

    t = (struct Node *)malloc(sizeof(struct Node));//Node to be inserted
    t->data = x;
    t->next = NULL;

    if (*H == NULL)//if root == NULL
        *H = t;

    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }

        if (p == *H)//if element is to be inserted before current root and made new
        //root
        {
            t->next = *H;//Make new node point at current root
            
            *H = t;//Update root pointer
        }

        else//Normal Linked List insertion
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

struct Node *Search(struct Node *p, int key)//Function to Search a element
{
    //We get the root node of list where the element might be situated and the element
    //to search itself
    
    //Until element is found and returned, loop
    while (p != NULL)
    {
        if (key == p->data)
        {
            return p;
        }
        p = p->next;
    }
    //When element is not found
    return NULL;
}

int Delete(struct Node **p, int key)//Takes root of list where element can be present
//return int is to indicate whether element was found and deleted or not
{
    //Pointers here might be complex if you forgot them but its easy, read the book
    //mentioned above
    
    struct Node *q = *p;

    while(*p != NULL && (*p)->data != key)//find element to be deleted
    {
        q = *p;

        *p = (*p)->next;
    }

    if(q == *p)//if element to be deleted is first element, root updation is done
    {
        *p = (*p)->next;
        q = NULL;
        return 1;
    }

    else
    {
        if(*p != NULL)//if *p is null, we searched whole list was 
        //searched and nothing was found
        {
            q->next = (*p)->next
            *p = q;
            return 1;
        }
    }

    return 0;//When element is not found.
}

int hash(int key)//Hash Function
{
    return key % 10;
}

void Insert(struct Node *H[], int key)//Insert into Hash Table
{
    int index = hash(key);//get index from hash function

    SortedInsert(&H[index], key);//Perform insertion in sorted manner.
    //Idea of Chaining says insert individual element and than sort each individual list.
    //We insert the element sorted and thus save the hassle. ;)
}

int main()
{
    struct Node *HT[10] = {NULL};//Hash Table
    struct Node *temp;

    //Insertion Operation
    Insert(HT, 15);
    Insert(HT, 25);
    Insert(HT, 35);

    int to_search = 185;
    int to_delete = 185;

    //Search Operation
    temp = Search(HT[hash(to_search)], to_search);

    if(temp)
        printf("\nFound %d\n", temp->data);
    else
        printf("\nNot Found\n");


    int flag = Delete(&HT[hash(to_delete)],to_delete);
    if(flag)
        printf("\nDeleted\n");
    else
        printf("\nNot Found\n");

    
    //Search Operation
    temp = Search(HT[hash(to_delete)], to_delete);

    if(temp)
        printf("\nFound %d\n", temp->data);
    else
        printf("\nNot Found\n");

    return 0;
}
