#include "stdio.h"
#include "stdlib.h"

//降序排列
void selection_sort(int **b, int n)
{
    int i, j, maxloc, *a = *b;
    for(i = 0; i < n - 1; i++)
    {
        maxloc = i;
        for(j = i + 1; j < n; j++)
        {
            if(a[j] > a[maxloc])
                maxloc = j;
        }
        if(maxloc != i)
            a[i] += a[maxloc], a[maxloc] = a[i] - a[maxloc], a[i] = a[i] - a[maxloc];
    }
}

int main()
{
    int a[100], i = 0, j, *b;
    b = a;
    printf("input the numbers you want to sort(end up inputting with -1)\n");
    while(scanf("%d", &a[i]), a[i++] != -1);
    selection_sort(&b, i - 1);
    for(j = 0; j < i - 1; j++)
    {
        printf("%d\t", a[j]);
    }
    printf("\n");
    system("pause");
    return 0;
}