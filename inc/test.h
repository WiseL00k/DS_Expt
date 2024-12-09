#ifndef __TEST_H__
#define __TEST_H__

#include "UDGraph.h"

#define ADJMATRIX 1
#define ADJLIST 2
#define EXIT 3

void test_M(MGraph *G);
void test_AL(ALGraph *G);
void displayMenu();

#endif // __TEST_H__