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

#endif // __TEST_H__