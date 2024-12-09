#include "test.h"

void test_M(MGraph *Gptr)
{
    int select;
    do
    {
        printf("---------------------------------------------\n");
        printMGraph(*Gptr);
        printf("---------------------------------------------\n");
        displayTestMenu_M();
        scanf("%d", &select);
        switch (select)
        {
        case 1:
        {
            VexType v;
            int i;
            printf("请输入要查找的顶点v: ");
            scanf("%c", v);
            i = LocateVex_M(*Gptr, v);
            if (i != -1)
                printf("顶点%c在图G中的位序为%d\n", v, i);
            else
                printf("顶点%c不在图中\n", v);
        }
        case 2:
        {
            int k;
            VexType w;
            printf("请输入要取值的顶点w: ");
            scanf("%d", k);
            if (ERROR != GetVex_M(Gptr, k, &w))
                printf("顶点%d的值为%c\n", k, w);
            else
                printf("顶点%d不存在\n", k);
        }
        case 3:
        {
        }
        case 4:
        {
        }
        case 5:
        {
        }
        case 6:
        {
        }
        case 7:
        {
        }
        case 8:
        {
            printf("MGraph_DFS:\n");
            DFSTraverse_M(*Gptr, visit);
            printf("\n");
        }
        case 9:
        {
            printf("MGraph_BFS:\n");
            BFSTraverse_M(*Gptr, visit);
            printf("\n");
        }
        case EXIT:
            system("cls");
            break;
        default:
            printf("输入错误,请重试!\n");
            break;
        }
        fflush(stdin); // 清空输入缓冲区
        if(select != EXIT)
        {
            puts("按任意键继续...");
            system("pause");
            system("cls");
        }
    } while (select != EXIT);
    DestroyGraph_M(Gptr);
}

void test_AL(ALGraph *Gptr)
{
    int select;
    do
    {
        printf("---------------------------------------------\n");
        printALGraph(*Gptr);
        printf("---------------------------------------------\n");
        displayTestMenu_AL();
        scanf("%d", &select);
        switch (select)
        {
        case 1:
        {
            VexType v;
            int i;
            printf("请输入要查找的顶点v: ");
            scanf("%c", v);
            i = LocateVex_AL(*Gptr, v);
            if (i != -1)
                printf("顶点%c在图G中的位序为%d\n", v, i);
            else
                printf("顶点%c不在图中\n", v);
        }
        case 2:
        {
            int k;
            VexType w;
            printf("请输入要取值的顶点w: ");
            scanf("%d", k);
            if (ERROR != GetVex_AL(*Gptr, k, &w))
                printf("顶点%d的值为%c\n", k, w);
            else
                printf("顶点%d不存在\n", k);
        }
        case 3:
        {
        }
        case 4:
        {
        }
        case 5:
        {
        }
        case 6:
        {
        }
        case 7:
        {
        }
        case 8:
        {
            printf("ALGraph_DFS:\n");
            DFSTraverse_AL(*Gptr, visit);
            printf("\n");
        }
        case 9:
        {
            printf("ALGraph_BFS:\n");
            BFSTraverse_AL(*Gptr, visit);
            printf("\n");
        }
        case EXIT:
            system("cls");
            break;
        default:
            printf("输入错误,请重试!\n");
            break;
        }
        fflush(stdin); // 清空输入缓冲区
        if(select != EXIT)
        {
            puts("按任意键继续...");
            system("pause");
            system("cls");
        }
    } while (select != EXIT);
    DestroyGraph_AL(Gptr);
}

void displayMainMenu()
{
    printf("数据结构实验无向图测试\n");
    printf("-----------------------\n");
    printf("1. 测试邻接矩阵\n");
    printf("2. 测试邻接表\n");
    printf("0. 退出\n");
    printf("-----------------------\n");
    printf("请输入你的选择: ");
}

void displayTestMenu_M()
{
    printf("1. 查找顶点v在图G中的位序 LocateVex_M()\n");
    printf("2. 取图G的k顶点的值到w GetVex_M()\n");
    printf("3. 对图G的k顶点赋值w PutVex_M()\n");
    printf("4. 求图G中k顶点的第一个邻接顶点的位序 FirstAdjVex_M()\n");
    printf("5. 求图G中k顶点相对于m顶点的下一个邻接顶点的位序 NextAdjVex_M()\n");
    printf("6. 在图G中增加k顶点到m顶点的边或弧 AddArc_M()\n");
    printf("7. 在图G中删除k顶点到m顶点的边或弧 RemoveArc_M()\n");
    printf("8. 深度优先遍历图G DFSTraverse_M()\n");
    printf("9. 广度优先遍历图G BFSTraverse_M()\n");
    printf("0. 返回\n");
    printf("---------------------------------------------\n");
    printf("请输入你的选择: ");
}

void displayTestMenu_AL()
{
    printf("1. 查找顶点v在图G中的位序 LocateVex_AL()\n");
    printf("2. 取图G的k顶点的值到w GetVex_AL()\n");
    printf("3. 对图G的k顶点赋值w PutVex_AL()\n");
    printf("4. 求图G中k顶点的第一个邻接顶点的位序 FirstAdjVex_AL()\n");
    printf("5. 求图G中k顶点相对于k顶点的下一个邻接顶点的位序 NextAdjVex_AL()\n");
    printf("6. 在图G中增加k顶点到m顶点的边或弧 AddArc_AL()\n");
    printf("7. 在图G中删除k顶点到m顶点的边或弧 RemoveArc_AL()\n");
    printf("8. 深度优先遍历图G DFSTraverse_AL()\n");
    printf("9. 广度优先遍历图G BFSTraverse_AL()\n");
    printf("0. 返回\n");
    printf("---------------------------------------------\n");
    printf("请输入你的选择: ");
}