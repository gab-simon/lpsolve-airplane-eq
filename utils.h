#include <stdio.h>


void readInputFile(int *comps, int *loads, int compWeights[], int compVolumes[], int loadWeights[], int loadVolumes[]);

void createLpSolveFormatFile(int comps, int loads, int compWeights[], int compVolumes[], int loadWeights[], int loadVolumes[]);