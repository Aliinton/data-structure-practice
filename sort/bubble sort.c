#include "stdio.h"
#include "stdlib.h"

//升序
int main()
{
    int a[100], i = 0, j, len;
    printf("input the numbers you want to sort(end up with 0)\n");
    while(scanf("%d", &a[i]), a[i++]);
    len = i - 1;
    for(i = 0; i < len - 1; i++)
    {
        for(j = 0; j < len - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                a[j] += a[j + 1];
                a[j + 1] = a[j] - a[j + 1];
                a[j] = a[j] - a[j + 1];
            }
        }
    }
    for(i = 0; i < len; i++)
        printf("%d\t", a[i]);
    printf("\n");
    system("pause");
    return 0;
}