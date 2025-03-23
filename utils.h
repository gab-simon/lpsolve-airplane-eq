#ifdef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>


void readInputFile(int comps, int loads, int compWeights[], int compVolumes[], int loadWeights[], int loadVolumes[], int loadPrices[]);

void createLpSolveFormatFile(int comps, int loads, int compWeights[], int compVolumes[], int loadWeights[], int loadVolumes[], int loadPrices[]);

#endif