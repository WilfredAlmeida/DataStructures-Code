//Binary Search Tree
//For More: refer YouTube Naresh IT
/*

Operations Performed
1. Creation
2. Insertion
3. Deletion
4. Traversal -> Inorder, Preorder, Postorder, Level Order
5. Height(Displayed when Traversal is selected)

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//--------------------Start: Node structure and variables----------------------------
struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
    struct Node *ancestor;
};

int max(int a, int b);
int height(struct Node *node);
bool is_balanced(struct Node *node);
struct Node *right_rotate(struct Node *node);
struct Node *left_rotate(struct Node *node);
bool is_left_heavy(struct Node *node);
void balance_node(struct Node *node);

struct Node *root = NULL;
struct Node *parent; //node after which operations are needed to be performed like insertion/deletion. will get values accordingly

//--------------------End: Node structure and variables----------------------------

//--------------------Start: Queue structure and variables and method declaration------

//Queue is used in level order traversal to store memory addresses of BST nodes
struct queue
{
    struct Node *address;
    struct queue *next;
};

struct queue *front = NULL;
struct queue *rear = NULL;

struct Node *dequeue();
void enqueue(struct Node *eq);
bool is_empty();

//--------------------End: Queue structure and variables and method declaration------

//--------------------Start: Main Function------------------------------------------

int main()
{
    int ch;
    while (1)
    {
        printf("\nEnter your Choice:\n 1. Insert\n 2. Delete\n 3. Traverse\n 4. Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete_node();
            break;
        case 3:
            traverse();
            break;
        case 4:
            exit(1);
        default:
            printf("\nInvalid Choice\n");
        }
    }
}

//--------------------End: Main Function------------------------------------------

//--------------------Start: BST Methods- Insert, Delete, Traverse------------------

//--------------------Start: Insert Method------------------------------------------
void insert()
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->left = NULL;
    temp->right = NULL;
    temp->ancestor = NULL;

    printf("\nEnter Node Data:\n");
    scanf("%d", &temp->data);

    if (root == NULL) //if no elements in list, our node to be inserted will be root node
    {
        root = temp;
        printf("\nNode Inserted\n");
    }
    else //if there are elements in the list
    {
        struct Node *current = root;

        /*
           As stated above, 'parent' is the node after which we need to insert but we need parent to point to the last node
           in the list.

           So what we do here is, take another node current and make it point to next nodes in the list and store its parent
           in 'parent' variable. So when 'current' will be NULL i.e. we would have reached the end of the list and 'parent'
           would be pointing to the last node and then we will connect our node to be inserted to 'parent' and done.
         */

        while (current != NULL)
        {
            parent = current; //below, value of 'current' is updated as per certain conditions and as stated in above comment, we need
            //'parent' to point where it should, so we store value of current into parent before it goes NULL and then current will
            //go NULL we would have the value pointed by it before which is where we need to perform insertion

            if (temp->data > current->data) //As per BST's rule, if new node's value is greater than present node than it has to
                //be at right side of that node and if value is less, than new node has to be at the left of the present node

                current = current->right; //if new node's data is greater, than it has to go to right side of the node we are checking
            //and thus we are making current to go towards right side of present node.
            else
                current = current->left; //if value of new node is less than our current node than we make 'current' go towards left
                                         //side of present node.
        }

        if (temp->data > parent->data) //from above while loop when we will reach the last node after which insertion is to be performed,
            //we check if our new node goes to right or left side of the last node and do necessary connections
        {
            parent->right = temp; //making last node point to our new node
            temp->ancestor = parent;
        }

        else
        {
            parent->left = temp;
            temp->ancestor = parent;
            ;
        }
    }

    struct Node *t2 = temp;
    while (t2 != NULL)
    {
        if (is_balanced(t2))
            t2 = t2->ancestor;
        else
        {
            balance_node(t2);
            t2 = t2->ancestor;
        }
    }

    printf("\nNode Inserted\n");
}
//--------------------End: Insert Method------------------------------------------

