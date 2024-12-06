#include <stdio.h>
#include "UDGraph.h"

int main(void)
{
    VexType vexs[5] = {'A', 'B', 'C', 'D', 'E'};
    ArcInfo arcs[5] = {{'A', 'C', 1}, {'A', 'D', 1}, {'C', 'E', 1}, {'C', 'D', 1}, {'B','D', 1}};

    // MGraph G;
    // CreateGraph_M(&G, UDG, vexs, 5, arcs, 5);
    // printMGraph(G);
    // printf("MGraph_DFS:\n");
    // DFSTraverse_M(G, visit);
    // printf("\n");
    // printf("MGraph_BFS:\n");
    // BFSTraverse_M(G, visit);
    // printf("\n");
    // DestroyGraph_M(&G);

    ALGraph G;
    CreateGraph_AL(&G, UDG, vexs, 5, arcs, 5);
    printALGraph(G);
    printf("ALGraph_DFS:\n");
    DFSTraverse_AL(G, visit);
    printf("\n");
    printf("ALGraph_BFS:\n");
    BFSTraverse_AL(G, visit);
    printf("\n");
    DestroyGraph_AL(&G);

    return 0;
}
