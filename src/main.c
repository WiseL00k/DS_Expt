#include <stdio.h>
#include "DSU.h"

#define MFSET_SIZE 10

int main(void)
{
    MFSet S;
    InitMFSet(&S, MFSET_SIZE); // 初始化集合
    printf("原始并查集:\n");
    displayMFSet(&S);

    UnionMFSet(&S, 0, 1);
    printf("合并0和1后的并查集:\n");
    displayMFSet(&S);

    UnionMFSet(&S, 2, 3);
    printf("合并2和3后的并查集:\n");
    displayMFSet(&S);

    UnionMFSet(&S, 1, 3);
    printf("合并1和3后的并查集:\n");
    displayMFSet(&S);

    UnionMFSet(&S, 4, 5);
    printf("合并4和5后的并查集:\n");
    displayMFSet(&S);

    UnionMFSet(&S, 3, 5);
    printf("合并3和5后的并查集:\n");
    displayMFSet(&S);

    UnionMFSet(&S, 5, 7);
    printf("合并5和7后的并查集:\n");
    displayMFSet(&S);

    return 0;
}
