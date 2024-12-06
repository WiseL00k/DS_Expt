#ifndef __UDGRAPH_H__
#define __UDGRAPH_H__

#include <stdio.h>
#include <stdlib.h>
#include "Status.h" // 状态码定义

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

// 暂未实现有向图相关API接口,只支持无向图
typedef enum
{
    DG,
    DN,
    UDG, // 无向图
    UDN  // 无向带权图
} GraphKind;

Status visit(int k); // 访问顶点k

#ifdef ADJMATRIX
typedef struct
{
    VexType *vexs;
    int **arcs;
    int n, e;
    GraphKind kind;
    int *tags;
} MGraph; // 邻接数组类型

Status InitGraph_M(MGraph *G, GraphKind kind, VexType *vexs, int n); // 初始化含n个顶点且无边的kind类的图G
Status CreateGraph_M(MGraph *G, GraphKind kind, VexType *vexs, int n, ArcInfo *arcs, int e);
Status CreateUDG_M(MGraph *G, VexType *vexs, int n, ArcInfo *arcs, int e);
Status DestroyGraph_M(MGraph *G);
int LocateVex_M(MGraph G, VexType v);          // 查找顶点v在图G中的位序
Status GetVex_M(MGraph *G, int k, VexType *w); // 取图G的k顶点的值到w
Status PutVex_M(MGraph *G, int k, VexType w);  // 对图G的k顶点赋值w
int FirstAdjVex_M(MGraph G, int k);
int NextAdjVex_M(MGraph G, int k, int m);             // m顶点为k顶点的邻接顶点,求图G中k顶点相对于m顶点的下一个邻接顶点的位序
Status AddArc_M(MGraph *G, int k, int m, int info);   // 在图G中增加k顶点到m顶点的边或弧,若为带权图,info为权值,否则为1
Status RemoveArc_M(MGraph *G, int k, int m);          // 在图G中删除k顶点到m顶点的边或弧
Status DFS_M(MGraph G, int k, Status (*visit)(int));  // 深度优先搜索图G中从顶点k开始访问
Status DFSTraverse_M(MGraph G, Status (*visit)(int)); // 深度优先遍历图G
Status BFSTraverse_M(MGraph G, Status (*visit)(int)); // 广度优先遍历图G
Status printMGraph(MGraph H);                         // 打印邻接矩阵图

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
Status CreateUDG_AL(ALGraph *G, VexType *vexs, int n, ArcInfo *arcs, int e);
Status DestroyGraph_AL(ALGraph *G);        // 销毁图G
Status LocateVex_AL(ALGraph G, VexType v); // 查找顶点v在图G中的位序
Status GetVex_AL(ALGraph G, int k, VexType *w);
Status PutVex_AL(ALGraph G, int k, VexType w);
int FirstAdjVex_AL(ALGraph G, int k, AdjVexNodeP *p);
int NextAdjVex_AL(ALGraph G, int k, AdjVexNodeP *p);
Status AddArc_AL(ALGraph *G, int k, int m, int info);
Status RemoveArc_AL(ALGraph *G, int k, int m);
Status DFS_AL(ALGraph G, int k, Status (*visit)(int));  // 深度优先搜索图G,从顶点k开始访问
Status DFSTraverse_AL(ALGraph G, Status (*visit)(int)); // 深度优先遍历图G
Status BFSTraverse_AL(ALGraph G, Status (*visit)(int)); // 广度优先遍历图G
Status printALGraph(ALGraph H);                         // 打印邻接表图

#endif

#endif /* __UDGRAPH_H__ */