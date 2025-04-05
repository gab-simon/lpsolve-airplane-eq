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
#include <stdio.h>

void restriction_weight(int k, int n, int *w) {
    printf("\n");
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            printf("x%d%d", i , j );
            if (j != n ) printf(" + ");
        }
        printf(" <= %d;\n", w[i]);
    }
}

void restriction_volume(int k, int n, int *v, int *p, int *t) {
    printf("\n");
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%f x%d%d ", (double)t[j]/p[j], i, j);
            if (j < n) printf("+ ");
        }
        printf("<= %d;\n", v[i]);
    }
}

void restriction_availability(int k, int n, int *p) {
    printf("\n");
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= k; i++) {
            printf("x%d%d", i , j );
            if (i != k) printf( " + ");
        }
        printf(" <= %d;\n", p[j]);
    }
}

void restriction_balance(int k, int n, int *w) {
    printf("\n");
    int soma = 0;
    for (int i = 1; i <= k; i++) {
        soma += w[i];
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%.8f x%d%d - x%d%d ", (double)w[i]/soma , (i % k) + 1, j, i, j);
            if ( j != n ) printf(" + ");
        }
        printf(" <= 0;\n");
    }
}

void restriction_positive(int k, int n) {
    printf("\n");
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            printf("x%d%d >= 0; ", i + 1, j + 1);
        }
        printf("\n");
    }
}

void restrictions(int k, int n, int *w, int *v, int *p, int *t, int *g) {
    restriction_weight(k, n, w);
    restriction_volume(k, n, v, p, t);
    restriction_availability(k, n, p);
    restriction_balance(k, n, w);
    restriction_positive(k, n);
}



