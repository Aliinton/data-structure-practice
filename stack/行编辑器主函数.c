void main()
{
    SqStack S;
    char ch, e, *p;
    InitStack (&S);
    p = S.base;
    ch = getchar ();
    while ( ch != EOF )
    {
        while (ch != EOF && ch != '\n')
        {
            switch (ch)
            {
                case '#':Pop (&S, &e); break;
                case '@':ClearStack (&S); break;
                default :Push (&S, ch); break;
            }
            ch = getchar ();
        }
        while (S.top != p) cqs
            printf ("%c", *p++);
        printf("\n");
        p = S.base;
        ClearStack (&S);
        if (ch != EOF) ch = getchar ();
    }
    DestroyStack (&S);
}
//pinaccesscode
//sexhotgames
