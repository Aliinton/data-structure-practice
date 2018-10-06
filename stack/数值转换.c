#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#define org 8
#define tgt 2
#define ERROR 0
#define OK 1
#define INIT_STACK_SIZE 10
#define STACKINCERMENT 10
typedef struct
{
    int *base;
    int stacksize;
    int top;
}SqStack;

void InitStack(SqStack * S)
{
    S->base = (int *) malloc (INIT_STACK_SIZE * sizeof (int));
    S->top = 0;
    S->stacksize = INIT_STACK_SIZE;
    printf("INITIALIZE STACK DONE\n");
}

int Push(SqStack *S, int e)
{
    if(S->top >= S->stacksize)
    {
        S->base = (int *) realloc (S->base, (S->stacksize + STACKINCERMENT) * sizeof (int));
        if (!S->base)
        {
            printf("INCRESE STACK FAILED\n");
            return ERROR;
        }
        else
        {
            printf("INCRESE STACK DONE\n");
            S->stacksize  += STACKINCERMENT;
        }
    }
    S->base[S->top] = e;
    S->top++;
    return OK;
}

int Pop(SqStack * S, int * e)
{
    if (S->top == 0)
    {
        printf("STACK EMPTY\n");
        return ERROR;
    }
    else
    {
        *e = S->base[--S->top];
        return OK;
    }
}

int main()
{
    int a, x , y, i;
    SqStack S;
    InitStack(&S);
    x = y = i = 0;
    scanf("%d", &a);
    while(a > 0)
    {
        x += (a%10) * pow(org, i++);
        a /= 10;
    }
    while(x > 0)
    {
        Push(&S, x%tgt);
        x /= tgt;
    }
    while(S.top)
    {
        Pop(&S, &y);
        printf("%d", y);
    }
    printf("\n");
    return 0;
}
