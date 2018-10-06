#include "stdlib.h"
#include "stdio.h"
int main()
{
    char * s;
    s = (char *) malloc (sizeof (char) * 100);
    scanf("%s", s);
    printf("%s\n", s);
    gets(s);
    printf("%s", s);
    return 0;
}
