#include "stdio.h"
#include "stdlib.h"

#define MAX_VERTEX_NUM 20

typedef char VertexType;
typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *nextarc;
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
            printf("%d", p->adjvex);
            p = p->nextarc;
        }
        printf("\n");
    }
}

void CreateAdjGraph(AdjGraph *GP)
{
    int i = 0, a, b;
    ArcNode * n, *tail[MAX_VERTEX_NUM];
    for(i = 0; i < MAX_VERTEX_NUM; i++)
    {
        n = (ArcNode *)malloc(sizeof(ArcNode));
        n->nextarc = NULL;
        tail[i] = GP->vexs[i].firstarc = n;
    }
    i = 0;
    printf("input vertex\n");
    while(GP->vexs[i].data = getchar(), GP->vexs[i++].data != '\n');
    GP->vexnum = i - 1;
    i = 0;
    printf("input edges\n");
    scanf("%d %d", &a, &b);
    while(a != -1)
    {
        n = (ArcNode *)malloc(sizeof(ArcNode));
        n->adjvex = b;
        n->nextarc = NULL;
        tail[a]->nextarc = n;
        tail[a] = n;
        scanf("%d %d", &a, &b);
        i++;
    }
    GP->arcnum = i;
}

void CountInDegree(AdjGraph G, int **inp)
{
    int i;
    ArcNode *p;
    for(i = 0; i < G.vexnum; i++)
    {
        p = G.vexs[i].firstarc->nextarc;
        while(p)
        {
            (*inp)[p->adjvex]++;
            p = p->nextarc;
        }
    }
}

void ToplogicalSort(AdjGraph G)
{
    int indegree[G.vexnum], *q = indegree, i, stack[G.vexnum], top = 0, count = 0;
    ArcNode *p;
    for(i = 0; i < G.vexnum; i++)
    {
        indegree[i] = 0;
    }
//统计每个顶点的入度
    CountInDegree(G, &q);
//入度为零的顶点压栈
    for(i = 0; i < G.vexnum; i++)
    {
        if(!indegree[i])
            stack[top++] = i;
    }
    while(top)
    {
        i = stack[--top];
        printf("%c", G.vexs[i].data);
        count++;
        p = G.vexs[i].firstarc->nextarc;
        while(p)
        {
//搜索所有以i顶点为弧尾的边，将这些边的弧头顶点的入度减1
            if(!(--indegree[p->adjvex]))
//减1后入度为零的顶点压栈
                stack[top++] = p->adjvex;
            p = p->nextarc;
        }
    }
    if(count == G.vexnum)
        printf("\nDONE\n");
    else
        printf("\nThe Graph Is Not An AOV Graph\n");
}

int main()
{
    AdjGraph G;
    CreateAdjGraph(&G);
    PrintAdjGraph(G);
    ToplogicalSort(G);
    return 0;
}

/*
测试数据：
1.
vex:ABCDEF
arcs:
0 1
0 3
0 2
2 1
5 4
5 3
3 4
2 4
-1 -1

2.
vex:ABCDEFGH
arcs:
0 2
1 2
2 4
2 5
3 5
4 7
4 6
5 6
-1 -1

3.
vex:ABCD
arcs:
0 1
1 2
2 0
3 0
-1 -1
*/
