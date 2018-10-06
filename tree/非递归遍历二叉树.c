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

void PreOrderTraverse(BiTree T)
{
    BiTree stack[100], R;
    int top = 0;
    if(T)
        stack[top++] = T;
    while(top)
    {
        R = stack[--top];
        printf("%c", R->data);
//注意压栈的顺序，以及要判断左右子树是否为空
        if(R->rchild) stack[top++] = R->rchild;
        if(R->lchild) stack[top++] = R->lchild;
    }
}

void InOrderTraverse(BiTree T)
{
    BiTree stack[100], R;
    int top = 0;
    if(T)
        stack[top++] = T;
    while(top)
    {
        while(R = stack[top - 1], R)
            stack[top++] = R->lchild;
        top--;
        if(top)
        {
            R = stack[--top];
            printf("%c", R->data);
            stack[top++] = R->rchild;
        }
    }
}

void PostOrderTraverse(BiTree T)
{
    BiTree stack[100], R, p;
    int top = 0, flag;
    if(T)
        stack[top++] = T;
    while(top)
    {
        while(R = stack[top - 1], R)
            stack[top++] = R->lchild;
        flag = 1;
        p = stack[--top];
        while(flag && top)
        {
            R = stack[top - 1];
            if(R->rchild == p)
            {
                p = stack[--top];
                printf("%c", p->data);
            }
            else
            {
                flag = 0;
                stack[top++] = R->rchild;
            }
        }
    }
}

int main()
{
    char * a;
    BiTree T;
    a = (char *)malloc(sizeof(char) * 100);
    gets(a);
    T = CreateBiTree(T, &a);
    PreOrderTraverse(T);
    printf("\n");
    InOrderTraverse(T);
    printf("\n");
    PostOrderTraverse(T);
    printf("\n");
}
