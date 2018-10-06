#include "stdio.h"
#include "stdlib.h"

#define MAX_VERTEX_NUM 20
#define Infinity 10000

typedef char VertexType;
typedef struct
{
    VertexType vexs[MAX_VERTEX_NUM];
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int arcnum, vexnum;
}MGraph;

int d[MAX_VERTEX_NUM];
int p[MAX_VERTEX_NUM];

void CreateMGraph(MGraph *GP)
{
    int i = 0, a, b, w;
    for(a = 0; a < MAX_VERTEX_NUM;  a++)
        for(b = 0; b < MAX_VERTEX_NUM; b++)
        {
            GP->arcs[a][b] = Infinity;
        }
    printf("input vertex\n");
    while(GP->vexs[i] = getchar(), GP->vexs[i++] != '\n');
    GP->vexnum = i - 1;
    printf("input edge with weight\n");
    i = 0;
    scanf("%d %d %d", &a, &b, &w);
    while(a != -1)
    {
        GP->arcs[a][b] = w;
        i++;
        scanf("%d %d %d", &a, &b, &w);
    }
    GP->arcnum = i;
}

void PrintMGraph(MGraph G)
{
    int i, j;
    printf("vexnum:%d arcnum:%d\n", G.vexnum, G.arcnum);
    for(i = 0; i < G.vexnum; i++)
    {
        printf("%d: %c\n", i, G.vexs[i]);
    }
    for(i = 0; i < G.vexnum; i++)
    {
        for(j = 0; j < G.vexnum; j++)
        {
            if(G.arcs[i][j] == Infinity)
                printf("inf\t");
            else
                printf("%d\t", G.arcs[i][j]);
        }
        printf("\n");
    }
}

int Bell_Ford(MGraph G)
{
    int k, i, j, s;
    printf("input the source vertex\n");
    scanf("%d", &s);
//锟斤拷始锟斤拷锟斤拷锟叫的讹拷锟斤拷,锟斤拷锟斤拷源锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟侥撅拷锟斤拷锟斤拷为锟斤拷锟斤拷
    for(i = 0; i < G.vexnum; i++)
    {
        if(i != s)
            d[i] = Infinity;
        else
            d[i] = 0;
        p[i] = s;
    }
    for(k = 1; k < G.vexnum; k++)
    {
        for(i = 0; i < G.vexnum; i++)
            for(j = 0; j < G.vexnum; j++)
            {
                if(d[i] + G.arcs[i][j] < d[j])
                {
                    d[j] = d[i] + G.arcs[i][j];
                    p[j] = i;
                }
            }
    }
//锟叫讹拷锟角凤拷锟叫革拷锟斤拷
    for(i = 0; i < G.vexnum; i++)
        for(j = 0; j < G.vexnum; j++)
        {
            if(d[i] + G.arcs[i][j] < d[j])
                return 0;
        }
    return 1;
}

int main()
{
    int i;
    MGraph G;
    CreateMGraph(&G);
    PrintMGraph(G);
    if(Bell_Ford(G))
        for(i = 0; i < G.vexnum; i++)
        {
            printf("%c: %d, prevertex: %c\n", G.vexs[i], d[i], G.vexs[p[i]]);
        }
    else
        printf("No solve exist\n");
    system("pause");
    return 0;
}
/*锟斤拷锟斤拷锟斤拷锟捷ｏ拷
1.
vexs:ABCDE
arcs:
0 1 6
0 3 7
1 3 8
1 2 5
2 1 -2
1 4 -4
4 0 2
3 4 9
4 2 7
3 2 -3
-1 -1 -1
result:
A: 0, prevertex: A
B: 2, prevertex: C
C: 4, prevertex: D
D: 7, prevertex: A
E: -2, prevertex: B

2.
vexs:
ABC
arcs:
0 2 2
2 1 3
1 0 -10
-1 -1 -1
result:
No solve exist

3.
vexs:
ABC
arcs:
0 2 2
2 1 3
1 0 1
-1 -1 -1
result:
A: 0, prevertex: A
B: 5, prevertex: C
C: 2, prevertex: A
*/
