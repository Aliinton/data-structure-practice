#include "stdio.h"
#include "stdlib.h"

#define MAX_VERTEX_NUM 20
#define Infinity 100000
typedef char VertexType;

typedef struct ArcNode
{
    int adjvex, weight;
    struct ArcNode * nextarc;
}ArcNode;

typedef struct
{
    VertexType data;
    ArcNode *firstarc;
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct
{
    AdjList vexs;
    int arcnum, vexnum;
}AdjGraph;

struct
{
    VertexType adj;
    int lowcost;
}closeedge[MAX_VERTEX_NUM];

void Insert(AdjGraph *GP, int a, int b, int w)
{
    ArcNode * n, *p, *q;
    n = (ArcNode *)malloc (sizeof (ArcNode));
    n->adjvex = b;
    n->weight = w;
    n->nextarc = NULL;
    p = GP->vexs[a].firstarc;
    q = p->nextarc;
    while(q && q->adjvex < b)
    {
        p = q;
        q = q->nextarc;
    }
    p->nextarc = n;
    n->nextarc = q;
}

void CreateAdjGraph(AdjGraph *GP)
{
    int i = 0, a, b, w;
    ArcNode * n;
    //得到所有的顶点
    printf("input veertex\n");
    while(GP->vexs[i].data = getchar(), GP->vexs[i++].data != '\n');
    GP->vexnum = i - 1;
//初始化所有的firstarc指针
    for(i = 0; i < MAX_VERTEX_NUM; i++)
    {
        n = (ArcNode *) malloc (sizeof(ArcNode));
        n->nextarc = NULL;
        GP->vexs[i].firstarc = n;
    }
//得到所有的边
    printf("input edges\n");
    scanf("%d %d %d", &a, &b, &w);
    i = 0;
    while(a != -1)
    {
//将节点按顺序插入到对应链表
        Insert(GP, a, b, w);
        Insert(GP, b, a, w);
        scanf("%d %d %d", &a, &b, &w);
        i++;
    }
    GP->arcnum = i;
}

void findsmallest(AdjGraph G, int *e)
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

void PrintAdjGraph(AdjGraph G)
{
    int i;
    ArcNode *p;
    printf("vexnum: %d, arcnum: %d\n", G.vexnum, G.arcnum);
    for(i = 0; i < G.vexnum; i++)
    {
        printf("vex%d: %c\t", i, G.vexs[i].data);
        p = G.vexs[i].firstarc->nextarc;
        while(p)
        {
            printf("%d(%d) ", p->adjvex, p->weight);
            p = p ->nextarc;
        }
        printf("\n");
    }
}

void PRIM(AdjGraph G)
{
    int n = 0, i = 0, s;
//初始化closeedge数组
    ArcNode *p = G.vexs[0].firstarc->nextarc;
    for(i = 0; i < G.vexnum; i++)
    {
        closeedge[i].adj = G.vexs[0].data;
        if(i)
            closeedge[i].lowcost = Infinity;
        else
            closeedge[i].lowcost = 0;
    }
    while(p)
    {
        closeedge[p->adjvex].lowcost = p->weight;
        p = p->nextarc;
    }
    for(i = 1; i < G.vexnum; i++)
    {
//寻找最小权值边的位置
        findsmallest(G, &s);
//输出树边
        printf("第%d条: %c-%d-%c\n", i, G.vexs[s].data, closeedge[s].lowcost, closeedge[s].adj);
        closeedge[s].lowcost = 0;
        p = G.vexs[s].firstarc->nextarc;
        while(p)
        {
            if(closeedge[p->adjvex].lowcost > p->weight)
            {
                closeedge[p->adjvex].lowcost = p->weight;
                closeedge[p->adjvex].adj = G.vexs[s].data;
            }
            p = p->nextarc;
        }
    }
}

int main()
{
    AdjGraph G;
    CreateAdjGraph(&G);
    PrintAdjGraph(G);
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
