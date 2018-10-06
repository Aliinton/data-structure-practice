#include "stdio.h"
#include "stdlib.h"

#define MAX_VEX_NUM 20

typedef enum{F, T} mark;
typedef char VertexType;
typedef struct
{
    VertexType vexs[MAX_VEX_NUM];
    int arcs[MAX_VEX_NUM][MAX_VEX_NUM];
    int vexnum, arcnum;
}MGraph;

mark visit[MAX_VEX_NUM];

void CreateMGraph(MGraph * GP)
{
    int i = 0;
    int a, b, *c = &GP->arcs[0][0];
    printf("input vertex\n");
    while(GP->vexs[i] = getchar(), GP->vexs[i++] != '\n');
    GP->vexnum = i - 1;
    for(i = 0; i < (MAX_VEX_NUM * MAX_VEX_NUM); i++)
    {
        *(c + i) = 0;
    }
    printf("input edges\n");
    if(!scanf("%d %d", &a, &b))
        GP->arcnum = 0;
    else
    {
        i = 0;
        while(a != -1)
        {
            GP->arcs[a][b] = 1;
            GP->arcs[b][a] = 1;
            i++;
            scanf("%d %d", &a, &b);
        }
        GP->arcnum = i;
    }

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
            printf("%d\t", G.arcs[i][j]);
        }
        printf("\n");
    }
}

void BFS(MGraph G, int begin)
{
    int queue[G.vexnum + 1], length, f = 0, t = 0, n, i;
    length = G.vexnum + 1;
//压入开始节点并将其标记，注意是一进队就标记
    queue[t++] = begin;
    visit[begin] = T;
//当循环队列不为空
    while(f != t)
    {
        n = queue[f];
//队首节点出队，访问
        f = (f+1) % length;
        printf("%c", G.vexs[n]);
//将和n相邻的顶点一一进队
        for(i = 0; i < G.vexnum; i++)
        {
            if(!visit[i] && G.arcs[n][i])
            {
                queue[t] = i;
                t = (t + 1) % length;
                visit[i] = T;
            }
        }
    }
}

//整个图的BFS
void BFSTraverse(MGraph G)
{
    int i, flag;
//初始化visit数组
    for(i = 0; i < MAX_VEX_NUM; i++)
    {
        visit[i] = F;
    }
//选择从哪一个顶点开始遍历
    printf("input the first vertex\n");
    scanf("%d", &i);
    BFS(G, i);
    do
    {
//寻找下一个分图的开始顶点
        i = 0;
        while(visit[i++]);
        if(i - 1 < G.vexnum)
        {
            flag = 1;
            BFS(G, i - 1);
        }
        else
            flag = 0;
    }
    while(flag);
}

int main()
{
    MGraph G;
    CreateMGraph(&G);
    PrintMGraph(G);
    BFSTraverse(G);
    return 0;
}

/*测试数据
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
*/
