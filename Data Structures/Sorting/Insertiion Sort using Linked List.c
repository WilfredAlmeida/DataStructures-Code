/*

Refer: Abdul Bari DS

Idea of insertion sort is assume that the first element in the list is sorted and
starting from the 2nd element compare the element with all elements before it and
find its ideal place. If we encounter an element greater than our element taken to
sort than our element needs to be before that element and so we put it before that
element and move further :)

*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *root = NULL;

void insert_node(int data);
void display();
void insertion_sort();

int main()
{
    int arr[] = {87, 15, 98, 174, 65};
    for (int i = 0; i < 5; i++)
        insert_node(arr[i]);

    printf("\nUnsorted List:");
    display();

    insertion_sort();

    printf("\nSorted List:");
    display();

    return 0;
}

void insert_node(int data) //create and insert a node in the list
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    t->next = NULL;

    if (root == NULL)
        root = t;

    else
    {
        struct Node *p = root;
        struct Node *q;

        while (p != NULL)
        {
            q = p;
            p = p->next;
        }

        q->next = t;
    }
}

void display() //function to display list
{
    struct Node *p = root;

    printf("\n");
    while (p != NULL)
    {
        printf(" %d ", p->data);

        p = p->next;
    }
}

void insertion_sort()
{
    //Idea here is take a node, disconnect it from the list, find its ideal position
    //and insert it.

    struct Node *p = root->next, *m = root->next;
    //p is the node that will be disconnected and inserted
    //m is to traverse through the list and get the node we want to sort

    while (p != NULL) //till you reach the end of the list
    {
        m = m->next; //updating m to point to the next location in the list
        //not updated in end cuz its value is assigned to p at the end to perform
        //sorting and p is disconnected from the list so m gets disconnected too
        //so updating it before hand

        //---------------Start: Disconnecting p from the list------------------

        //Idea here is connect node before p to node after p and make next of p NULL
        struct Node *q = root, *r = NULL;

        while (q != p)
        {
            r = q;
            q = q->next;
        }

        r->next = p->next;
        p->next = NULL;

        //---------------End: Disconnecting p from the list------------------

        //---------------Start:Find ideal position for p and insert it---------

        struct Node *a = root, *b = NULL; //a is node before which p is to be connected
        //and b is node after which p is to be connected.

        int flag = 1; //We need to know whether the place we are inserting is the first
        // or inbetween the list, cuz root needs to be updated. So as per insertion
        //sort technique we begin with node at 2nd position and assume that the one
        //first position is already sorted, So if any element needs to be inserted at
        //the first position than the loop which is to determine where p is to be
        //inserted wont run at all and flag wont change and we will know that p
        //needs to be the root.

        while (a != NULL && p->data > a->data) //loop to determine position of p
        {
            flag = 0; //changing flag so we will know p is not to be inserted at the root.
            b = a;
            a = a->next;
        }

        if (flag == 1) //p needs to be the root and we make it
        {
            p->next = a;
            root = p;
        }
        else
        { //connecting p in the list at its ideal position.
            p->next = a;
            b->next = p;
        }
        //---------------End:Find ideal position for p and insert it---------

        p = m; //Updating p to sort next element in the list
    }
}