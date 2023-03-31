#include <stdio.h>
#include <stdlib.h>

/*
Dada um vetor inteiros v, retorne a maior soma dos números não adjacentes. Os
números podem incluir 0 ou negativos no vetor.
○ Exemplo 1, dado v = [2,4,6,2,5], a saída esperada é 13, considerando 2 + 6 + 5
○ Exemplo 2, dado v = [5,1,1,5], a saída esperada é 10, considerando 5 + 5
*/

void main() {

    int biggestSum;
    int size = 5;
    int array[] = {2,4,6,2,5};

    for (int i = 0; i < size; i++) {
        int sum = 0;

        for (int j = i; j < size; j+= 2) {
            sum += array[j];
        }

        if (i == 0) {
            biggestSum = sum;
        } else if (sum > biggestSum) {
            biggestSum = sum;
        }

    }

    printf("%d", biggestSum);

}
