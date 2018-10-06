#include "stdio.h"
#include "stdlib.h"

#define MAX_VERTEX_NUM 20
#define Infinity 1000
typedef struct
{
    char vexs[MAX_VERTEX_NUM];
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vexnum, arcnum;
}MGraph;

void CreateMGraph(MGraph* GP)
{
    int i = 0, a, b, w;
    printf("Input Vertex\n");
    while(GP->vexs[i] = getchar(), GP->vexs[i++] !='\n');
    GP->vexnum = i - 1;
    for(a = 0; a < i; a++)
        for(b = 0; b < i; b++)
        {
            if(a == b)
                GP->arcs[a][b] = 0;
            else
            GP->arcs[a][b] = Infinity;
        }
    i = 0;
    printf("Input Edges\n");
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
        for(j = 0; j < G.vexnum; j++)
        {
            if(G.arcs[i][j] == Infinity)
                printf("¡Þ\t");
            else
                printf("%d\t", G.arcs[i][j]);
        }
        printf("\n");
    }
}

void Floyd(MGraph G)
{
    int path[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int i, j, k;
    for(i = 0; i < G.vexnum; i++)
        for(j = 0; j < G.vexnum; j++)
            path[i][j] = G.arcs[i][j];
    for(k = 0; k < G.vexnum; k++)
        for(i = 0; i < G.vexnum; i++)
            for(j = 0; j < G.vexnum; j++)
            {
               if(path[i][k] + path[k][j] < path[i][j])
                    path[i][j] = path[i][k] + path[k][j];
            }
    for(i = 0; i < G.vexnum; i++)
    {
        for(j = 0; j < G.vexnum; j++)
        {
            if(path[i][j] == Infinity)
                printf("¡Þ\t");
            else
                printf("%d\t", path[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    MGraph G;
    int path[MAX_VERTEX_NUM][MAX_VERTEX_NUM], i ,j;
    CreateMGraph(&G);
    PrintMGraph(G);
    printf("\n");
    Floyd(G);
    return 0;
}
/*²âÊÔÊý¾Ý£º
vexs:ABCD
arcs:
0 1 2
0 3 4
0 2 6
1 2 3
2 0 7
2 3 1
3 0 5
3 2 12
-1 -1 -1
*/
