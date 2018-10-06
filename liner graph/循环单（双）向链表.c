#include "stdlib.h"
#include "stdio.h"

struct node1
{
    int data;
    struct node1 *next;
};

struct node2
{
    int data;
    struct node2 * next;
    struct node2 * prior;
};

//带尾指针的单循环链表（后进先出）
struct node1 * creatlist4 (int *e)
{
    struct node1 *head, *f, *tail;
    head = (struct node1 *) malloc (sizeof (struct node1));
    head->next = NULL;
    while (*e)
    {
        f = (struct node1 *) malloc (sizeof (struct node1));
        f->data = *e++;
        if(head->next)
            f->next = head->next;
        else
            f->next = head, tail = f;
        head->next = f;
    }
    return tail;
}

//带尾指针的单向循环链表（先进先出）
struct node1 * creatlist5 (int *e)
{
    struct node1 *head, *f, *tail;
    head = tail = (struct node1 *) malloc (sizeof (struct node1));
    while(*e)
    {
        f = (struct node1 *) malloc (sizeof (struct node1));
        f->data = *e++;
        tail->next = f;
        tail = f;
    }
    tail->next = head;
    return tail;
}

//带尾指针的双向循环链表（先进先出）
struct node2 * creatlist6 (int *e)
{
    struct node2 *head, *tail, *f;
    head = tail = (struct node2 *) malloc (sizeof (struct node2));
    while(*e)
    {
        f = (struct node2 *) malloc (sizeof(struct node2));
        f->data = *e++;
        f->prior = tail;
        tail->next = f;
        tail = f;
    }
    tail->next = head;
    head->prior = tail;
    return tail;
}

//带尾指针的双向循环链表（先进后出）
struct node2 * creatlist7 (int *e)
{
    struct node2 *head, *f, *tail;
    head = (struct node2 *)malloc(sizeof(struct node2));
    head->next = NULL;
    while(*e)
    {
        f = (struct node2 *) malloc (sizeof (struct node2));
        f->data = *e++;
        if(head->next)
        {
            f->next = head->next;
            f->prior = head;
            head->next->prior = f;
            head->next = f;
        }
        else
        {
            f->next = head, tail = f;
            head->next = f;
            f->prior = head;
            head->prior = tail;
        }
    }
    return tail;
}

void display1 (struct node1 * tail)
{
    struct node1 *p;
    p = tail->next->next;
    while(p != tail->next)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}

void display2 (struct node2 * tail)
{
    struct node2 *p;
    p = tail->next->next;
    while(p != tail->next)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int a[100], *e = a;
    struct node1 *tail1;
    struct node2 *tail2;
    scanf("%d", e);
    while(*e++)
        scanf("%d", e);
    tail1 = creatlist4(a);
    display1(tail1);
    tail1 = creatlist5(a);
    display1(tail1);
    tail2 = creatlist6(a);
    display2(tail2);
    tail2 = creatlist7(a);
    display2(tail2);
    return 0;
}
