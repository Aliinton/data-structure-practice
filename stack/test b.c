int compare(char a, char b)
{
    int flag = 0;
    if( (b == '(' || b == ')') && (a == '(' || a == ')') && a != b )
        flag = 1;
    else if( (b == '[' || b == ']') && (a == '[' || a == ']') && a != b )
        flag = 1;
    return flag;
}

void main()
{
    SqStack S;
    int i = 0;
    char a[100] = {};
    char c = '\0', *p = a;
    InitStack(&S);
    scanf("%s", a);
    while( (*p) != '\0' )
    {
        GetTop(&S, &c);
        if( compare(*p, c) )
            S.top--;
        else
            Push(&S, *p);
        p++;
    }
    if(S.top == S.base)
        printf("OK\n");
    else
        printf("Fail\n");
}
