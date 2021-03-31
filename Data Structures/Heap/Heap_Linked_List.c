/*

Refer: Abdul Bari Algo Analysis video 2.6.3

Operations performed:
1. Creation
2. Insertion
3. Deletion
4. Sort -> We print it in descending order

To create Heap, we create a complete binary tree by inserting nodes level by level and with every insertion, we adjust the tree as per heap's requirement such that root will be be the greatest value.

For level by level insertion, we'll insert nodes left to right in a level, first create a node and enqueue it into a queue. Then if it's first node in tree, make it root and return. Insertion has 2 parts; 1. Creation and Enqueueing the node. In second part, we take first node from queue, note that we DO NOT dequeue it, we peek it and then we see that if it's left or right is absent and insert our node to be inserted there accordingly, we do insertions from left to right so do accordingly. Now that we have done insertion, we'll take the node peeked from queue and see if it has both left and right child and if yes, we dequeue it and we do insertion for next node in queue. Visualize this to understand better.

After a node is inserted irrespective to its value, we now adjust tree to satisfy heap condition. To do so, we'll take the inserted node and compare it with its parents until we reach root and if the node is bigger than its parent, we swap them, we do this until we reach root so eventually, we'll always have biggest value in root.



In heap, by law, we delete only root element. So now if root is deleted, we need to replace it with the biggest value present in heap. To do this, from the last level we remove elements from right to left and make root. Now to balance heap, we compare the root with its children and if any child is greater than root, we swap them.

That's the concept, Now, in below sort() function, there are lots of if's to avoid segmentation faults which might be tricky to understand :) ;)

*/

#include <stdio.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
};

struct Queue
{
    int front;
    int rear;
    int size;
    struct Node **array;
};

void insert_into_heap(int n, struct Node **root, struct Queue *queue);
void level_order(int size);
struct Queue *create_queue(int size);
void enqueue(struct Node *node, struct Queue *queue);
struct Node *dequeue(struct Queue *queue);
int is_full(struct Queue *queue);
int is_empty(struct Queue *queue);
int max(int a, int b);
void sort(int size);

struct Node *root;

int main()
{
    int array[] = {789,123,98,234,908,956,46,324,534,12,905,34,56764,4325};
    size_t array_size = sizeof(array) / sizeof(array[0]);

    struct Queue *queue = create_queue(array_size);

    for (int i = 0; i < array_size; i++)
        insert_into_heap(array[i], &root, queue);

    //level_order(array_size);

    sort(array_size);
}

void insert_into_heap(int n, struct Node **root, struct Queue *queue)
{
    //Node to be inserted creation
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = n;
    t->left = t->right = t->parent = NULL;

    //Putting node in queue, explained above.
    enqueue(t, queue);

    if (*root == NULL)
        *root = t;

    else
    {
        struct Node *p = queue->array[queue->front];

        //Inserting node left to right
        if (p->left == NULL)
        {
            p->left = t;
            t->parent = p;
        }
        else if (p->right == NULL)
        {
            p->right = t;
            t->parent = p;
        }

        //Checking and removing node if it has 2 children.
        if (p->left != NULL && p->right != NULL)
            dequeue(queue);

        //Adjusting tree
        adjust(t);
    }
}

void adjust(struct Node *node)
{
    struct Node *p = node;//Tempoarary navigation node.

    while (p != NULL)
    {
        if (p->parent != NULL)
        {
            //As explained above, compare newly inserted with parent and if its bigger than parent, swap.
            if (p->data > p->parent->data)
            {
                int t = p->data;
                p->data = p->parent->data;
                p->parent->data = t;
            }
        }

        p = p->parent;
    }
}

//Plain old level order traversal.
void level_order(int size)
{
    struct Queue *queue = create_queue(size);

    enqueue(root, queue);

    printf("\n");

    while (!is_empty(queue))
    {
        struct Node *p = dequeue(queue);

        printf(" %d ", p->data);

        if (p->left != NULL)
            enqueue(p->left, queue);

        if (p->right != NULL)
            enqueue(p->right, queue);
    }
}

