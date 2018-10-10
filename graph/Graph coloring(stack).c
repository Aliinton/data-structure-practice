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
//特殊情况，n为0，不用判断直接返回1
    if(n == 0)
        return 1;
    for(i = 0; i < n; i++)
    {
        if(G.arcs[n][i] && Q_paint[i] == Q_paint[n])
            return 0;
    }
    return 1;
}

//对图G，利用K种颜色染色
void Coloring(Graph G, int k)
{
//n代表对第n个顶点进行染色
    int n = 0, i;
//对染色方案进行初始化
    for(i = 0; i < G.vexnum; i++)
    {
        Q_paint[i] = 0;
    }
    while(n != -1)
    {
//显示找到的染色方案
        if(n == G.vexnum)
        {
            Q_ans++;
            for(i = 0; i < G.vexnum; i++)
            {
                printf("%c:%d\t", G.vex[i], Q_paint[i]);
            }
            printf("\n");
//继续寻找下一组染色方案,注意一定要改变掉最后一个顶点的染色，不然就将卡在这种染色方案
            Q_paint[--n]++;
        }
        else
        {
//flag作为标识变量，若在现存染色方案上能够对下一个点着色，就为1，否则为0
            int flag = 0;
            for(; Q_paint[n] < k; Q_paint[n]++)
            {
                if(judege(G, n))
                {
                    n++;
                    flag = 1;
                    break;
                }
            }
            if(!flag)
            {
//即将回到上一个顶点进行染色，应该放弃对当前顶点染色的尝试，即将这个顶点的染色方案初始化，归零，同时改变上一个顶点的染色状况
                Q_paint[n--] = 0;
                Q_paint[n]++;
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
    Coloring(G, k);
    if(Q_ans)
        printf("The total solve number: %d\n", Q_ans);
    else
        printf("No solve exist\n");
    system("pause");
    return 0;
}
/*测试数据
vexs:
ABCD
color:
4(3)
arcs:
0 1
0 2
0 3
1 3
2 3
-1 -1
solve:
48(6)
*/
