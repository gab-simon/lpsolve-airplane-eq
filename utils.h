#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>

void readInput(int k, int n, int *w, int *v, int *p, int *t, int *g);

void objectiveFunction(int k, int n, int *g);

void restrictions(int k, int n, int *w, int *v, int *p, int *t, int *g);

#endif
