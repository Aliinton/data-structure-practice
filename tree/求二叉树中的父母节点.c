#include "stdio.h"
#include "stdlib.h"

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

BiTree CreateBiTree(BiTree T, char ** ch)
{
    if(**ch == ' ')
    {
        (*ch)++;
        T = NULL;
    }
    else
    {
        if(!(T = (BiTree) malloc (sizeof(BiTNode))))
        {
            printf("ERROR\n");
            return NULL;
        }
        T->data = **ch;
        (*ch)++;
        T->lchild = CreateBiTree(T->lchild, ch);
        T->rchild = CreateBiTree(T->rchild, ch);
    }
    return T;
}

BiTree GetParent(BiTree T, char k)
{
    BiTree stack[100], N, p;
    int top = 0, flag;
    if(T->data == k)
        return NULL;
    stack[top++] = T;
    while(top)
    {
        while(N = stack[top - 1], N)
        {
            if(N->data == k)
                return stack[top - 2];
            stack[top++] = N->lchild;
        }
        p = stack[--top];
        flag = 1;
        while(top && flag)
        {
            N = stack[top - 1];
            #if 1
            if(N->rchild == p)
            {
                p = stack[--top];
                if(p->data == k)
                    return stack[top - 1];
            }
            else
            {
                stack[top++] = N->rchild;
                flag = 0;
            }
            #else
            if(N->rchild == p)
            {
                p = stack[--top];
            }
            else
            {
                if(N->rchild->data == k)
                    return N;
                else
                {
                    stack[top++] = N->rchild;
                    flag = 0;
                }
            }
            #endif
        }
    }
}

int main()
{
    BiTree T;
    char *a, k;
    a = (char *)malloc(sizeof(char) * 100);
    gets(a);
    T = CreateBiTree(T, &a);
    printf("GET PARENT\n");
    k = getchar();
    while(k)
    {
        getchar();
        if(GetParent(T, k))
            printf("%c\n\n", GetParent(T, k)->data);
        else
            printf("No Parent\n");
        k = getchar();
    }
    return 0;
}