//Method to sort heap, self written :)
void sort(int size)
{
    for (int i = 0; i < size-1; i++)//Repeating for number of elements.
    {
        int n = root->data;//Root is biggest element, its data, we just popped out.
       
        struct Node *p = root, *q = NULL;//temporary

        //As explained above, we'll remove nodes from last level from right to left. So here from root, we go to the rightmost element.
        while (p != NULL)
        {
            q = p;

            p = p->right;
        }

        //Now if the rightmost element has a left element and no right element, we go to it. It's a root->right node->left node scenario.
        if (q->left != NULL)
        {
                q = q->left;//If there is a node towards left of the rightmost node, we switch to it for making it root.

                //Below conditions occur for diagram represented below

/*
                                          (a)
										  /
										 /  
									    /    
									   (b)
									   /\
									  /  \
									 /    \
								   (c)   (d)
*/
                //Now above scenario does occur in case where right child of root becomes root and the tree becomes left skewed. In such case, the while() loop above won't run at all since there is no right element to root. The statement after it will bring us to (b). Now there do exist (c) and (d) so we got to them by below statements

                if(q->right != NULL)//If there's a right, go to it
                    q = q->right;

                if(q->left != NULL)//If there's a left, go to it.
                    q = q->left;
        }

        //Now that we have the node thats to be made root, we disconnect it from its parent first. Below statements check whether the node to be made root is towards left or right of its parent and disconnect it accordingly.
        if (q->parent != NULL && q->parent->left == q)
            q->parent->left = NULL;

        if (q->parent != NULL && q->parent->right == q)
            q->parent->right = NULL;

        //Making node to made root's pointers NULL
        q->parent = NULL;
        q->left = NULL;
        q->right = NULL;

        //This is essentially where root is replaced, although a swap should have been done, we are doing for simplicity purpose.
        root->data = q->data;

        //Now that there's a new root, we need to adjust the root
        //This code is broken, doesn't do adjusting properly
        if (root->left != NULL && root->right != NULL)
        {
            int m = max(root->left->data, root->right->data);

            if (root->data < m)
            {
                if (m == root->left->data)
                {
                    root->left->data = root->data;
                    root->data = m;
                }
                else if (m == root->right->data)
                {
                    root->right->data = root->data;
                    root->data = m;
                }
            }
        }
        else if(root->left != NULL)
        {
            if(root->data < root->left->data)
            {
                int t = root->data;
                root->data = root->left->data;
                root->left->data = t;
            }
        }
        else if(root->right != NULL)
        {
            if(root->data < root->right->data)
            {
                int t = root->data;
                root->data = root->right->data;
                root->right->data = t;
            }
        }

        printf(" %d ", n);
        p = NULL;
        q = NULL;
        n = -1;
    }
}


//Below are basic utility methods. A little thought and you'll get it.
struct Queue *create_queue(int size)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
    queue->size = size;

    queue->array = (struct Queue **)malloc(queue->size * sizeof(struct Node *));

    for (int i = 0; i < size; i++)
        queue->array[i] = NULL;

    return queue;
};

void enqueue(struct Node *node, struct Queue *queue)
{
    if (!is_full(queue))
    {
        queue->array[++queue->rear] = node;

        if (queue->front == -1)
            queue->front++;
    }
}

struct Node *dequeue(struct Queue *queue)
{
    if (is_empty(queue))
        return NULL;

    struct Node *temp = queue->array[queue->front];

    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front++;

    return temp;
}

int is_full(struct Queue *queue)
{
    return queue->rear == queue->size - 1;
}

int is_empty(struct Queue *queue)
{
    return queue->front == -1 && queue->rear == -1;
}

int max(int a, int b)
{
    return a > b ? a : b;
}