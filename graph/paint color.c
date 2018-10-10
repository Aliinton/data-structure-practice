#include "stdio.h"
#include "stdlib.h"

#define MAX_VEX_NUM 100

typedef enum{red, yellow, blue, green} color;
typedef struct
{
    char vex[MAX_VEX_NUM + 1];
    int arcs[MAX_VEX_NUM][MAX_VEX_NUM];
    int vexnum, arcnum;
}Graph;
//定义一个数组用来保存每个顶点的染色情况
color Q_paint[MAX_VEX_NUM];
//保存总染色方案数
int Q_ans;

//判断当前染色方案是否合理,合理返回1，否则返回0
int judege(Graph G, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(G.arcs[n][i] && Q_paint[i] == Q_paint[n])
            return 0;
    }
    return 1;
}

//对第n个顶点进行染色
void Paint_Color(Graph G, int n, int k)
{
    int i;
    if(n == G.vexnum)
    {
        Q_ans++;
        for(i = 0; i < G.vexnum; i++)
        {
            printf("%c:%d\t", G.vex[i], Q_paint[i]);
        }
        printf("\n");
    }
    else
    {
        for(i = 0; i < k; i++)
        {
            Q_paint[n] = i;
            if(judege(G, n))
            {
                Paint_Color(G, n + 1, k);
            }
        }
    }
}

void CreateGraph(Graph * GP)
{
    int i = 0, a, b;
    printf("intput the vexs\n");
    while(GP->vex[i] = getchar(), GP->vex[i++] != '\n');
    GP->vexnum = i -  1;
    for(a = 0; a < GP->vexnum; a++)
        for(b = 0; b < GP->vexnum; b++)
            GP->arcs[a][b] = 0;
    printf("input the arcs,(the arcs should be inputted with two vex's numbers, like 1 2), end up with -1 -1\n");
    i = 0;
    scanf("%d %d", &a, &b);
    while(a != -1)
    {
        GP->arcs[a][b] = GP->arcs[b][a] = 1;
        i++;
        scanf("%d %d", &a, &b);
    }
    GP->arcnum = i;
}

int main()
{
    Graph G;
    int k;
    printf("0-red; 1-yellow; 2-blue; 3-green\n");
    printf("Start to Create Graph\n");
    CreateGraph(&G);
    printf("How many color you want to use to paint this graph\n");
    scanf("%d", &k);
    printf("Here is the solve\n");
    Paint_Color(G, 0, k);
    if(Q_ans)
        printf("The total solve number: %d\n", Q_ans);
    else
        printf("No solve exist\n");
    system("pause");
    return 0;
}