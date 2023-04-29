#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int compara(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int *geraVetor(int n) {
    int *v = malloc(sizeof(int) * n);
    int i;

    for (i = 0; i < n; i++) {
        v[i] = rand() % n;
    }

    qsort(v, n, sizeof(int), compara);

    return v;
}

int pesquisaSequencial(int chave, int v[], int n) {
    int contador = 1;
    int i;

    for (i = 0; i < n; i++) {
        contador++;
        if (v[i] == chave) {
            return contador;
        }
        contador++;
    }

    return contador; //índice inválido
}

int pesquisaSequencialSentinela(int chave, int v[], int n) {
    int contador = 1, i = 0;
    v[n] = chave; //A última posição do vetor possui o sentinela
    while (v[i] != chave) {
        i++;
        contador++;
    }
    contador++;
    if (i < n) {
        return contador;
    }
    return contador; //Índice inválido
}

int pesquisaBinaria(int chave, int v[], int n) {
    int inicio = 0, fim = n - 1, contador = 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        contador++;
        if (chave == v[meio]) {
            return contador;
        } else if (chave < v[meio]) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }

        contador += 2;
    }

    return contador; //Índice inválido
}

int pesquisaInterpolacao(int chave, int v[], int n) {
    int inicio = 0, meio, fim = n - 1, contador = 1;

    if (v[inicio] == v[fim]) {
        contador++;
        return v[inicio] == chave ? contador : contador;
    }

    contador += 3;

    while (inicio <= fim && chave >= v[inicio] && chave <= v[fim]) {
        contador++;

        if (inicio == fim) {
            contador++;
            return v[inicio] == chave ? contador : contador;
        }

        meio = inicio + (((double) (fim - inicio) / (v[fim] - v[inicio])) * (chave - v[inicio]));

        contador++;

        if (chave == v[meio]) {
            return contador;
        } else if (chave < v[meio]) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }

        contador += 4;
    }

    return contador; //Índice inválido
}

int main() {
    int n = 1000000;
    int *v = geraVetor(n + 1);
    int i;

    int mediaSequencial = 0;
    int mediaSentinela = 0;
    int mediaBinaria = 0;
    int mediaInterpolacao = 0;
    int repeticoes = 30;

    for (i = 0; i < repeticoes; i++) {
        int medio = rand() % n;
        mediaSequencial += pesquisaSequencial(medio, v, n);
        mediaSentinela += pesquisaSequencialSentinela(medio, v, n);
        mediaBinaria += pesquisaBinaria(medio, v, n);
        mediaInterpolacao += pesquisaInterpolacao(medio, v, n);
    }

    mediaSequencial /= repeticoes;
    mediaSentinela /= repeticoes;
    mediaBinaria /= repeticoes;
    mediaInterpolacao /= repeticoes;

    printf("Pesquisa sequencial\n");
    printf("Caso medio: %d\n\n", mediaSequencial);

    printf("Pesquisa sequencial com sentinela\n");
    printf("Caso medio: %d\n\n", mediaSentinela);

    printf("Pesquisa binaria\n");
    printf("Caso medio: %d\n\n", mediaBinaria);

    printf("Pesquisa interpolacao\n");
    printf("Caso medio: %d\n\n", mediaInterpolacao);
}
