//数组表示法
#define MAX_VERTEX_NUM 20

typedef enum{DG, DN, UDG, UDN} GraphKind;

typedef struct
{
//存放节点
    VertexType vexs[MAX_VERTEX_NUM];
//存放邻接矩阵
    VRType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vexnum, arcnum;
    GraphKind kind;
}Mgraph;

//邻接表表示法
#define MAX_VERTEX_NUM 20

typedef enum{DG, DN, UDG, UDN} GraphKind;
//表节点类型定义，对网需要加权值属性
typedef struct ArcNode
{
    int adjvex;//顶点位置编号
    struct ArcNode *nextarc;
    InfoType *info;
}ArcNode;

//头结点及其数组类型定义
typedef struct VNode
{
    VertexType data;     //顶点信息
    ArcNode * firstarc;  //指向第一条弧
}VNode, AdjList[MAX_VERTEX_NUM];


//邻接表的类型定义
typedef struct
{
    AdjLis vertices;
    int vexnum, arcnum;
    GraphKind kind;
}ALGraph;

//十字链表表示法
#define MAX_VERTEX_NUM 20
typedef struct ArcNode
{
    int tailvex, headvex;
    struct ArcNode *hlink, *tlink;
}ArcNode;

typedef struct
{
    VertexType data;
    ArcNode *firstin, *firstout;
}VexNode;

typedef struct
{
    Vexnode Xlist[MAX_VERTEX_NUM];
    int vxnum, arcnum;
}OLGrapgh;

//多重邻接表
