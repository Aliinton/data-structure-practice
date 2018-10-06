#include "stdio.h"
#include "stdlib.h"

#define MAX_VERTEX_NUM 20

typedef char VertexType;
typedef enum{F, T} mark;

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode * nextarc;
} ArcNode;

typedef struct
{
    VertexType data;
    ArcNode *firstarc;
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct
{
    AdjList vexs;
    int vexnum, arcnum;
}AdjGraph;

mark visit[MAX_VERTEX_NUM];

//安递增顺序插入节点
void Insert(AdjGraph * GP, int a, int b)
{
    ArcNode *p, *q, *n;
    n = (ArcNode *)malloc(sizeof (ArcNode));
    n->adjvex = b;
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



//创建由邻接表保存的图(其中的链表按增序排列)
void CreateAdjGraph(AdjGraph *GP)
{
    int i = 0, a, b;
    ArcNode *n;
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
    scanf("%d %d", &a, &b);
    i = 0;
    while(a != -1)
    {
//将新节点按增序插入对应的链表
        Insert(GP, a, b);
        Insert(GP, b, a);
        scanf("%d %d", &a, &b);
        i++;
    }
    GP->arcnum = i;
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
            printf("%d", p->adjvex);
            p = p ->nextarc;
        }
        printf("\n");
    }
}

//判断两个顶点之间是否有边链接,有返回1，否则返回0
int adj(AdjGraph G, int n, int i)
{
    int flag = 0;
    ArcNode * p;
    p = G.vexs[n].firstarc->nextarc;
    while(!flag && p)
    {
        if(p->adjvex == i)
            flag = 1;
        else
            p = p->nextarc;
    }
    return flag;
}

void BFS(AdjGraph G, int begin)
{
    int queue[G.vexnum + 1], f = 0, t = 0, n, length, i;
    length = G.vexnum + 1;
    queue[t++] = begin;
    visit[begin] = T;
    while(t != f)
    {
//队首顶点出队，访问，并保存至n中
        n = queue[f];
        f = (f + 1) % length;
        printf("%c", G.vexs[n].data);
        i = 0;
//使所有与顶点n相邻且未被访问的顶点进队，标记
        while(i < G.vexnum)
        {
            if(adj(G, n, i) && !visit[i])
            {
                queue[t] = i;
                t = (t + 1) % length;
                visit[i] = T;
            }
            i++;
        }
    }
}

void BFSTraverse(AdjGraph G)
{
    int begin, i, flag = 1;
    for(i = 0; i < MAX_VERTEX_NUM; i++)
    {
        visit[i] = F;
    }
    printf("input the first vertex\n");
    scanf("%d", &begin);
    BFS(G, begin);
    do
    {
        i = 0;
        while(visit[i++]);
        if(i - 1 < G.vexnum)
        {
            BFS(G, i - 1);
        }
        else
        {
            printf("\nDONE\n");
            flag = 0;
        }
    }
    while(flag);
}

int main()
{
    AdjGraph G;
    CreateAdjGraph(&G);
    PrintAdjGraph(G);
    BFSTraverse(G);
    return 0;
}

/*测试数据
1
vertex: ABCDEFGHIJ
arcs:
0 1
0 5
0 4
1 2
1 3
3 2
5 7
5 6
4 6
6 7
8 9
-1 -1

2
vertex: ABCDEFGH
arcs:
0 1
0 2
1 3
1 4
2 5
2 6
5 6
3 7
4 7
-1 -1
*/

