#include <stdio.h>
#include <stdlib.h>

//Dado um vetor de números inteiros v, encontre o primeiro inteiro positivo ausente no
//vetor. Em outras palavras, deve ser retornado o menor inteiro positivo que não existe no
//vetor. A matriz pode conter duplicados e números negativos também. O algoritmo deve
//apresentar complexidade de tempo linear e de espaço constante (pode desconsiderar
//                                                                       o esforço para ordenação do vetor).
//Exemplo 1, dado v = [3,4,-1,1], a saída esperada é 2
//Exemplo 2, dado v = [1,2,0], a saída esperada é 3

int compara(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

void main() {
    int size = 5;
    int array[] = {2, 9, 5, 1, 5};

    qsort(array, size, sizeof(int), compara);

    int result = array[size - 1] + 1;

    printf("%d", result);
}