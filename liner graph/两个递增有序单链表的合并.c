#include "stdio.h"
#include "stdlib.h"
struct node
{
    int data;
    struct node *next;
};

struct node * creatlist1(int *e)
{
    struct node * head, * tail, *f;
    head = tail = (struct node *) malloc (sizeof (struct node));
    while (*e)
    {
        f = (struct node *) malloc (sizeof (struct node));
        f->data = *e++;
        tail->next = f;
        tail = f;
    }
    tail->next = NULL;
    return head;
}

struct node * creatlist2 (int *e)
{
    struct node * head, *f;
    head = (struct node *) malloc (sizeof (struct node));
    head->next = NULL;
    while (*e)
    {
        f = (struct node *) malloc (sizeof (struct node));
        f->data = *e++;
        f->next = head->next;
        head->next = f;
    }
    return head;
}

struct node * unionlist (struct node * heada, struct node * headb)
{
    struct node * pa = heada->next, * pb = headb->next, *pc = heada;
    free (headb);
    while (pa && pb)
    {
        if(pa->data < pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    if (pa) pc->next = pa;
    else pc->next = pb;
    return heada;
}

void display (struct node * p)
{
    while (p)
    {
        printf ("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int a[100], *e = a;
    struct node *heada, *headb;
    scanf ("%d", e);
    while (*e++)
        scanf ("%d", e);
    heada = creatlist1 (a);
    display (heada->next);
    headb = creatlist1 (a);
    display (headb->next);
    unionlist(heada, headb);
    display(heada->next);
    return 0;
}
