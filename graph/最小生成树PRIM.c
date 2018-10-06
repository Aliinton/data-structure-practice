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

struct
{
    VertexType adjvex;
    int lowcost;
}closeedge[MAX_VERTEX_NUM];

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
        GP->arcs[b][a] = GP->arcs[a][b] = w;
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
                printf("Infinity\t");
            else
                printf("%d\t", G.arcs[i][j]);
        }
        printf("\n");
    }
}

void findsmallest(MGraph G, int *e)
{
    int i, s = Infinity;
    *e = 0;
    for(i = 0; i < G.vexnum; i++)
    {
        if(closeedge[i].lowcost < s && closeedge[i].lowcost)
        {
            s = closeedge[i].lowcost;
            *e = i;
        }
    }
}

void PRIM(MGraph G)
{
    int n, i, s, k = G.vexnum - 1;
//初始化closeedge数组
    printf("select a vertex as begin point\n");
    scanf("%d", &n);
    for(i = 0; i < G.vexnum; i++)
    {
        closeedge[i].adjvex = G.vexs[n];
        if(i != n)
            closeedge[i].lowcost = G.arcs[n][i];
        else
            closeedge[i].lowcost = 0;
    }
    while(k--)
    {
//寻找最小权值边的位置
        findsmallest(G, &s);
//输出生成树边
        printf("%c-%c: weight: %d\n", closeedge[s].adjvex, G.vexs[s], closeedge[s].lowcost);
        closeedge[s].lowcost = 0;
        for(i = 0; i < G.vexnum; i++)
        {
            if(G.arcs[s][i] < closeedge[i].lowcost)
            {
                closeedge[i].lowcost = G.arcs[s][i];
                closeedge[i].adjvex = G.vexs[s];
            }
        }
    }
}

int main()
{
    MGraph G;
    CreateMGraph(&G);
    PrintMGraph(G);
    PRIM(G);
    return 0;
}

/*测试数据
1
vexs: ABCDE
arcs:
0 1 1
0 4 2
1 4 3
1 2 5
1 3 4
2 3 6
3 4 7
-1 -1 -1

2
vexs: ABCDEF
arcs:
0 4 6
0 1 3
0 2 1
0 3 7
1 2 6
1 3 5
2 3 5
2 4 7
2 5 8
4 5 4
-1 -1 -1
*/
