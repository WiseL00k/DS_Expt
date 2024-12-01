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
typedef struct
{
    VexType v, w;
    int info;
} ArcInfo;
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

Status InitGraph_M(MGraph *G, GraphKind kind, VexType *vexs, int n);
Status CreateGraph_M(MGraph *G, GraphKind kind, VexType *vexs, int n, ArcInfo *arcs, int e);
Status DestroyGraph_M(MGraph *G);
int LocateVex_M(MGraph G, VexType v);
Status GetVex_M(MGraph G, int k, VexType *w);
Status PutVex_M(MGraph G, int k, VexType w);
int FirstAdjVex_M(MGraph G, int k);
int NextAdjVex_M(MGraph G, int k, int m);
Status AddArc_M(MGraph *G, int k, int m, int info);
Status RemoveArc_M(MGraph *G, int k, int m);
Status DFSTraverse_M(MGraph G, Status (*visit)(int)); // 深度优先遍历图G
Status BFSTraverse_M(MGraph G, Status (*visit)(int)); // 广度优先遍历图G

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

Status CreateGraph_AL(ALGraph *G, GraphKind kind, VexType *vexs, int n, ArcInfo *arcs, int e);
Status DestroyGraph_AL(ALGraph *G); // 销毁图G
Status LocateVex_AL(ALGraph G, VexType v);
Status GetVex_AL(ALGraph G, int k, VexType *w);
Status PutVex_AL(ALGraph G, int k, VexType w);
int FirstAdjVex_AL(ALGraph G, int k, AdjVexNodeP *p);
int NextAdjVex_AL(ALGraph G, int k, AdjVexNodeP *p);
Status AddArc_AL(ALGraph *G, int k, int m, int info);
Status RemoveArc_AL(ALGraph *G, int k, int m);
Status DFSTraverse_AL(ALGraph G, Status (*visit)(int)); // 深度优先遍历图G
Status BFSTraverse_AL(ALGraph G, Status (*visit)(int)); // 广度优先遍历图G

#endif

#endif