#include "stdio.h"
#include "stdlib.h"
#define STACK_INIT_SIZE 100
#define STACKINCERMENT 10
typedef struct
{
    char * base;
    char * top;
    int stacksize;
}SqStack;

int InitStack (SqStack *S)
{
    S->base = (char * )malloc(STACK_INIT_SIZE * sizeof(int));
    if(! S->base) return 0;
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return 1;
}

int GetTop(SqStack *S, char *e)
{
    if(S->base == S->top) return 0;
    else
    {
        *e = *(S->top-1);
        return 1;
    }
}

int Push (SqStack *S, char e)
{

    if(S->top - S->base >= S->stacksize)
    {
        S->base = (char *) realloc(S->base, (S->stacksize + STACKINCERMENT) * sizeof(int));
        if(!S->base) return 0;
        S->top = S->base + S->stacksize;
        S->stacksize +=STACKINCERMENT;
    }
    *S->top++ = e;
    return 1;
}

int Pop(SqStack *S, char *e)
{
    if(S->top == S->base) return 0;
    *e = *--S->top;
    return 1;
}

int StackEmpty(SqStack *S)
{
    if(S->top == S->base) return 1;
    else return 0;
}

int compare(char a, char b)
{
    int flag = 0;
    if( (b == '(' || b == ')') && (a == '(' || a == ')') && a != b )
        flag = 1;
    else if( (b == '[' || b == ']') && (a == '[' || a == ']') && a != b )
        flag = 1;
    return flag;
}

void DestroyStack(SqStack * S)
{
    free(S->base);
}

void ClearStack ( SqStack *S)
{
    S->top = S->base;
}

void main()
{

}
