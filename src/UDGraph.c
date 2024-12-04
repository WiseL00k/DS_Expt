#include "UDGraph.h"
#include "LQueue.h"

Status visit(int k)
{
    printf("%d ", k);
    return OK;
}

#ifdef ADJMATRIX

Status InitGraph_M(MGraph *G, GraphKind kind, VexType *vexs, int n)
{
    int i, j, info;
    if (n < 0 || (n > 0 && vexs == NULL))
        return ERROR;
    if (kind == UDG)
        info = 0;
    else if (kind == UDN)
        info = INFINITY;
    else
        return ERROR;
    G->n = n;
    G->e = 0;
    G->kind = kind;
    if (n == 0)
        return OK;
    if (NULL == (G->vexs = (VexType *)malloc(n * sizeof(VexType))))
        return OVERFLOW;
    for (i = 0; i < G->n; ++i)
        G->vexs[i] = vexs[i];
    if (NULL == (G->arcs = (int **)malloc(n * sizeof(int *))))
        return OVERFLOW;
    for (i = 0; i < n; ++i)
        if (NULL == (G->arcs[i] = (int *)malloc(n * sizeof(int))))
            return OVERFLOW;
    if (NULL == (G->tags = (int *)malloc(n * sizeof(int))))
        return OVERFLOW;
    for (i = 0; i < n; ++i)
    {
        G->tags[i] = UNVISITED;
        for (j = 0; j < n; ++j)
            G->arcs[i][j] = info;
    }
    return OK;
}

Status CreateGraph_M(MGraph *G, GraphKind kind, VexType *vexs, int n, ArcInfo *arcs, int e)
{
    if (n < 0 || e < 0 || (n > 0 && vexs == NULL) || (e > 0 && arcs == NULL))
        return ERROR;
    G->kind = kind;
    switch (G->kind)
    {
    case UDG:
        return CreateUDG_M(G, vexs, n, arcs, e); // 创建无向图
    default:
        return ERROR;
    }
}

Status CreateUDG_M(MGraph *G, VexType *vexs, int n, ArcInfo *arcs, int e)
{
    int i, j, k;
    VexType v, w;
    if (InitGraph_M(G, UDG, vexs, n) != OK)
        return ERROR;
    G->e = e;
    for (k = 0; k < G->e; ++k)
    {
        v = arcs[k].v;
        w = arcs[k].w;
        i = LocateVex_M(*G, v);
        j = LocateVex_M(*G, w);
        if (i < 0 || j < 0)
            return ERROR;
        G->arcs[i][j] = G->arcs[j][i] = 1;
    }
    return OK;
}

Status DestroyGraph_M(MGraph *G)
{
    if (G == NULL)
        return ERROR;
    free(G->vexs);
    for (int i = 0; i < G->n; ++i)
    {
        free(G->arcs[i]);
        G->arcs[i] = NULL;
    }
    free(G->arcs);
    free(G->tags);
    G->vexs = NULL;
    G->arcs = NULL;
    G->tags = NULL;
    return OK;
}

int LocateVex_M(MGraph G, VexType v)
{
    if (G.vexs == NULL)
        return -1;
    for (int i = 0; i < G.n; ++i)
        if (v == G.vexs[i])
            return i; // 找到顶点返回下标i
    return -1;        // 未找到顶点返回-1
}

Status GetVex_M(MGraph *G, int k, VexType *w)
{
    if (k < 0 || k >= G->n)
        return -1;   // k顶点不存在
    *w = G->vexs[k]; // 将k顶点的值赋给w
    return OK;
}

Status PutVex_M(MGraph *G, int k, VexType v)
{
    if (k < 0 || k >= G->n)
        return -1;  // k顶点不存在
    G->vexs[k] = v; // 将v赋给k顶点
    return OK;
}

int FirstAdjVex_M(MGraph G, int k)
{
    int i;
    if (k < 0 || k >= G.n)
        return -1; // k顶点不存在
    for (i = 0; i < G.n; ++i)
        if (G.kind == UDG && G.arcs[k][i] != 0)
            return i;
        else if (G.kind == UDN && G.arcs[k][i] != INFINITY)
            return i;
    return -1; // k顶点无邻接顶点
}

int NextAdjVex_M(MGraph G, int k, int m)
{
    int i;
    if (k < 0 || k >= G.n || m < 0 || m >= G.n)
        return -1; // k顶点或m顶点不存在
    for (i = m + 1; i < G.n; ++i)
    {
        if (G.kind == UDG && G.arcs[k][i] != 0)
            return i;
        else if (G.kind == UDN && G.arcs[k][i] != INFINITY)
            return i;
    }
    return -1; // k顶点无邻接顶点
}

Status AddArc_M(MGraph *G, int k, int m, int info)
{
    if (k < 0 || k >= G->n || m < 0 || m >= G->n)
        return ERROR;   // k顶点或m顶点不存在
    if (G->kind == UDG) // 无向图
    {
        G->arcs[k][m] = G->arcs[m][k] = 1;
    }
    else if (G->kind == UDN) // 无向网
    {
        G->arcs[k][m] = G->arcs[m][k] = info;
    }
    G->e++; // 边数加1
    return OK;
}

Status RemoveArc_M(MGraph *G, int k, int m)
{
    if (k < 0 || k >= G->n || m < 0 || m >= G->n)
        return ERROR;                  // k顶点或m顶点不存在
    G->arcs[k][m] = G->arcs[m][k] = 0; // 删除k顶点与m顶点之间的边或弧
    G->e--;                            // 边数减1
    return OK;
}

Status DFS_M(MGraph G, int k, Status (*visit)(int))
{
    int i;
    if (ERROR == visit(k)) // 访问k顶点
        return ERROR;
    G.tags[k] = VISITED;
    for (i = FirstAdjVex_M(G, k); i >= 0; i = NextAdjVex_M(G, k, i))
        if (G.tags[i] == UNVISITED) // 位序为i的邻接顶点未被访问过
            DFS_M(G, i, visit);     // 对i顶点递归深度搜索
    return OK;
}

Status DFSTraverse_M(MGraph G, Status (*visit)(int))
{
    int i;
    for (i = 0; i < G.n; ++i)
        G.tags[i] = UNVISITED; // 初始化标志数组
    for (i = 0; i < G.n; ++i)
        if (G.tags[i] == UNVISITED) // 若i顶点未访问,则以其为起点进行深度优先遍历
            if (ERROR == DFS_M(G, i, visit))
                return ERROR;
    return OK;
}

Status BFSTraverse_M(MGraph G, Status (*visit)(int))
{
    int i, j, k;
    LQueue Q;
    InitQueue_LQ(&Q);
    for (i = 0; i < G.n; ++i)
        G.tags[i] = UNVISITED; // 初始化标志数组
    for (i = 0; i < G.n; ++i)
    {
        if (G.tags[i] == UNVISITED)
        {
            if (ERROR == visit(i))
                return ERROR;
            G.tags[i] = VISITED;
            EnQueue_LQ(&Q, i);
            while (DeQueue_LQ(&Q, k) == OK)
            {
                for (j = FirstAdjVex_M(G, k); j >= 0; j = NextAdjVex_M(G, k, j))
                {
                    if (G.tags[j] == UNVISITED)
                    {
                        if (ERROR == visit(j))
                            return ERROR;
                        G.tags[j] = VISITED;
                        EnQueue_LQ(&Q, j);
                    }
                }
            }
        }
    }
    return OK;
}

#endif