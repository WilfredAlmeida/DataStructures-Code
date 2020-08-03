/*

Refer: Abdul Bari DS

Program to count number of nodes in a binary tree

For creation simplification, BST is created :)
*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

void print_tree(struct Node *n);
void create_node(int val);
int get_node_count(struct Node *n);

struct Node* root = NULL;

int main()
{
    
    create_node(10);
    create_node(20);
    create_node(30);
    create_node(40);
    create_node(50);
    create_node(60);
    create_node(70);
    create_node(80);
    create_node(90);
    create_node(100);

    printf("\nTree is:\n");
    print_tree(root);
    
    printf("\nNode Count: %d", get_node_count(root));

    return 0;
}

void print_tree(struct Node *n)
{
    if(n)
    {
        printf(" %d ",n->data);

        print_tree(n->left);

        print_tree(n->right);
    }
}

void create_node(int val)
{
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = val;
    t->left = NULL;
    t->right = NULL;

    if(root == NULL)
        root = t;
    
    else
    {
        struct Node *p = root;
        struct Node *q;

        while(p != NULL)
        {
            q = p;
            if(t->data < p->data)
                p = p->left;
            else if(t->data > p->data)
                p = p->right;
        }

        if(t->data < q->data)
            q->left = t;
        else 
            q->right = t;
    }
}

int get_node_count(struct Node *n)
{
    if(n != NULL)
    {
        //node count of left subtree + count of right st + 1 for self
        int x = get_node_count(n->left);
        int y = get_node_count(n->right);

        return x+y+1;
    }
    return 0;
}
