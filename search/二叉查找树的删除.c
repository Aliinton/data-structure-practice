#include "stdio.h"
#include "stdlib.h"

typedef enum{l, r}mark;
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

BiTree BTSearch(BiTree T, int k)
{
    BiTree N = T;
    while(N)
    {
        if(N->data == k)
            return N;
        else if(N->data > k)
            N = N->lchild;
        else
            N = N->rchild;
    }
    return N;
}

BiTree CreateBSTree(int *a, int l)
{
    int i;
    for(i = 0; i < l; i++)
    {
        BiTree
    }
}

void InOrderTraverse(BiTree T)
{
    if(T)
    {
        InOrderTraverse(T->lchild);
        printf("%d\t", T->data);
        InOrderTraverse(T->rchild);
    }
}

void PreOrderTraverse(BiTree T)
{
    if(T)
    {
        printf("%d\t", T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

BiTree GetParent(BiTree T, BiTree k)
{
    BiTree stack[100], N, p;
    int top = 0, flag;
    if(T == k)
        return NULL;
    stack[top++] = T;
    while(top)
    {
        while(N = stack[top - 1], N)
        {
            if(N == k)
                return stack[top - 2];
            stack[top++] = N->lchild;
        }
        flag = 1;
        p = stack[--top];
        while(top && flag)
        {
            N = stack[top - 1];
            if(N->rchild == p)
            {
                p = stack[--top];
                if(p == k)
                    return stack[top - 1];
            }
            else
            {
                stack[top++] = N->rchild;
                flag = 0;
            }
        }
    }
}

BiTree BSTreeDelete(BiTree T, int i)
{
    BiTree p, n, s;
    mark dir;
    p = BTSearch(T, i);
    n = GetParent(T, p);
    if(n)
    {
        if(n->lchild == p)
            dir = l;
        else
            dir = r;
    }
    if(p->lchild)
    {
        if(p->rchild)
        {
            s = p->lchild;
            while(s->rchild)
                s = s->rchild;
            if(n)
            {
                #if 1
                s->rchild = p->rchild;
                if(dir == l)
                    n->lchild = p->lchild;
                else
                    n->rchild = p->lchild;
                #else
                p->data = s->data;
                GetParent(T, s)->lchild = s->rchild;
                #endif
            }
            else
            {
                s->rchild = T->rchild;
                return T->lchild;
            }
        }
        else
        {
            if(n)
            {
                if(dir == l)
                    n->lchild = p->lchild;
                else
                    n->rchild = p->lchild;
            }
            else
                return T->lchild;

        }
    }
    else
    {
        if(p->rchild)
        {
            if(n)
            {
                if(dir == l)
                    n->lchild = p->rchild;
                else
                    n->rchild = p->rchild;
            }
            else
                return T->rchild;
        }
        else
        {
            if(n)
            {
                if(dir == l)
                    n->lchild = NULL;
                else
                    n->rchild = NULL;
            }
            else
                return NULL;
        }
    }
    free(p);
    return T;
}

BiTree BSTreeAdd(BiTree T, int k)
{
    BiTree n, p = T;
    n = (BiTree) malloc(sizeof(BiTNode));
    n->data = k;
    n->lchild = n->rchild = NULL;
    while(p)
    {
        if(p->data > k)
        {
            if(p->lchild)
                p = p->lchild;
            else
            {
                p->lchild = n;
                return T;
            }
        }
        else
        {
            if(p->rchild)
                p = p->rchild;
            else
            {
                p->rchild = n;
                return T;
            }
        }
    }
}

int main()
{
    BiTree T;
    int a[100], l, k, s;
    printf("BITREE\n");
    printf("0.exit\n1.create\n2.Pre\\InOrderTraverse\n3.search\n4.add\n5.delete\n");
    scanf("%d", &s);
    while(s)
    {
        if(s == 1)
        {
            l = 0;
            while(scanf("%d", &a[l]), a[l++] != -1);
            T = CreateBSTree(a, l - 1);
            printf("DONE\n");
        }
        else if(s == 2)
        {
            printf("PreOrderTraverse\n");
            PreOrderTraverse(T);
            printf("\nInOrderTraverse\n");
            InOrderTraverse(T);
            printf("\nDONE\n");
        }
        else if(s == 3)
        {
            printf("input elemnts you want to search, end up search with input 0\n");
            scanf("%d", &k);
            while(k)
            {
                if(BTSearch(T, k))
                    printf("%d\n", BTSearch(T, k)->data);
                else
                    printf("Not Found\n");
                scanf("%d", &k);
            }
        }
        else if(s == 4)
        {
            printf("Input the elements you want to add, input 0 to exit\n");
            scanf("%d", &k);
            while(k)
            {
                T = BSTreeAdd(T, k);
                printf("add %d successfully\n", k);
                scanf("%d", &k);
            }
        }
        else
        {
            scanf("%d", &k);
            while(k)
            {
                T = BSTreeDelete(T, k);
                printf("delete %d successfully\n", k);
                scanf("%d", &k);
            }
        }
        scanf("%d", &s);
    }
    system("pause");
    return 0;
}
/*100 90 110 80 95 92 105 120 106 115 130 -1*/