//--------------------End: Delete Method------------------------------------------
void delete_node()
{
    if (root == NULL)
        printf("\nTree Empty\n");
    else
    {
        int val;
        printf("\nEnter value of node to be deleted:\n");
        scanf("%d", &val);

        struct Node *current = root; //current is node to be deleted

        while (current->data != val)
        {
            parent = current;

            if (val < current->data)
                current = current->left;
            else
                current = current->right;
        }
        if (current->left == NULL && current->right == NULL) //if val is leaf node
        {
            if (val < parent->data)
                parent->left = NULL;
            else
                parent->right = NULL;
        }
        else if (current->left != NULL && current->right == NULL) //val is node with one child on left side
        {
            current = current->left;

            if (current->data > parent->data)
                parent->right = current;
            else
                parent->left = current;
        }
        else if (current->right != NULL && current->left == NULL) //val is node with one child on right side
        {
            
            current = current->right;

            if (current->data > parent->data)
                parent->right = current;
            else
                parent->left = current;
        }
        else //node has children on both sides
        {
            //here we can replace node to be deleted with a node in 2 ways:
            //1. with smallest value from right sub tree
            //2. with greatest value from left sub tree
            //here we go with option 2: greatest value in left sub tree
            //no matter how big the value is, it will always be the LAST RIGHT node in the left sub tree.
            //imagine this with a tree example and you'll get it.

            //now we go to the last value
            struct Node *q = current; //required last node
            struct Node *p;           //parent of required last node

            while (q->right != NULL)
            {
                p = q;
                q = q->right;
            }
            p->right = NULL; //disconnecting required last node from parent

            q->left = current->left; //making required last node point to nodes pointed by 'current' node which is node to be deleted
            q->right = current->right;

            if (parent->left == current) //connecting last node to parent of node to be deleted
                parent->left = q;
            else
                parent->right = q;
        }

        check(root);

        printf("\nNode Deleted\n");
    }
}
//--------------------End: Delete Method------------------------------------------

//--------------------Start: Traverse Method--------------------------------------
void traverse()
{
    printf("\nHeight of tree:\n%d\n", height(root));

    int ch;
    printf("\nEnter Traversal Method:\n 1. Inorder Traversal\n 2. Preorder Traversal\n 3. Postorder Traversal\n 4. Levelorder Traversal\n");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        inorder(root); //see function definition for details
        break;
    case 2:
        preorder(root); //see function definition for details
        break;
    case 3:
        postorder(root); //see function definition for details
        break;
    case 4:
        levelorder(root);
        break;
    default:
        printf("\nInvalid Choice\n");
        break;
    }
}
//--------------------End: Traverse Method--------------------------------------

//--------------------Start: Sub methods of Traverse- Inorder, Preorder, Postorder,
//Listorder Traversal----------------------------------------------------------------

void inorder(struct Node *t) //Inorder Traverasl
{
    //Traverse order of inorder traversal is: left->parent->right. Here it is performed using recursive function
    /*

    so we first start at root node. order is left->parent->right so we have to first print data of left node.
    if left node has child nodes then left node among those nodes and so on until we reach the last node which has its
    left and right attributes as NULL

    So in line 1 below we check if there is any node to left of our given node. initially it will be root node.
    then, if there is left node then we pass the left node into inorder function and perform the same operation

    As per order, line 1,2 are for printing left side, 3 for parent, 4&5 for right side.

    */

    if (t->left != NULL)  //1
        inorder(t->left); //2

    printf(" %d ", t->data); //3

    if (t->right != NULL)  //4
        inorder(t->right); //5
}

void preorder(struct Node *t) //Preorder Traverasl
{
    //Traverse order in preorder traversal id: parent->left>right
    //We do the same thing explained above in inorder traversal just in desired order
    //Line 1 for parent, 2&3 for left side, 4&5 for right side

    printf(" %d ", t->data); //1

    if (t->left != NULL)   //2
        preorder(t->left); //3

    if (t->right != NULL)   //4
        preorder(t->right); //5
}

