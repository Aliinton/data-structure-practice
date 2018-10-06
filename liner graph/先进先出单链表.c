#include "stdio.h"
#include "stdlib.h"
struct node
{
    int data;
    struct node * next;
};

struct node * creatlist1 (int *e)
{
    struct node *head, *tail, *p;
    head = tail = (struct node *)malloc(sizeof(struct node));
    while (*e)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = *e++;
        tail->next = p;
        tail = p;
    }
    tail->next = NULL;
    return head;
}

struct node *creatlist2 (int *e)
{
    struct node *head, *p;
    head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;
    while(*e)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = *e++;
        p->next = head->next;
        head->next = p;
    }
    return head;
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
    display(headp->next);
    headp = creatlist2(a);
    display(headp->next);
    return 0;
}
