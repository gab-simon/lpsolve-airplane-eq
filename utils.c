#include "./utils.h"
#include <stdio.h>

void readInputFile(int comps, int loads, int compWeights[], int compVolumes[], int loadWeights[], int loadVolumes[], int loadPrices[]) {
    for (int i = 0; i < comps; i++) {
        scanf("%d %d", &compWeights[i], &compVolumes[i]);
    }
    for (int i = 0; i < loads; i++) {
        scanf("%d %d %d", &loadWeights[i], &loadVolumes[i], &loadPrices[i]);
    }
}

void createLpSolveFormatFile(int comps, int loads, int compWeights[], int compVolumes[],
    int loadWeights[], int loadVolumes[], int loadPrices[]) {
    FILE *file = fopen("lp_problem.lp", "w");
    if (!file) {
        perror("Error opening file");
        return;
    }

    // Função objetivo
    fprintf(file, "max: ");
    for (int i = 0; i < comps; i++) {
        for (int j = 0; j < loads; j++) {
            fprintf(file, "%d x%d_%d", loadPrices[j], i + 1, j + 1);
            if (i != comps - 1 || j != loads - 1) fprintf(file, " + ");
        }
    }
    fprintf(file, ";\n");

    // Restrição de volume
    for (int i = 0; i < comps; i++) {
        for (int j = 0; j < loads; j++) {
            fprintf(file, "%.2f x%d_%d", (double)loadVolumes[j] / loadWeights[j], i + 1, j + 1);
            if (j != loads - 1) fprintf(file, " + ");
        }
        fprintf(file, " <= %d;\n", compVolumes[i]);
    }

    // Restrição de peso
    for (int i = 0; i < comps; i++) {
        for (int j = 0; j < loads; j++) {
            fprintf(file, "x%d_%d", i + 1, j + 1);
            if (j != loads - 1) fprintf(file, " + ");
        }
        fprintf(file, " - %d r = 0;\n", compWeights[i]);
    }

    // Restrição de disponibilidade das cargas
    for (int j = 0; j < loads; j++) {
        for (int i = 0; i < comps; i++) {
            fprintf(file, "x%d_%d", i + 1, j + 1);
            if (i != comps - 1) fprintf(file, " + ");
        }
        fprintf(file, " <= %d;\n", loadWeights[j]);
    }

    // Restrição para a variável r, que é a fração que da pra utilizar os compartimentos, entre 0 e 1
    fprintf(file, "r <= 1;\n");
    fprintf(file, "r >= 0;\n");

    // Restrição para as cargas alocadas serem positivas
    for (int i = 0; i < comps; i++) {
        for (int j = 0; j < loads; j++) {
            fprintf(file, "x%d_%d >= 0;\n", i + 1, j + 1);
        }
    }

    fclose(file);
}