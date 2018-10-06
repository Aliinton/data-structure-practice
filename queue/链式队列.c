#include "stdio.h"
#include "stdlib.h"
typedef struct Qnode
{
    int data;
    struct Qnode * next;
}Qnode;

typedef struct
{
    Qnode * front;
    Qnode * rear;
} LinkQueue;

LinkQueue InitQueue()
{
    LinkQueue Q;
    Q.front = Q.rear = (Qnode *) malloc (sizeof (Qnode));
    Q.front->next = NULL;
    printf("INITIALIZE QUEUE DONE\n");
    return Q;
}

LinkQueue EnQueue (LinkQueue Q, int e)
{
    Qnode * p;
    p = (Qnode *) malloc (sizeof (Qnode));
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    printf("DONE\n");
    return Q;
}

void DeQueue (LinkQueue *Q, int *e)
{
    Qnode * p;
    if(Q->front == Q->rear)
        printf("EMPTY QUEUE\n");
    else
    {
        p = Q->front->next;
        Q->front->next = p->next;
        if (Q->rear == p)
            Q->rear = Q->front;
        (*e) = p->data;
        free(p);
    }
}

int EmptyQueue (LinkQueue Q)
{
    if(Q.rear == Q.front)
        return 1;
    else
        return 0;
}

void aidprint(LinkQueue Q)
{
    Qnode *p = Q.front->next;
    while(p)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int i, e;
    LinkQueue Q;
    Q = InitQueue();
    for(i = 0; i <= 10; i++)
    {
       Q = EnQueue(Q, i);
    }
    aidprint(Q);
    for(i = 0; i <= 10; i++)
    {
        DeQueue(&Q, &e);
        printf("%d\t", e);
    }
    i = EmptyQueue(Q);
    printf("\n%d\n", i);
}
