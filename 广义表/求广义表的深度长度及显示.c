#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef char AtomType;

typedef struct GLNode
{
    int tag;
    union
    {
        AtomType atom;
        struct
        {
            struct GLNode *hp, *tp;
        }ptr;
    };
} GList;

char * Find(char *s)
{
    char a[100], *z = s;
    int top = 1;
    a[0] = *z++;
    while(top)
    {
        if(a[top-1] == '(' && *z == ')')
            top--, z++;
        else if(*z == '(' || *z == ')')
            a[top++] = *z++;
        else
            z++;
    }
    return z;
}

GList * CreateGList(char * sub)
{
    GList * head;
    char *z, *s;
    s = (char *) malloc ((strlen(sub) + 1) * sizeof (char));
    strcpy(s, sub);
    head = NULL;
    //得到待处理子串
    z = Find(s);
    z[-1] = '\0';
    memcpy(s, s, z - s);
    s++;
    printf("%s\n", s);
    //判断是否为空表
    if(s[0] == '\0') return NULL;
    //处理原子节点
    else
    {
        GList * f, *p;
        p = (GList *) malloc (sizeof (GList));
        p->tag = 1;
        p->ptr.tp = p->ptr.hp = NULL;
        head = p;
        while(s[0] != '\0')
        {
            if(s[0] == ',')
            {
                s++;
                f = (GList *) malloc (sizeof (GList));
                f->tag = 1;
                f->ptr.hp = f->ptr.tp = NULL;
                p->ptr.tp = f;
                p = f;
            }
            else if(s[0] == ' ') s++;
            else if(s[0] == '(')
            {
                p->ptr.hp = CreateGList(s);
                //将s跳过这一个子表
                s = Find(s);
            }
            else
            {
                f = (GList *) malloc (sizeof (GList));
                f->tag = 0;
                f->atom = s[0];
                s++;
                p->ptr.hp = f;
            }
        }
        //返回这一组的头指针
        return head;
    }
}

int GListlen(GList * head)
{
    if(!head) return 0;
    return 1 + GListlen(head->ptr.tp);
}

int GListdep(GList * head)
{
    int max, dep;
    GList * p = head;
    if(!head)
        return 1;
    if(head->tag == 0) return 0;
    for(max = 0; p; p = p->ptr.tp)
    {
        dep = GListdep(p->ptr.hp);
        if(dep > max) max = dep;
    }
    return max + 1;
}

void displayGList(GList * head)
{
    printf("(");
    while(head)
    {
        if(!head->ptr.hp)
            printf("()");
        else if(head->ptr.hp->tag == 1)
            displayGList(head->ptr.hp);
        else
            printf("%c", head->ptr.hp->atom);
        //判断有无后继节点
        if(head->ptr.tp) printf(",");
        head = head->ptr.tp;
    }
    printf(")");
}

char * fliter(char * s)
{
    char * p, *head;
    head = p = (char *) malloc (sizeof (char) * 100);
    while(*s)
    {
        if(*s != ' ')
            *p++ = *s;
        s++;
    }
    *p = '\0';
    return head;
}

int main()
{
    char *s;
    s = (char *) malloc (100 * sizeof (char));
    GList * headp;
    gets(s);                         //不可用scanf("%s", s);代替
    s = fliter(s);
    while(s)
    {
        headp = CreateGList(s);
        printf("%d\n", GListlen(headp));
        printf("%d\n", GListdep(headp));
        displayGList(headp);
        printf("\n");
        gets(s);
        s = fliter(s);
    }
    free(headp);
    return 0;
}


