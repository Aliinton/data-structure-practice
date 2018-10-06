#include "stdio.h"
#include "stdlib.h"
struct node
{
    int data;
    struct node * next;
};

void creatlist3 (struct node *head, int e)
{
    struct node *q = head, *p = head->next, *f;
    while (p && p->data <= e)  //注意此处应当先行判断p是否为空
    {
        q = p;
        p = p->next;
    }
    f = (struct node *)malloc(sizeof(struct node));
    f->data = e;
    f->next = NULL;
    if (p)
        q->next = f, f->next = p;
    else
        q->next = f;
}

void display(struct node *p)
{
    while(p)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct node *headp;
    int e;
    headp = (struct node *)malloc(sizeof(struct node));
    headp->next = NULL;
    scanf("%d", &e);
    while(e)
    {
        creatlist3(headp, e);
        scanf("%d", &e);
    }
    display(headp->next);
    return 0;
}
