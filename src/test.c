#include "test.h"

void test_M(MGraph *G)
{
    printf("-----------------------\n");
    printMGraph(*G);
    printf("MGraph_DFS:\n");
    DFSTraverse_M(*G, visit);
    printf("\n");
    printf("MGraph_BFS:\n");
    BFSTraverse_M(*G, visit);
    printf("\n");
    DestroyGraph_M(G);
    printf("-----------------------\n");
}

void test_AL(ALGraph *G)
{
    printf("-----------------------\n");
    printALGraph(*G);
    printf("ALGraph_DFS:\n");
    DFSTraverse_AL(*G, visit);
    printf("\n");
    printf("ALGraph_BFS:\n");
    BFSTraverse_AL(*G, visit);
    printf("\n");
    DestroyGraph_AL(G);
    printf("-----------------------\n");
}

void displayMenu()
{
    printf("数据结构实验无向图测试\n");
    printf("-----------------------\n");
    printf("1. 测试邻接矩阵\n");
    printf("2. 测试邻接表\n");
    printf("3. 退出\n");
    printf("-----------------------\n");
    printf("请输入你的选择: ");
}