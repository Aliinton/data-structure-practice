#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//归并排序，升序
int * merge(int *a, int size)
{
    int i, j, n, m, *sub1, *sub2, *sorted, index;
    sorted  = (int *) malloc (sizeof (int) * size);
//若待排序序列长度小于等于2，则直接排序，无需二分，此处为递归出口
    if(size == 1)
    {
        return a;
    }
    else if(size == 2)
    {
        if(a[0] > a[1])
        {
            a[0] += a[1];
            a[1] = a[0] - a[1];
            a[0] = a[0] - a[1];
        }
        return a;
    }
    else
    {
//将整个待排序序列二分
        n = size/2;
        m = size - n;
        sub1 = (int *) malloc (sizeof(int) * n);
        sub2 = (int *) malloc (sizeof(int) * m);
        for(i = 0; i < n; i++)
        {
            sub1[i] = a[i];
        }
        a += n;
        for(j = 0; j < m; j++)
        {
            sub2[j] = a[j];
        }
//对分好的两个子串进行merge sort
        sub1 = merge(sub1, n);
        sub2 = merge(sub2, m);
//将两个已经经过merge sort的子串合并
        for(index = 0, i = 0 , j = 0; i < n && j < m;)
        {
            sorted[index++] = sub1[i] > sub2[j] ? sub2[j++] : sub1[i++];
        }
       for(; i < n; i++)
            sorted[index++] = sub1[i];
        for(; j < m; j++)
            sorted[index++] = sub2[j];
        free(sub1);
        free(sub2);
        return sorted;
    }
}

int main()
{
    int *a, size, i;
    printf("input the totoal element numbers you want to sort\n");
    scanf("%d", &size);
    a = (int *) malloc (sizeof (int) * size);
    for(i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    a = merge(a, size);
    for(i = 0; i < size; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}