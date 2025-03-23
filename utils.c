#include "./utils.h"
#include <stdio.h>


void readInputFile(int comps, int loads, int compWeights[], int compVolumes[], int loadWeights[], int loadVolumes[], int loadPrices[]) {
    for (int i = 0; i < comps; i++) {
        scanf("%d %d", &compWeights[i], &compVolumes[i]);
    }
    for (int i = 0; i < loads; i++) {
        scanf("%d %d %d", &loadWeights[i], &loadVolumes[i], &loadPrices[i]);
    }

    printf("carregou");
}

void createLpSolveFormatFile(int comps, int loads, int compWeights[], int compVolumes[], int loadWeights[], int loadVolumes[], int loadPrices[]) {
    FILE *file = fopen("lp_problem.lp", "w");
    fprintf(file, "max: ");
    for (int i = 0; i < loads; i++) {
        fprintf(file, "%d x%d ", loadPrices[i], i);
        if (i != loads - 1) {
            fprintf(file, "+ ");
        }
    }
    fprintf(file, ";\n");

    for (int i = 0; i < comps; i++) {
        for (int j = 0; j < loads; j++) {
            fprintf(file, "%d x%d ", loadVolumes[j], j);
            if (j != loads - 1) {
                fprintf(file, "+ ");
            }
        }
        fprintf(file, "<= %d;\n", compVolumes[i]);
    }

    for (int i = 0; i < comps; i++) {
        for (int j = 0; j < loads; j++) {
            fprintf(file, "%d x%d ", loadWeights[j], j);
            if (j != loads - 1) {
                fprintf(file, "+ ");
            }
        }
        fprintf(file, "<= %d;\n", compWeights[i]);
    }

    for (int i = 0; i < loads; i++) {
        fprintf(file, "x%d >= 0;\n", i);
    }

    fclose(file);
}