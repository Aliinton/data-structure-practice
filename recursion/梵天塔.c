#include "stdio.h"
#include "stdlib.h"

#define NUM 3

void solve(int n, char a, char b, char c)
{
    if(n > 1)
    {
        solve(n-1, a, c, b);
        printf("%c->%c\n", a, c);
        solve(n-1, b, a, c);
    }
    else
        printf("%c->%c\n", a, c);
}

int main()
{
    int n = NUM;
    char a = 'a', b = 'b', c = 'c';
    solve(NUM, a, b, c);
    return 0;
}
