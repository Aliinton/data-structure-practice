#include "stdio.h"
#include "stdlib.h"

void test(int * a)
{
    printf("%x\t", a);
    a++;
    printf("%x\t", a);
}

int main()
{
    int *a;
    a = (int *) malloc (sizeof (int) * 100);
    printf("%x\t", a);
    test(a);
    printf("%x\t", a);
    return 0;
}
