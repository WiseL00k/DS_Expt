#ifndef __DSU_H__
#define __DSU_H__

typedef enum {
    FALSE,
    TRUE,
    OVERFLOW,
} Status;

typedef struct {
    int* parent;
    int n;
}PForest, MFSet;

Status InitMFSet(MFSet *S, int n);
Status DestroyMFSet(MFSet *S);
int FindMFset(MFSet *S, int i);
Status DiffMFSet(MFSet *S, int i, int j);
Status UnionMFSet(MFSet *S, int i, int j);

#endif /* __DSU_H__ */