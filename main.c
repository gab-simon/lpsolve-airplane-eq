#include <stdio.h>
#include "./utils.h"

int main () {
    int k, n;
    scanf("%d %d", &k, &n);
    
    int w[k], v[k], p[n], t[n], g[n];

    readInput(k, n, w, v, p, t, g);
    objectiveFunction(k, n, g);
    restrictions(k, n, w, v, p, t, g);

    return 0;
}
