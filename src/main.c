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
        displayMenu();
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
            break;
        }
        fflush(stdin); //清空输入缓冲区
        puts("按任意键继续...");
        system("pause");
        system("cls"); //清屏
    }
    while(select != EXIT);
    
    return 0;
}
