#include "stdio.h"
#include "stdlib.h"
struct node
{
    int data;
    struct node *next;
};

struct node * creatlist1 (int *e)
{
    struct node *head, *tail, *f;
    tail = head = (struct node *)malloc(sizeof(struct node));
    while (*e)
    {
        f = (struct node *)malloc(sizeof(struct node));
        f->data = *e++;
        tail->next = f;
        tail = f;
    }
    tail->next = NULL;
    return head;
}

int insert (struct node *head, int e, int i)
{
    int j;
    struct node *p = head, *f;
    f = (struct node *)malloc(sizeof(struct node));
    f->data = e;
    f->next = NULL;
    for (j = 1; j < i; j++)
        p = p->next;
    if(p == NULL || i < 1) return 0;
    else
    {
        f->next = p->next, p->next = f;
        return 1;
    }
}

//删除指定大小元素
int Delete1 (struct node * head, int e)
{
    struct node *q = head, *p = head->next;
    while (p && p->data != e)
    {
        q = p;
        p = p->next;
    }
    if (p)
    {
        q->next = p->next;
        free(p);
        return 1;
    }
    else return 0;

}

//删除指定位置元素
int Delete2 (struct node * head, int i)
{
    int j;
    struct node *p = head, *d;
    for(j = 1; j < i; j++)
        p = p->next;
    if(p == NULL || i < 1) return 0;
    else
    {
        d = p->next;
        p->next = d->next;
        free(d);
        return 1;
    }
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
    int a[100], *e = a;
    struct node *headp;
    scanf("%d", e);
    while(*e++)
        scanf("%d", e);
    headp = creatlist1(a);
    insert(headp, 0, 1);
    display(headp->next);
    Delete2(headp, 1);
    display(headp->next);
    insert(headp, 4, 4);
    display(headp->next);
    Delete1(headp, 4);
    display(headp->next);
    return 0;
}
