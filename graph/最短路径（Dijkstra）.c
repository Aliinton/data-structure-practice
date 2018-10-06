#include "stdio.h"
#include "stdlib.h"

#define MAX_VERTEX_NUM 20
#define Infinity 10000

typedef enum{F,T} status;
typedef char VertexType;
typedef struct
{
    VertexType vexs[MAX_VERTEX_NUM];
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int arcnum, vexnum;
}MGraph;

int d[MAX_VERTEX_NUM];

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
                printf("∞\t");
            else
                printf("%d\t", G.arcs[i][j]);
        }
        printf("\n");
    }
}

int Fexist(status *s, int n)
{
    int i, flag = 0;
    for(i = 0; i < n; i++)
    {
        if(s[i] == F)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

int find(status * S, int *d, int *e, int n)
{
    int i, s = Infinity + 1;
    for(i = 0; i < n; i++)
    {
        if(!S[i])
        {
            if(d[i] < s)
            {
                s = d[i];
                *e = i;
            }
        }
    }
}

int** Dijkstra(MGraph G)
{
    int e, t, n, i, p[G.vexnum];
    int **way, *temp;
    status s[G.vexnum];
    printf("input the start vertex\n");
    scanf("%d", &n);
    for(i = 0; i < G.vexnum; i++)
    {
        d[i] = G.arcs[n][i];
        p[i] = n;
        s[i] = F;
    }
    s[n] = T;
    while(Fexist(s, G.vexnum))
    {
        find(s, d, &t, G.vexnum);
        s[t] = T;
//寻找是否存在以顶点t为中继的更短路径
        for(i = 0; i < G.vexnum; i++)
        {
//在status值为F的顶点中寻找
            if(!s[i])
            {
                e = d[t] + G.arcs[t][i];
                if(e < d[i])
                {
                    d[i] = e;
                    p[i] = t;
                }
            }
        }
    }
/*    for(i = 0; i < G.vexnum; i++)
    {
        printf("%d: %d %d\n", i, d[i], p[i]);
    }
*/
//得到每个顶点的最短路径
    way = (int **) malloc(G.vexnum * (sizeof(int *)));
    for(i = 0; i < G.vexnum; i++)
    {
        temp = (int *)malloc(G.vexnum * (sizeof(int)));
        e = 0;
        t = i;
        if(i != n)
            temp[e++] = i;
        while(p[t] != n)
        {
            temp[e++] = p[t];
            t = p[t];
        }
        temp[e++] = n;
        t = 0;
        way[i] = (int *)malloc(sizeof(int) * (e + 1));
        while(e--)
        {
            way[i][t++] = temp[e];
        }
        way[i][t] = -1;
    }
    return way;
}

int main()
{
    int **way, i, j;
    MGraph G;
    CreateMGraph(&G);
    PrintMGraph(G);
    way = Dijkstra(G);
    for(i = 0; i < G.vexnum; i++)
    {
        j = 0;
        while(way[i][j] != -1)
        {
            printf("%c", G.vexs[way[i][j]]);
            j++;
        }
        if(d[i] == Infinity)
            printf("\tDISTANCE: ∞\n");
        else
            printf("\tDISTANCE: %d\n", d[i]);
    }
    return 0;
}
/*
测试数据：
1.
vexs:ABCDEF
arcs:
0 5 100
0 4 30
0 2 10
1 2 5
2 3 50
3 5 10
4 5 60
4 3 20
-1 -1 -1
2.
vexs:ABCD
arcs:
0 1 1
0 2 4
0 3 5
1 2 2
2 3 1
-1 -1 -1
*/
