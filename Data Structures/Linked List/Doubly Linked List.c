//Doubly Linked List
//refer YouTube Naresh IT
/*

Operations performed are:
1. Creation
2. Append
3. Traversal
4. Length
5. Insert at Beginning
6. Insert any position

:) following is one of the best commented code ever :)
*/
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    //Double node structure
    struct Node* left;
    int data;
    struct Node* right;
};

struct Node* root;//root node

int main()
{
    while(1)
    {
        int ch;
        printf("\nEnter Choice:\n 1. Append\n 2. Insert at Beginning\n 3. Traverse\n 4. Insert at Position\n 5. Delete from position\n 6. Exit\n");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            append();
            break;
        case 2:
            insert_at_beginning();
            break;
        case 3:
            traverse();
            break;
        case 4:
            insert_at_position();
            break;
        case 5:
            delete_from_position();
            break;
        case 6:
            exit(1);
        default:
            printf("\nInvalid Choice\n");
            break;
        }
    }
}

int length()
{
    int count = 0;

    struct Node* p = root;
    //p is root,its right is pointing to node after p and the right of last node has NULL.
    while(p != NULL)//below we are changing value of 'p' to the value pointed by its 'right' attribute
    {
        count++;//as long 'p' is not null, count will increase
        p = p->right;//changing value of 'p' to what is pointed by its 'right' attribute
    }
    return count;
}

void append()
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));//creating node to be appended

    printf("\nEnter Node Data:\n");
    scanf("%d",&temp->data);//getting node data from user

    temp->left = NULL;//making its attributes null for safety purposes.
    temp->right = NULL;//as it is last node its right needs to be null, left is done "aahas" :)

    if(root == NULL)//if no elements in list, it will be first
    {
        root = temp;//temp is full fledged node and now just assigning it to root and we are done:)
        printf("\nNode Appended\n");
    }
    else
    {
        struct Node* p = root;//we need to go to the last node in the list and update it to point to new node created & defined above

        while(p->right != NULL)//if a node has null in its right then it is last node.
        {
            p = p->right;//changing value of p to the node pointed by its right attribute
        }

        p->right = temp;//making 'right' value of last element point to new node
        temp->left = p;//making our new node's 'left' value point to the last node and now our new node is the last node in the list

        printf("\nNode Appended\n");
    }
}

void traverse()
{
    printf("\nNumber of Nodes = %d",length());

    struct Node* p = root;

    printf("\nNods are:\n");
    while(p != NULL)
    {
        printf("%d-->",p->data);
        p = p->right;
    }
    printf("NULL");
}

void insert_at_beginning()
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    temp->left = NULL;
    temp->right = NULL;

    printf("\nEnter Node Data:\n");
    scanf("%d",&temp->data);

    if(root == NULL)//if list is empty then our node will be first one in it
    {
        root = temp;
        printf("\nNode Inserted at Beginning\n");
    }
    else
    {
        temp->right = root;//making new node point to root node
        root->left = temp;//making root node's left value point to our new node and now our node is the new root
        root = temp;//changing value of root variable to new value

        printf("\nNode Inserted at Beginning\n");
    }
}

void insert_at_position()
{
    int pos;

    printf("\nEnter position to insert value:\n");
    scanf("%d",&pos);

    if(pos>length() || root == NULL)//if wrong position or list empty
        printf("\nInvalid Position or List Empty\n");
    else
    {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->left = NULL;
        temp->right = NULL;

        printf("\nEnter Node Value:\n");
        scanf("%d",&temp->data);

        int i = 1;
        struct Node* p = root;

        while(i < pos-1)//going to the node after which new node is to be inserted(ti node jichya nantar navin node ghalaichi aahe).
        // if pos(position of new node) = 3
        //then we need p to point the node at position 2.
        //p is root and pointing to the node after it. p is node number 1 pointing to node number 2, we need it to point
        //it to node number 3 which is pointed by the value in its 'right' attribute. so here we need the loop to run only once.
        //that is we need 'i' to be 2 to terminate loop and 3-1=2 i.e. pos-1= where loop needs to be stopped
        {
            p = p->right;
            i++;
        }

        //our new node needs to be at position 3
        temp->right = p->right;//making our new node point to node at position 4

        p->right->left = temp;//p->right->left = p cha right jya node la point karto tya node chi 'left' attribute chi value = temp
        //munje node at position 4 cha left chi value temp munjech aapli new node. in short, node at position 4 pointing to our new node

        temp->left = p;//new node pointing to node before it

        p->right = temp;//node before our new node pointing to our new node
        //aaplya node chya aadhi chi node aaplya navin node la point karte

        printf("\nNode Inserted\n");

    }
}

void delete_from_position()
{
    if(root == NULL)
    {
        printf("\nList is Empty\n");
    }
    else
    {
        struct Node* p = root;//node jichya nantar chi node delete karaichi aahe
        struct Node* q = root;//node jichya aadhi chi node delete karaichi aahe
        //aata 'root' aahet pudhe point kartil. hya doghan madhe connection kela ki zala kaam

        int pos,i=1;

        printf("\nEnter position to delete:\n");
        scanf("%d",&pos);

        while(i < pos-1)
        {
            p = p->right;
            i++;
        }//p jithe tila aasaila pahije

        q = p->right->right;//q jithe tila aasaila pahije. remember like this referencing is also possible.

        q->left = p;//'q' point karte 'p' la aani
        p->right = q;//'p' point karte 'q' la
        //hya doghaan madhli node disconnected zali. kaam zala.

        printf("\nNode Deleted\n");
    }
}
