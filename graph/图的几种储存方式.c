//�����ʾ��
#define MAX_VERTEX_NUM 20

typedef enum{DG, DN, UDG, UDN} GraphKind;

typedef struct
{
//��Žڵ�
    VertexType vexs[MAX_VERTEX_NUM];
//����ڽӾ���
    VRType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vexnum, arcnum;
    GraphKind kind;
}Mgraph;

//�ڽӱ��ʾ��
#define MAX_VERTEX_NUM 20

typedef enum{DG, DN, UDG, UDN} GraphKind;
//��ڵ����Ͷ��壬������Ҫ��Ȩֵ����
typedef struct ArcNode
{
    int adjvex;//����λ�ñ��
    struct ArcNode *nextarc;
    InfoType *info;
}ArcNode;

//ͷ��㼰���������Ͷ���
typedef struct VNode
{
    VertexType data;     //������Ϣ
    ArcNode * firstarc;  //ָ���һ����
}VNode, AdjList[MAX_VERTEX_NUM];


//�ڽӱ�����Ͷ���
typedef struct
{
    AdjLis vertices;
    int vexnum, arcnum;
    GraphKind kind;
}ALGraph;

//ʮ�������ʾ��
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

//�����ڽӱ�
