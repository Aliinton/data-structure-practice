#include "stdio.h"
#include "stdlib.h"
#define MAXIUM 10000
typedef struct
{
    int i;
    int j;
    int e;
} Tripe;

typedef struct
{
    int mu;
    int nu;
    int tu;
    Tripe a[MAXIUM];
} Matrix;

void display(Matrix M)
{
    int i, j, p = 0;
    for(i = 1; i <= M.mu; i++)
    {
        for(j = 1; j <= M.nu; j++)
        {
            if(i == M.a[p].i && j == M.a[p].j)
            {
                printf("%d\t", M.a[p].e);
                p++;
            }
            else
                printf("0\t");
        }
        printf("\n");
    }
    printf("\n");
}

void CreatMatrix(Matrix * M)
{
    int i = 0, n = 0;
    Tripe T;
    printf("输入行数列数\n");
    scanf("%d%d", &M->mu, &M->nu);
    printf("输入非零元素个数：\n");
    scanf("%d", &n);
    M->tu = n;
    printf("输入非零元素：\n");
    while(i < n)
    {
        scanf("%d%d%d", &T.i, &T.j, &T.e);
        M->a[i] = T;
        i++;
    }
}

void TransMatrix(Matrix *M, Matrix * T)
{
    int num[M->nu + 1], cpot[M->nu + 1], i, col, p;
    T->mu = M->nu, T->nu = M->mu, T->tu = M->tu;
    for(col = 1; col <= M->nu; col++) num[col] = 0;
    for(i = 0; i < M->tu; i++) num[M->a[i].j]++;
    cpot[1] = 1;
    for(col = 2; col <= M->nu; col++)
        cpot[col] = cpot[col-1] + num[col-1];
    for(i = 0; i < M->tu; i++)
    {
        col = M->a[i].j;
        p = cpot[col] - 1;
        T->a[p].i = M->a[i].j;
        T->a[p].j = M->a[i].i;
        T->a[p].e = M->a[i].e;
        cpot[col]++;
    }
}

int main()
{
    Matrix M, T;
    CreatMatrix(&M);
    display(M);
    TransMatrix(&M, &T);
    display(T);
    return 0;
}
