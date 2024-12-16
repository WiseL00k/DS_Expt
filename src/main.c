#include <stdio.h>
#include <stdlib.h>
#include "UDGraph.h"
#include "test.h"

int main(void)
{
    int select;
    // 测试数据
    VexType vexs[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    ArcInfo arcs[10] = {{'A', 'C', 1}, {'A', 'D', 1}, {'C', 'E', 1}, {'C', 'D', 1}, {'B', 'D', 1}, {'G', 'H', 1}, {'G', 'I', 1}, {'H', 'I', 1}, {'H', 'F', 1}, {'I', 'J', 1}};
    do
    {
        system("cls"); // 清屏
        displayMainMenu();
        fflush(stdin); // 清空输入缓冲区
        select = -1;
        scanf("%d", &select);
        switch (select)
        {
        // 测试邻接矩阵存储结构
        case ADJMATRIX:
        {
            MGraph G;
            CreateGraph_M(&G, UDG, vexs, 10, arcs, 10);
            test_M(&G);
            break;
        }
        // 测试邻接表存储结构
        case ADJLIST:
        {
            ALGraph G;
            CreateGraph_AL(&G, UDG, vexs, 10, arcs, 10);
            test_AL(&G);
            break;
        }
        // 退出
        case EXIT:
            printf("已退出程序!\n谢谢使用!\n");
            break;
        // 输入错误
        default:
            printf("输入错误,请重试!\n");
            puts("按任意键以继续...");
            system("pause");
            break;
        }
    } while (select != EXIT);

    return 0;
}
