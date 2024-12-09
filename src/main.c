#include <stdio.h>
#include <stdlib.h>
#include "UDGraph.h"
#include "test.h"

int main(void)
{
    int select;
    VexType vexs[5] = {'A', 'B', 'C', 'D', 'E'};
    ArcInfo arcs[5] = {{'A', 'C', 1}, {'A', 'D', 1}, {'C', 'E', 1}, {'C', 'D', 1}, {'B', 'D', 1}};
    do
    {
        system("cls"); // 清屏
        displayMainMenu();
        fflush(stdin); // 清空输入缓冲区
        select = -1;
        scanf("%d", &select);
        switch (select)
        {
        case ADJMATRIX:
        {
            MGraph G;
            CreateGraph_M(&G, UDG, vexs, 5, arcs, 5);
            test_M(&G);
            break;
        }
        case ADJLIST:
        {
            ALGraph G;
            CreateGraph_AL(&G, UDG, vexs, 5, arcs, 5);
            test_AL(&G);
            break;
        }
        case EXIT:
            printf("退出程序\n");
            break;
        default:
            printf("输入错误,请重试!\n");
            puts("按任意键以继续...");
            system("pause");
            break;
        }
    } while (select != EXIT);

    return 0;
}
