#ifndef __UDGRAPH_H__
#define __UDGRAPH_H__

#include <stdio.h>
#include <stdlib.h>

#define ADJMATRIX // 选择图存储方式，选择一种即可 邻接矩阵 ADJMATRIX 或者 邻接表 ADJLIST

#define UNVISITED 0
#define VISITED 1
#define INFINITY MAXINT
#define MAXINT 0xFFFFFFFF

typedef char VexType;

typedef enum
{
    ERROR = -1,
    FALSE,
    TRUE,
    OK,
    OVERFLOW,
} Status; // 状态码

typedef enum
{
    DG,
    DN,
    UDG,
    UDN
} GraphKind;

#ifdef ADJMATRIX
typedef struct
{
    VexType *vexs;
    int **arcs;

    int n, e;
    GraphKind kind;
    int *tags;
} MGraph; // 邻接数组类型

#endif

#ifdef ADJLIST

typedef struct AdjVexNode
{
    int adjvex;
    struct AdjVexNode *nextArc;
    int info;
} AdjVexNode, *AdjVexNodeP;
typedef struct VexNode
{
    VexType data;
    struct AdjVexNode *firstArc;
} VexNode;

typedef struct
{
    VexNode *vexs;
    int n, e;
    GraphKind kind;
    int *tags;
} ALGraph; // 邻接表类型

#endif

#endif