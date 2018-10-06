#include "stdio.h"
#include "stdlib.h"
#define OK 1
struct node
{
    int data;
    struct node *next;
} * top = NULL;

int Push(int e)
{
    struct node *f;
    f = (struct node *) malloc (sizeof (struct node));
    f->data = e;
    f->next = top;
    top = f;
    return OK;
}

int Pop(int *e)
{
    struct node *p;
    p = top;
    *e = p->data;
    top = top->next;
    free(p);
    return OK;
}

int main()
{
    int i, e;
    for (i = 0; i <= 100; i++)
        Push(i);
    for (i = 0; i <= 100; i++)
    {
       Pop(&e);
       printf("%d\t", e);
    }
    return 0;
}
