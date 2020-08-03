/*

Refer: Abdul Bari DS

Sparse Matrix: Matrix in which most of the elements are zero.

*/

#include <stdio.h>
#include <stdlib.h>

struct element
{
    int i;
    int j;
    int x;
};

struct matrix
{
    int m;
    int n;
    int num;
    struct element *e;
};

void create_matrix(struct matrix *s);
void display(struct matrix s);

int main()
{
    struct matrix s;

    create_matrix(&s);

    display(s);

    return 0;
}

void create_matrix(struct matrix *s)
{
    printf("\nEnter matrix dimensions and number of elements:\n");
    scanf("%d %d %d", &s->m, &s->n, &s->num);

    s->e = (struct element *)malloc(sizeof(s->e) * s->num);

    for (int i = 0; i < s->num; i++)
    {
        printf("Enter element %d:\n", i);
        scanf("%d %d %d", &s->e[i].i, &s->e[i].j, &s->e[i].x);
    }
}

void display(struct matrix s)
{
    int i, j, k = 0;

    printf("\nMatrix is:\n");

    for (i = 0; i < s.m; i++)
    {
        for (j = 0; j < s.n; j++)
        {
            if (i == s.e[k].i && j == s.e[k].j)
                printf("%d ", s.e[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
}