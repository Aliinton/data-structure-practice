#include "stdio.h"
#include "stdlib.h"
#define INIT_STACK_SIZE 100
#define STACKINCREMENT 10
#define ERROR 0
#define OK 1
#define TESTSIZE 111
typedef struct
{
    int * base;
    int top;
    int stacksize;
} SqStack;

int InitStack (SqStack * S)
{
    S->base = (int *) malloc (INIT_STACK_SIZE * sizeof (int));
    if (!S->base)
    {
        printf("OVERFLOW\n");
        return ERROR;
    }
    else
    {
        printf("INITIALIZE DONE\n");
        S->stacksize = INIT_STACK_SIZE;
        S->top = 0;
        return OK;
    }
}

int Push(SqStack * S, int e)
{
    if (S->top >= S->stacksize)
    {
        S->base = (int *) realloc (S->base, (S->stacksize + STACKINCREMENT) * sizeof (int));
        if (!S->base)
        {
            printf("OVERFLOW\n");
            return ERROR;
        }
        else
        {
            printf("INCRESE STACK SIZE DONE\n");
            S->stacksize += STACKINCREMENT;
        }

    }
    S->base[S->top] = e;
    S->top ++;
    return OK;
}

int Pop(SqStack *S, int *e)
{
    if(S->top == 0)
    return ERROR;
    else
    {
        S->top--;
        *e = S->base[S->top];
        return OK;
    }
}

int GetTop(SqStack *S, int *e)
{
    if (S->top == 0)
        return ERROR;
    else
    {
        *e = S->base[S->top-1];
        return OK;
    }
}

int main()
{
    int i, a;
    SqStack S;
    InitStack(&S);
    for(i = 0; i <= TESTSIZE; i++)
    {
        Push(&S, i);
    }
    GetTop(&S, &a);
    printf("%d\n", a);
    for(i = 0; i <= TESTSIZE; i++)
    {
        Pop(&S, &a);
        printf("%d\t", a);
    }
    printf("\n");
    return 0;
}
