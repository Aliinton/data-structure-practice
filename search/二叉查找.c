#include "stdio.h"
#include "stdlib.h"

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
    BiTree T, N, p;
    T = NULL;
    if(l)
    {
        T = (BiTree)malloc(sizeof(BiTNode));
        T->data = a[0];
        T->lchild = T->rchild = NULL;
    }
    for(i = 1; i < l; i++)
    {
        p = T;
        N = (BiTree) malloc (sizeof(BiTNode));
        N->data = a[i];
        N->lchild = N->rchild = NULL;
        while(p)
        {
            if(p->data > a[i])
            {
                if(!p->lchild)
                {
                    p->lchild = N;
                    break;
                }
                else
                    p = p->lchild;
            }
            else
            {
                if(!p->rchild)
                {
                    p->rchild = N;
                    break;
                }
                else
                    p = p->rchild;
            }
        }
    }
    return T;
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
int main()
{
    BiTree T;
    int a[100], l = 0, k;
    while(scanf("%d", &a[l]), a[l++] != -1);
    T = CreateBSTree(a, l - 1);
    InOrderTraverse(T);
    scanf("%d", &k);
    while(k)
    {
        if(BTSearch(T, k))
            printf("%d\n", BTSearch(T, k)->data);
        else
            printf("Not Found\n");
        scanf("%d", &k);
    }
    return 0;
}

