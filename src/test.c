#include "test.h"

void test_M(MGraph *Gptr)
{
    int select;
    do
    {
        system("cls");
        printf("---------------------------------------------\n");
        printMGraph(*Gptr);
        printf("---------------------------------------------\n");
        displayTestMenu_M();
        select = -1;
        fflush(stdin); // 清空输入缓冲区
        scanf("%d", &select);
        fflush(stdin); // 清空输入缓冲区
        switch (select)
        {
        case 1:
        {
            VexType v;
            int i;
            printf("请输入要查找的顶点v: ");
            scanf("%c", &v);
            i = LocateVex_M(*Gptr, v);
            if (i != -1)
                printf("顶点%c在图G中的位序为%d\n", v, i);
            else
                printf("顶点%c不在图中\n", v);
            break;
        }
        case 2:
        {
            int k = -1;
            VexType w;
            printf("请输入要取值的顶点k: ");
            scanf("%d", &k);
            if (k < 0)
                printf("输入有误,请重试!\n");
            else if (ERROR != GetVex_M(*Gptr, k, &w))
                printf("顶点%d的值为%c\n", k, w);
            else
                printf("顶点%d不存在\n", k);
            break;
        }
        case 3:
        {
            int k = -1;
            VexType w;
            printf("请输入要赋值的顶点k: ");
            scanf("%d", &k);
            if (k < 0)
            {
                printf("输入有误,请重试!\n");
                break;
            }
            printf("请输入要赋的值w: ");
            fflush(stdin); // 清空输入缓冲区
            scanf("%c", &w);
            if (ERROR != PutVex_M(*Gptr, k, w))
                printf("顶点%d现在的值为%c\n", k, w);
            else
                printf("顶点%d不存在\n", k);
            break;
        }
        case 4:
        {
            test_FirstAdjVex_M(Gptr);
            break;
        }
        case 5:
        {
            break;
        }
        case 6:
        {
            break;
        }
        case 7:
        {
            break;
        }
        case 8:
        {
            printf("MGraph_DFS:\n");
            DFSTraverse_M(*Gptr, visit);
            printf("\n");
            break;
        }
        case 9:
        {
            printf("MGraph_BFS:\n");
            BFSTraverse_M(*Gptr, visit);
            printf("\n");
            break;
        }
        case EXIT:
            system("cls");
            break;
        default:
            printf("输入错误,请重试!\n");
            break;
        }
        if (select != EXIT)
        {
            puts("按任意键以继续...");
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
        system("cls");
        printf("---------------------------------------------\n");
        printALGraph(*Gptr);
        printf("---------------------------------------------\n");
        displayTestMenu_AL();
        select = -1;
        fflush(stdin); // 清空输入缓冲区
        scanf("%d", &select);
        fflush(stdin); // 清空输入缓冲区
        switch (select)
        {
        case 1:
        {
            VexType v;
            int i;
            printf("请输入要查找的顶点v: ");
            scanf("%c", &v);
            i = LocateVex_AL(*Gptr, v);
            if (i != -1)
                printf("顶点%c在图G中的位序为%d\n", v, i);
            else
                printf("顶点%c不在图中\n", v);
            break;
        }
        case 2:
        {
            int k = -1;
            VexType w;
            printf("请输入要取值的顶点w: ");
            scanf("%d", &k);
            if (k < 0)
                printf("输入有误,请重试!\n");
            else if (ERROR != GetVex_AL(*Gptr, k, &w))
                printf("顶点%d的值为%c\n", k, w);
            else
                printf("顶点%d不存在\n", k);
            break;
        }
        case 3:
        {
            int k = -1;
            VexType w;
            printf("请输入要赋值的顶点k: ");
            scanf("%d", &k);
            if (k < 0)
            {
                printf("输入有误,请重试!\n");
                break;
            }
            printf("请输入要赋的值w: ");
            fflush(stdin); // 清空输入缓冲区
            scanf("%c", &w);
            if (ERROR != PutVex_AL(*Gptr, k, w))
                printf("顶点%d现在的值为%c\n", k, w);
            else
                printf("顶点%d不存在\n", k);
            break;
        }
        case 4:
        {
            test_FirstAdjVex_AL(Gptr);
            break;
        }
        case 5:
        {
            break;
        }
        case 6:
        {
            break;
        }
        case 7:
        {
            break;
        }
        case 8:
        {
            printf("ALGraph_DFS:\n");
            DFSTraverse_AL(*Gptr, visit);
            printf("\n");
            break;
        }
        case 9:
        {
            printf("ALGraph_BFS:\n");
            BFSTraverse_AL(*Gptr, visit);
            printf("\n");
            break;
        }
        case EXIT:
            system("cls");
            break;
        default:
            printf("输入错误,请重试!\n");
            break;
        }
        if (select != EXIT)
        {
            puts("按任意键以继续...");
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


void test_FirstAdjVex_M(MGraph *Gptr)
{
    int k = -1,i;
    printf("请输入要求的第一个邻接顶点的顶点k: ");
    scanf("%d", &k);
    if (k < 0)
    {
        printf("输入有误,请重试!\n");
        return ;
    }
    i = FirstAdjVex_M(*Gptr, k);
    if(i < 0)
        printf("顶点%d没有邻接顶点!\n", k);
    else
        printf("顶点%d的第一个邻接顶点是%d\n", k, i);
}

void test_FirstAdjVex_AL(ALGraph *Gptr)
{
    int k = -1,i;
    AdjVexNodeP p;
    printf("请输入要求的第一个邻接顶点的顶点k: ");
    scanf("%d", &k);
    if (k < 0)
    {
        printf("输入有误,请重试!\n");
        return ;
    }
    i = FirstAdjVex_AL(*Gptr, k, &p);
    if(i < 0)
        printf("顶点%d没有邻接顶点!\n", k);
    else
        printf("顶点%d的第一个邻接顶点是%d\n", k, i);
}