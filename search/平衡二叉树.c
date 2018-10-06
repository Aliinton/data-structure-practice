#include "stdio.h"
#include "stdlib.h"
#include "math.h"

typedef struct AVLNode
{
    int data;
    struct AVLNode* lchild, *rchild;
}AVLNode, *AVLTree;

AVLTree LL(AVLTree T)
{
    AVLTree temp = T->lchild;
    T->lchild = temp->rchild;
    temp->rchild = T;
    return temp;
}

AVLTree RR(AVLTree T)
{
    AVLTree temp = T->rchild;
    T->rchild = temp->lchild;
    temp->lchild = T;
    return temp;
}

AVLTree LR(AVLTree T)
{
    T->lchild = RR(T->lchild);
    T = LL(T);
    return T;
}

AVLTree RL(AVLTree T)
{
    T->rchild = LL(T->rchild);
    T = RR(T);
    return T;
}

int h(AVLTree T)
{
    int hl, hr;
    if(T == NULL)
        return 0;
    else
    {
        hl = h(T->lchild);
        hr = h(T->rchild);
        return (hl > hr ? hl : hr) + 1;
    }
}

AVLTree AVLTree_Insert(AVLTree T, int x)
{
    if(T == NULL)
    {
        T = (AVLTree) malloc(sizeof(AVLNode));
        if(T)
        {
            T->data = x;
            T->lchild = T->rchild = NULL;
        }
        else
        {
            printf("OVERFLOW\n");
        }
    }
    else if(x < T->data)
    {
        T->lchild = AVLTree_Insert(T->lchild, x);
        if(h(T->lchild) - h(T->rchild) == 2)
        {
            if(T->lchild->data > x)
            {
                T = LL(T);
            }
            else
                T = LR(T);
        }
    }
    else if(x > T->data)
    {
        T->rchild = AVLTree_Insert(T->rchild, x);
        if(h(T->rchild) - h(T->lchild) == 2)
        {
            if(T->rchild->data > x)
            {
                T = RL(T);
            }
            else
                T = RR(T);
        }
    }
    else
        printf("%d already exist in the tree\n", x);
    return T;
}

AVLTree AVLTree_Delete(AVLTree T, int x)
{
    AVLTree stack[100], N = T, NP, S, SP;
    int top = 0;
//寻找待删除元素，并把搜索路径压栈
    while(N->data != x)
    {
        if(N->data > x)
        {
            stack[top++] = N;
            N = N->lchild;
        }
        else
        {
            stack[top++] = N;
            N = N->rchild;
        }
    }
    NP = stack[top - 1];
//执行删除操作
    if(N->lchild)
    {
        if(N->rchild)
        {
            stack[top++] = N;
            S = N->lchild;
            while(S)
            {
                stack[top++] = S;
                S = S->rchild;
            }
            S = stack[--top];
            N->data = S->data;
            if(stack[top - 1] == N)
                N->lchild = NULL;
            else
                stack[top - 1]->rchild = S->lchild;
        }
        else
        {
            if(NP->lchild == N)
                NP->lchild = N->lchild;
            else
                NP->rchild = N->lchild;
        }
    }
    else
    {
        if(N->rchild)
        {
            if(NP->lchild == N)
                NP->lchild = N->rchild;
            else
                NP->rchild = N->rchild;
        }
        else
        {
            if(NP->lchild == N)
                NP->lchild = NULL;
            else
                NP->rchild =NULL;
        }
    }
//回溯处理到根节点，进行平衡化处理直到栈为空
    while(top)
    {
        S = stack[--top];
        SP = stack[top - 1];
        if(h(S->lchild) - h(S->rchild) > 1)
        {
            if(h(S->lchild->lchild) < h(S->lchild->rchild))
            {
                S->lchild = RR(S->lchild);
            }
            if(SP->lchild == S)
                SP->lchild = LL(S);
            else
                SP->rchild = LL(S);
        }
        if(h(S->rchild) - h(S->lchild) > 1)
        {
            if(h(S->rchild->lchild) > h(S->rchild->rchild))
            {
                S->rchild = LL(S->lchild);
            }
            if(SP->lchild == S)
                SP->lchild = RR(S);
            else
                SP->rchild = RR(S);
        }
    }
    return T;
}

void InOrderTraverse(AVLTree T)
{
    if(T)
    {
        InOrderTraverse(T->lchild);
        printf("%d\t", T->data);
        InOrderTraverse(T->rchild);
    }
}

void PreOrderTraverse(AVLTree T)
{
    if(T)
    {
        printf("%d\t", T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

int main()
{
    int x, selction;
    AVLTree T = NULL;
    printf("AVL TREE\n0.EXIT\n1.CREATE\n2.INSERT\n3.DELETE\n4.CLEAR THE AVL TREE\n5.PREORDERTRAVERSE AND INORDERTEAVERSE\n");
    scanf("%d", &selction);
    while(selction)
    {
        if(selction == 1)
        {
            printf("INPUT NUMBERS WITH 0 AS END MARK\n");
            scanf("%d", &x);
            while(x)
            {
                T = AVLTree_Insert(T, x);
                scanf("%d", &x);
            }
            printf("DONE\n");
        }
        else if(selction == 2)
        {
            scanf("%d", &x);
            T = AVLTree_Insert(T, x);
            printf("DONE\n");
        }
        else if(selction == 3)
        {
            scanf("%d", &x);
            T = AVLTree_Delete(T, x);
            printf("DONE\n");
        }
        else if(selction == 4)
        {
            free(T);
            T = NULL;
            printf("DONE\n");
        }
        else if(selction == 5)
        {
            printf("InOrderTraverse\n");
            InOrderTraverse(T);
            printf("\nPreOrderTraverse\n");
            PreOrderTraverse(T);
            printf("\n");
        }
        else
            printf("NO SUCH SELECTION\n");
        scanf("%d", &selction);
    }
}

