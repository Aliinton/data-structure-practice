#include "stdio.h"

int main()
{
    int i;
    i = 10;
    sizeof(i++);
    printf("After sizeof(i++) i's value is: %d", i);
    printf("\n");
    int a[10][10];
    printf("%d\t%d\t%d\n", sizeof(a), sizeof(a[1]), sizeof(&a));
}
