#include <stdio.h>
#include "./utils.h"


// 3 4 // 3 é o numero de compartimentos e 4 é o numero de cargas
// 10 6800 // 10 é o peso e 6800 é o volume
// 16 8700
// 8 5300
// 18 480 310 // 18 é o peso, 480 é o volume e 310 é o volume
// 15 650 380
// 23 580 350
// 12 390 285
int main () {
    int comps, loads;
    scanf("%d %d", &comps, &loads);
    
    int compWeights[comps], compVolumes[comps], loadWeights[loads], loadVolumes[loads], loadPrices[loads];
    readInputFile(comps, loads, compWeights, compVolumes, loadWeights, loadVolumes, loadPrices);
    createLpSolveFormatFile(comps, loads, compWeights, compVolumes, loadWeights, loadVolumes, loadPrices);

    return 0;
}