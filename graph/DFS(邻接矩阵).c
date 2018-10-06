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

void DFS(MGraph G, int begin)
{
    int n, k, stack[G.vexnum], top = 0;
//ѹ�뿪ʼ����
    stack[top++] = begin;
    printf("%c", G.vexs[begin]);
    visit[begin] = T;
//ջ��û��Ԫ��ʱ��������
    while(top)
    {
//�õ�ջ��Ԫ�أ�ע�ⲻ��ȡ��
        n = stack[top - 1];
//����������˳����δ���ʹ��Ķ���
        k = 0;
        while((visit[k] || !G.arcs[n][k]) && (k++ < G.vexnum));
        if((k - 1) < G.vexnum)
        {
//ע��˴���(visit[k] || !G.arcs[n][k])��Ϊ0����ôk�ǲ����һ�ģ��ʸ�ֵʱʹ�õ���k
            stack[top++] = k;
            printf("%c", G.vexs[k]);
            visit[k] = T;
        }
        else
        {
            top--;
        }
    }
}

void DFSTraverse(MGraph G)
{
    int i, flag;
//��ʼ��visit����
    for(i = 0; i < MAX_VEX_NUM; i++)
        visit[i] = F;
//���뿪ʼ����
    printf("input first vertex\n");
    scanf("%d", &i);
    DFS(G, i);
    do
    {
//Ѱ����һ����ͼ�Ŀ�ʼ����
        i = 0;
        while(visit[i++]);
        if(i - 1 < G.vexnum)
        {
            flag = 1;
            DFS(G, i - 1);
        }
        else
        {
            flag = 0;
            printf("\nDONE\n");
        }

    }
    while(flag);
}

int main()
{
    MGraph G;
    CreateMGraph(&G);
    PrintMGraph(G);
    DFSTraverse(G);
    return 0;
}
/*��������
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
