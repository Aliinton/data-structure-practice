#include "stdio.h"
#include "stdlib.h"

#define MAX_VERTEX_NUM 20
typedef enum{T, F} mark;
typedef struct
{
    char vexs[MAX_VERTEX_NUM];
    int map[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vexnum, arcnum;
}MGraph;

mark visit[MAX_VERTEX_NUM];



