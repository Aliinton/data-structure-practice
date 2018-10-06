#include "stdio.h"
#include "stdlib.h"

#define MAX_TREE_SIZE 100

typedef char TElemType;

//链式结构
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode * lchild;
    struct BiTNode * rchild;
}BiTNode, * BiTree;

//仔细体会参数的选择
BiTree CreateBiTree(BiTree T, char ** ch)
{
    if(**ch == ' ')
    {
        T = NULL;
        (*ch)++;
    }
    else
    {
        if(!(T = (BiTree) malloc (sizeof (BiTNode)))) printf("OVERFLOW\n");
        T->data = **ch;
        (*ch)++;
        T->lchild = CreateBiTree(T->lchild, ch);  //注意此处必须要将返回值赋予T->lchild, 否则它将指向垃圾内存
        T->rchild = CreateBiTree(T->rchild, ch);  //同上
    }
    return T;
}

void POT(BiTree T)
{
    if(T)
    {
        POT(T->lchild);
        POT(T->rchild);
        printf("%c", T->data);
    }
}

void INT(BiTree T)
{
    if(T)
    {
        INT(T->lchild);
        printf("%c", T->data);
        INT(T->rchild);
    }
}

void PRT(BiTree T)
{
    if(T)
    {
        printf("%c", T->data);
        PRT(T->lchild);
        PRT(T->rchild);
    }
}

int main()
{
    BiTree T;
    char * ch;
    ch = (char *) malloc (sizeof (char) * 100);
    gets(ch);
    T = CreateBiTree(T, &ch);
    printf("PreOrederTraverse\n");
    PRT(T);
    printf("\nInOrderTraverse\n");
    INT(T);
    printf("\nPostOrderTraverse\n");
    POT(T);
    free(T);
    free(ch);
    return 0;
}
