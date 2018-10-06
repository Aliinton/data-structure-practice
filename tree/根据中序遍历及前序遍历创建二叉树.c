#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode , *BiTree;

int find(char tar, char * s)
{
    int i = 0;
    while(s[i++] != tar);
    return i - 1;
}

BiTree CreateBiTree(BiTree T, char *pre, char *in)
{
    int loc;
    char root, *lpre, *rpre, *lin, *rin;
    if(!strlen(pre))
        return NULL;
    root = *pre;
    loc = find(root, in);
    T = (BiTree) malloc(sizeof (BiTNode));
    T->data = root;
//�����ʵ������ռ�
    lpre = (char *)malloc(sizeof(char) * (loc + 1));
    lin = (char *)malloc (sizeof (char) * (loc + 1));
    rin = (char *)malloc (sizeof (char) * (strlen(pre) - loc));
    rpre = (char *)malloc (sizeof(char) * (strlen(in) - loc));
//�ָ�pre����
    pre++;
    memcpy(lpre, pre, loc);
    lpre[loc] = '\0';
    pre += loc;
    strcpy(rpre, pre);
//�ָ�in����
    memcpy(lin, in, loc);
    lin[loc] = '\0';
    in = loc + 1 + in;
    strcpy(rin, in);
//�ݹ鴦��
    T->lchild = CreateBiTree(T->lchild, lpre, lin);
    T->rchild = CreateBiTree(T->rchild, rpre, rin);
    return T;
}
void PostOrderTraverse(BiTree T)
{
    if(T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%c", T->data);
    }
}

int main()
{
    char pre[100], in[100];
    BiTree T;
    gets(pre);
    gets(in);
    T = CreateBiTree(T, pre, in);
    PostOrderTraverse(T);
    return 0;
}