void postorder(struct Node *t) //Postorder Traverasl
{
    //traverse order for postorder traversal is: left->right->parent
    //We do same thine explained in inorder traversal just in different order

    if (t->left != NULL)
        postorder(t->left);

    if (t->right != NULL)
        postorder(t->right);

    printf(" %d ", t->data);
}

void levelorder(struct Node *t) //Levelorder Traverasl
{
    printf(" %d ", t->data);
    if (t->left != NULL)
        enqueue(t->left);
    if (t->right != NULL)
        enqueue(t->right);

    while (!is_empty())
    {
        levelorder(dequeue());
    }
}
//--------------------End: Sub methods of Traverse- Inorder, Preorder, Postorder,
//Listorder Traversal, Height------------------------------------------------------

//--------------------End: BST Methods- Insert, Delete, Traverse------------------

//--------------------------Start: Queue Methods- Isempty, Enqueue, Dequeue-----------

bool is_empty() //function to check if queue is empty
{
    if (front == NULL && rear == NULL)
        return true;
    return false;
}

//------------------------Start: Enqueue Method--------------------------------------
void enqueue(struct Node *en)
{
    struct queue *temp = (struct queue *)malloc(sizeof(struct queue));
    temp->address = en;
    temp->next = NULL;

    if (rear == NULL)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

//------------------------End: Enqueue Method--------------------------------------

//------------------------Start: Dequeue Method------------------------------------
struct Node *dequeue()
{
    struct queue *temp = front;
    if (front->next == NULL && front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
        front = front->next;

    return temp->address;
}

//------------------------End: Dequeue Method--------------------------------------

//------------------------End: Queue Methods- Isempty, Enqueue, Dequeue------------

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int height(struct Node *node)
{
    if (node == NULL)
        return -1;
    else
    {
        return max(height(node->left), height(node->right)) + 1;
    }
}

bool is_balanced(struct Node *node)
{
    int bal = height(node->left) - height(node->right);

    if (bal == -1 || bal == 0 || bal == 1)
        return true;

    return false;
}

bool is_left_heavy(struct Node *node)
{
    if (height(node->left) > height(node->right))
        return true;

    return false;
}

void balance_node(struct Node *node)
{
    if (node == root)
    {
        if (is_left_heavy(node))
            root = right_rotate(node);
        else
            root = left_rotate(node);
    }
    else
    {
        if (is_left_heavy(node))
            right_rotate(node);
        else
            left_rotate(node);
    }
}

struct Node *right_rotate(struct Node *node)
{
    struct Node *temp = node->left;

    if (temp->right != NULL)
    {
        temp->right->ancestor = node;
        node->left = temp->right;
    }
    else
    {
        node->left = NULL;
    }

    temp->ancestor = node->ancestor;
    node->ancestor = temp;

    temp->right = node;

    if (temp->ancestor != NULL)
        temp->ancestor->left = temp;

    return temp;
}

struct Node *left_rotate(struct Node *node)
{
    struct Node *temp = node->right;

    if (temp->left != NULL)
    {
        temp->left->ancestor = node;
        node->right = temp->left;
    }
    else
    {
        node->right = NULL;
    }

    temp->ancestor = node->ancestor;
    node->ancestor = temp;

    temp->left = node;

    if (temp->ancestor != NULL)
        temp->ancestor->right = temp;

    return temp;
}

void check(struct Node *node)
{
    if (is_balanced(node))
    {
        if (node->left != NULL)
            inorder(node->left);

        if (node->right != NULL)
            inorder(node->right);
    }
    else
    {
        balance_node(node);

        if (node->left != NULL)
            inorder(node->left);

        if (node->right != NULL)
            inorder(node->right);
    }
}