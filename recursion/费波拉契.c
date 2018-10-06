#include "stdio.h"
#include "stdlib.h"

int fei(int n)
{
    if(n < 3)
        return 1;
    else
        return fei(n-1) + fei(n-2);
}

int main()
{
    int i = 0;
    while(i++ <= 10)
    {
        printf("%d\t", fei(i));
    }
    return 0;
}
