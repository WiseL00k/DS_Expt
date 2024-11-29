#include <stdio.h>
#include "DSU.h"

#define USE_WUR_UNION // 采用加权合并原则
#define MFSET_SIZE 10

int main(void)
{
    MFSet S;
    InitMFSet(&S, MFSET_SIZE);
    UnionMFSet(&S, 0, 1);
    UnionMFSet(&S, 2, 3);
    UnionMFSet(&S, 1, 3);
    UnionMFSet(&S, 4, 5);
    displayMFSet(&S);
    return 0;
}
