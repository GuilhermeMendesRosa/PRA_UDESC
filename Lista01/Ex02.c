#include <stdio.h>

//Dado um vetor de números inteiros v, retorne um novo vetor de forma que cada
//elemento no índice i seja o produto de todos os números na matriz original, com
//exceção de i.
//Exemplo 1: dado v = [1,2,3,4,5], a saída esperada é [120,60,40,30,24]
//Exemplo 2: dado v = [3,2,1], a saída esperada é [2,3,6]

// Default
void main2() {

    int loops = 0;

    int size = 5;
    int source[] = {1, 2, 3, 4, 5};
    int result[size];

    for (int i = 0; i < size; ++i) {
        int product = 1;
        for (int j = 0; j < size; ++j) {
            if (i == j) {
                continue;
            }

            product *= source[j];
            loops++;
        }

        result[i] = product;
    }

    printf("%d - %d - %d - %d - %d = %d", result[0], result[1], result[2], result[3], result[4], loops);

}

// Optimatized
void main2Optimatized() {

    int loops = 0;

    int size = 5;
    int source[] = {1, 2, 3, 4, 5};
    int result[size];
    int left_product[size], right_product[size];

    left_product[0] = 1;
    for (int i = 1; i < size; ++i) {
        left_product[i] = left_product[i - 1] * source[i - 1];
        loops++;
    }

    right_product[size - 1] = 1;
    for (int i = size - 2; i >= 0; --i) {
        right_product[i] = right_product[i + 1] * source[i + 1];
        loops++;
    }

    for (int i = 0; i < size; ++i) {
        result[i] = left_product[i] * right_product[i];
        loops++;
    }

    printf("%d - %d - %d - %d - %d = %d", result[0], result[1], result[2], result[3], result[4], loops);

}
