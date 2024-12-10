#ifndef __TEST_H__
#define __TEST_H__

#include "UDGraph.h"

#define EXIT 0
#define ADJMATRIX 1
#define ADJLIST 2

void test_M(MGraph *Gptr);
void test_AL(ALGraph *Gptr);
void displayMainMenu();
void displayTestMenu_M();
void displayTestMenu_AL();

void test_LocateVex_M(MGraph *Gptr);
void test_GetVex_M(MGraph *Gptr);
void test_PutVex_M(MGraph *Gptr);
void test_FirstAdjVex_M(MGraph *Gptr);
void test_NextAdjVex_M(MGraph *Gptr);
void test_AddArc_M(MGraph *Gptr);
void test_RemoveArc_M(MGraph *Gptr);
void test_DFS_M(MGraph *Gptr);
void test_BFS_M(MGraph *Gptr);

void test_LocateVex_AL(ALGraph *Gptr);
void test_GetVex_AL(ALGraph *Gptr);
void test_PutVex_AL(ALGraph *Gptr);
void test_FirstAdjVex_AL(ALGraph *Gptr);
void test_NextAdjVex_AL(ALGraph *Gptr);
void test_AddArc_AL(ALGraph *Gptr);
void test_RemoveArc_AL(ALGraph *Gptr);
void test_DFS_AL(ALGraph *Gptr);
void test_BFS_AL(ALGraph *Gptr);

#endif // __TEST_H__