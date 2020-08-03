/*

Refer: Abdul Bari DS

To generate tree from traversals, we need 2 traversals: Inorder and Preorder

Algo(Geeks For Geeks):
1) Pick an element from Preorder. Increment a Preorder Index Variable 
   (preIndex in below code) to pick next element in next recursive call.

2) Create a new tree node tNode with the data as picked element.

3) Find the picked element’s index in Inorder. Let the index be inIndex.

4) Call buildTree for elements before inIndex and make the built tree as left 
   subtree of tNode.

5) Call buildTree for elements after inIndex and make the built tree as right 
   subtree of tNode.

6) return tNode.

*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

void print_tree(struct Node *t);
struct Node *build_tree(int *inorder, int *preorder,
                        int inorder_start, int inorder_end);
struct Node *new_node(int val);
int search(int *inorder, int start, int end, int val);

static int preorder_index = 0;

int main()
{
    int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};

    int len = sizeof(inorder) / sizeof(inorder[0]);

    struct Node *root = build_tree(inorder, preorder, 0, len-1);

    printf("\nPreorder Traversal of Tree formed:\n");
    print_tree(root);

    return 0;
}

void print_tree(struct Node *t)
{
    
    printf(" %d ", t->data);

    if(t->left != NULL)
        print_tree(t->left);

    if(t->right != NULL)
        print_tree(t->right);
}

struct Node *build_tree(int *inorder, int *preorder, int inorder_start, int inorder_end)
{
    if (inorder_end < inorder_start)
        return NULL;

    struct Node *n = new_node(preorder[preorder_index++]);

    int inorder_index = search(inorder, inorder_start, inorder_end, n->data);

    n->left = build_tree(inorder, preorder, inorder_start, inorder_index - 1);
    n->right = build_tree(inorder, preorder, inorder_index + 1, inorder_end);

    return n;
}

struct Node *new_node(int val)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = val;
    t->left = NULL;
    t->right = NULL;

    return t;
}

int search(int *inorder, int start, int end, int val)
{
    for (int i = start; i <= end; i++)
        if (inorder[i] == val)
            return i;

    return -1;
}