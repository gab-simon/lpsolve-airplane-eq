#include "./utils.h"
#include <stdio.h>

void readInput(int k, int n, int *w, int *v, int *p, int *t, int *g) {
	for (int i = 1; i <= k; i++) {
		scanf("%d %d", &w[i], &v[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &p[i], &t[i], &g[i]);
	}
}

void objectiveFunction(int k, int n, int *g) {

	// Função objetivo
	printf("max: \n");
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d x%d%d", g[j], i , j );
			if (i != k  || j != n ) printf(" + ");
		}
		if (i != k) { printf("\n"); } else { printf(";\n");}
	}
	printf("\n");
}


void restrictions(int k, int n, int *w, int *v, int *p, int *t, int *g) {

	printf("\n");
	// Restrição de peso
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			printf("x%d%d", i , j );
			if (j != n ) printf(" + ");
		}
		printf(" <= %d;\n", w[i]);
	}

	printf("\n");
	// restrição de volume
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%f x%d%d ", (double)t[j]/p[j], i, j);
			if (j < n) printf("+ ");
		}
		printf("<= %d;\n", v[i]);
	}

	printf("\n");
	// Restrição de disponibilidade das cargas
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= k; i++) {
			printf("x%d%d", i , j );
			if (i != k) printf( " + ");
		}
		printf(" <= %d;\n", p[j]);
	}

	// restrição equilíbrio de cargas
	printf("\n");
	int soma = 0;
	for (int i = 1; i <= k; i++) {
		soma += w[i];
	}

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%.8f x%d%d - x%d%d ", (double)w[i] / soma, (i % k) + 1, j, i, j);
			if ( j != n ) printf(" + ");
		}
		
		printf(" <= 0;\n");
	}

	printf("\n");
	// Restrição para as cargas alocadas serem positivas
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			printf("x%d%d >= 0; ", i + 1, j + 1);
		}
		printf("\n");
	}


}

