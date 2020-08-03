// /*

// Refer: Abdul Bari DS

// Polynomial Expression:
//     3x^5 + 2x^4 + 5x^2 + 2x + 7

// */

//See this for comments, working code is below this, no change just some syntax errors:):(

// #include <stdio.h>
// #include <stdlib.h>

// struct Term
// {
//     int coeff; //Coefficient of Polynomail
//     int exp;   //Exponent of Polynomail
// };

// struct Poly
// {
//     int n;          //Number of terms in polynomail. Term = "3x^2", this whole is a term
//     struct Term *t; //Dynaimc array of terms
// };

// void create(struct Poly *p);
// void display(struct Poly p);
// struct Poly *add_polynomials(struct Poly *p1, struct Poly *p2);

// int main()
// {

//     struct Poly p1, p2, *sum;

//     create(&p1);
//     create(&p2);

//     sum = add_polynomials(&p1, &p2);

//     printf("\nPolynomail 1:\n");
//     display(p1);

//     printf("\nPolynomail 2:\n");
//     display(p2);

//     printf("\nSum is:\n");
//     display(*sum);

//     return 0;
// }

// void create(struct Poly *p)
// {
//     printf("\nEnter Number of Terms:\n"); //Number of elements in Polynomial
//     scanf("%d", &p->n);

//     p->t = (struct Term *)malloc(p->n * sizeof(struct Poly)); //Array of terms

//     printf("\nEnter all Terms:\n");

//     for (int i = 0; i < p->n; i++) //reading values of coefficient and exponent
//         scanf("%d %d", &p->t[i].coeff, &p->t[i].exp);
// }

// void display(struct Poly p)
// {
//     printf("Polynomial is:\n");
//     for (int i = 0; i < p.n; i++)
//     {
//         if (i != 0)
//             printf(" + ");
//         printf("%dx%d", p.t[i].coeff, p.t[i].exp); //x is not multiply,its 'x' of algebra
//     }
//     printf("\n");
// }

// struct Poly *add_polynomials(struct Poly *p1, struct Poly *p2)
// {
//     struct Poly *sum;

//     int i=j=k=0;

//     sum->t = (struct Term*)sizeof((struct Term * (p1->n + p2->n));

//     while(i<p1->n && j<p2->n)
//     {
//         if(p1->t[i].exp > p2->t[j].exp)//if p1.exp > p2.exp, copy p1 in sum polynomial
//         {
//             sum->t[k].exp = p1->t[i].exp;
//             sum->t[k].coeff = p1->t[i].coeff;
//             ++i;
//             ++k;
//         }
//         else if(p1->t[i].exp < p2->t[j].exp)//if p2.exp > p1.exp, copy p2 in sum polynomial
//         {
//             sum->t[k].exp = p2->t[j].exp;
//             sum->t[k].coeff = p2->t[j].coeff;
//             ++j;
//             ++k;
//         }
//         else //both exponents are equal, add coefficients
//         {
//             sum->t[k].exp = p1->t[i].exp;
//             sum->t[k].coeff = p1->t[i].coeff + p2->t[j].coeff;
//             ++i;
//             ++j;
//             ++k;
//         }
//     }

//     for(;i<p1->n;i++)
//         sum->t[k++] = p1->t[i];

//     for(;j<p2->n;j++)
//         sum->t[k++] = p2->t[j];

//     sum->n = k;

//     return sum;
// }

#include <stdio.h>
#include <stdlib.h>
    struct Term
{
    int coeff;
    int exp;
};
struct Poly
{
    int n;
    struct Term *terms;
};
void create(struct Poly *p)
{
    int i;
    printf("Number of terms?");
    scanf("%d", &p->n);
    p->terms = (struct Term *)malloc(p->n * sizeof(struct
                                                   Term));

    printf("Enter terms\n");
    for (i = 0; i < p->n; i++)
        scanf("%d%d", &p->terms[i].coeff, &p->terms[i].exp);
}
void display(struct Poly p)
{
    int i;
    for (i = 0; i < p.n; i++)

        printf("%dx%d+", p.terms[i].coeff, p.terms[i].exp);
    printf("\n");
}
struct Poly *add(struct Poly *p1, struct Poly *p2)
{
    int i, j, k;
    struct Poly *sum;

    sum = (struct Poly *)malloc(sizeof(struct Poly));
    sum->terms = (struct Term *)malloc((p1->n + p2->n) *sizeof(struct Term));
    i = j = k = 0;

    while (i < p1->n && j < p2->n)
    {
        if (p1->terms[i].exp > p2->terms[j].exp)
            sum->terms[k++] = p1->terms[i++];
        else if (p1->terms[i].exp < p2->terms[j].exp)
            sum->terms[k++] = p2->terms[j++];
        else
        {
            sum->terms[k].exp = p1->terms[i].exp;
            sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
        }
    }
    for (; i < p1->n; i++)
        sum->terms[k++] = p1->terms[i];
    for (; j < p2->n; j++)
        sum->terms[k++] = p2->terms[j];

    sum->n = k;
    return sum;
}
int main()
{
    struct Poly p1, p2, *p3;

    create(&p1);
    create(&p2);

    p3 = add(&p1, &p2);

    printf("\n");
    display(p1);
    printf("\n");
    display(p2);
    printf("\n");
    display(*p3);

    return 0;
}