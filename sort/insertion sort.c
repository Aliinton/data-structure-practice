#include "stdio.h"
#include "stdlib.h"

typedef struct node
{
    int data;
    struct node *next;
}Node, *List;

//升序插入
void Insert_Sort(int n, List *l)
{
    List head = *l;
    Node *q = head, *p = head->next, *r;
    r = (List) malloc (sizeof(Node));
    r->data = n;
    r->next = NULL;
    while(p)
    {
        if(p->data < n)
        {
            q = p;
            p = p->next;
        }
        else
            break;
    }
    r->next = q->next;
    q->next = r;
    *l = head;
}

int main()
{
    int element;
    Node *head, *p;
    head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    printf("input the numbers you want to sort(end up with 0)\n");
    scanf("%d", &element);
    while(element)
    {
        Insert_Sort(element, &head);
        scanf("%d", &element);
    }
    p = head->next;   
    while(p)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
    system("pause");
    return 0; 
}