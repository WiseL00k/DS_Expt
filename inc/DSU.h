#ifndef __DSU_H__
#define __DSU_H__

#include <stdlib.h>
#include <stdio.h>

/* 使用者可自行进行宏定义，以选择不同的并查集合并方式 */
#ifdef USE_WUR_UNION
#define UnionMFSet UnionMFSet_WUR
#endif

#ifdef USE_PC_UNION
#define UnionMFSet UnionMFSet_PC
#define FindMFset FindPCMFSet_PC_ite
#endif

typedef enum
{
    ERROR = -1,
    FALSE,
    TRUE,
    OK,
    OVERFLOW,
} Status; // 状态码

typedef struct // 并查集
{
    int *parent;
    int n;
} PForest, MFSet, *MFSetPtr;

Status InitMFSet(MFSet *S, int n);             // 初始化并查集S
Status DestroyMFSet(MFSet *S);                 // 销毁并查集S
int FindMFset(MFSet *S, int i);                // 查找并查集S中元素i所属的集合
int FindPCMFSet_PC_ite(MFSet *S, int i);       // 查找并查集S中元素i所属的集合，同时压缩路径
Status DiffMFSet(MFSet *S, int i, int j);      // 判断并查集S中元素i和j是否属于同一个集合
Status UnionMFSet(MFSet *S, int i, int j);     // 合并并查集S中元素i和j所属的两个集合
Status UnionMFSet_WUR(MFSet *S, int i, int j); // 合并并查集S中元素i和j所属的两个集合，采用加权合并原则
Status UnionMFSet_PC(MFSet *S, int i, int j);  // 合并并查集S中元素i和j所属的两个集合，同时压缩路径
Status hasRelation(MFSet *S, int i, int j);    // 判断并查集S中元素i和j是否属于同一个集合
Status displayMFSet(MFSet *S);                 // 可视化并查集S

#endif /* __DSU_H__ */