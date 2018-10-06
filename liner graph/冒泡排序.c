#include "stdio.h"
#include "stdlib.h"
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define SWAP(a,b) a = a + b, b = a - b, a = a - b
typedef int ElemType;
typedef struct
{
    ElemType * base;
    int length;
    int listsize;
} SqList;

int InitList (SqList *L)
{
    L->base = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L->base) return 0;
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return 1;
}

int PutElem (SqList *L, ElemType e)
{
    if (L->length >= L->listsize)
    {
        L->base = (ElemType *) realloc (L->base, (L->listsize + LISTINCREMENT) * sizeof (ElemType));
        if(!L->base) return 0;
        L->listsize += LISTINCREMENT;
    }
    *(L->base + L->length ++) = e;
}

void PrintList (SqList * L)
{
    int i;
    ElemType *p = L->base;
    for (i = 0; i < L->length; i ++)
    {
        printf("%d\t", *(p + i));
    }
}

void SortHTL (SqList * L)
{
    int i, k;
    for (i = 0; i < L->length - 1; i++)
        for(k = 0; k < L->length - 1 - i; k++)
            if (*(L->base + k) < *(L->base + k + 1))
                SWAP (*(L->base + k), *(L->base + k + 1));
}

int main()
{
    int e = 0;
    SqList L;
    InitList (&L);
    scanf ("%d", &e);
    while (e)
    {
        PutElem (&L, e);
        scanf("%d", &e);
    }
    SortHTL(&L);
    PrintList(&L);
    free(L.base);
    return 0;
}
