#include <stdio.h>
#include "DSU.h"

#define MFSET_SIZE 10

int main(void)
{
    MFSet S;
    InitMFSet(&S, MFSET_SIZE); // 初始化集合
    displayMFSet(&S);
    UnionMFSet(&S, 0, 1);
    displayMFSet(&S);
    UnionMFSet(&S, 2, 3);
    displayMFSet(&S);
    UnionMFSet(&S, 1, 3);
    displayMFSet(&S);
    UnionMFSet(&S, 4, 5);
    displayMFSet(&S);
    return 0;
}
