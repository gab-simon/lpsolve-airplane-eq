#include "./utils.h"
#include <stdio.h>


void readInputFile(int *comps, int *loads, int compWeights[], int compVolumes[], int loadWeights[], int loadVolumes[]) {
    scanf("%d %d", comps, loads);
    for (int i = 0; i < *comps; i++) {
        scanf("%d %d", &compWeights[i], &compVolumes[i]);
    }
    for (int i = 0; i < *loads; i++) {
        scanf("%d %d", &loadWeights[i], &loadVolumes[i]);
    }
}

void createLpSolveFormatFile(int comps, int loads, int compWeights[], int compVolumes[], int loadWeights[], int loadVolumes[]) {
    FILE *file = fopen("lp_problem.lp", "w");
    fprintf(file, "max: ");
    for (int i = 0; i < comps; i++) {
        fprintf(file, "%d x%d", compWeights[i], i);
        if (i < comps - 1) {
            fprintf(file, " + ");
        }
    }
    fprintf(file, ";\n");
    for (int i = 0; i < loads; i++) {
        fprintf(file, "%d x%d <= %d;\n", loadWeights[i], i, loadVolumes[i]);
    }
    for (int i = 0; i < comps; i++) {
        fprintf(file, "x%d >= 0;\n", i);
    }
    fclose(file);
}