#include "stdio.h"
#include "stdlib.h"
#define STACK_INIT_SIZE 100
#define STACKINCERMENT 10
typedef int SElemType;
typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;

int InitStack (SqStack * S)
{
    S->base = (SElemType *) malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S->base) return 0;
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return 1;
}

int GetTop (SqStack *S, SElemType *e)
{
    if(S->base == S->top) return 0;
    else
    {
        *e = *(S->top-1);
        return 1;
    }
}

int Push (SqStack *S, SElemType e)
{
    if(S->top - S->base >= S->stacksize)
    {
        S->base = (SElemType *)realloc(S->base, (S->stacksize+STACKINCERMENT) * sizeof(SElemType));
        if (!S->base) return 0;
        S->top = S->base +S->stacksize;
        S->stacksize += STACKINCERMENT;
    }
    *S->top++ = e;
    return 1;
}

int Pop (SqStack *S, SElemType *e)
{
    if (S->base == S->top) return 0;
    else
    {
        *e = *(S->top--);
        return 1;
    }
}

void ClearStack(SqStack *S)
{
    S->top = S->base;
}

void DestroyStack(SqStack *S)
{
    free(S->base);
}

int StackEmpty (SqStack *S)
{
    if(S->base == S->top) return 1;
    else return 0;
}

void DisplayStack(SqStack * S)
{
    SElemType *p;
    p = S->top;
    while(p != S->base)
    {
        printf("%d\t", *--p);
    }
}

void main()
{
    SqStack S;
    int i = 0;
    InitStack(&S);
    scanf("%d", &i);

    for (i = 0; i <100000; i++)
    {
        Push(&S, i);
    }
    DisplayStack(&S);
    DestroyStack(&S);
}
