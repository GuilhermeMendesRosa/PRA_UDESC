#include <stdio.h>
#include <string.h>

void main() {

    char string1[100];
    char string2[100];

    printf("String 1: ");
    scanf("%s", string1);

    printf("String 2: ");
    scanf("%s", string2);

    int tamanhoS1 = strlen(string1);
    int tamanhoS2 = strlen(string2);

    int matriz[tamanhoS1][tamanhoS2];

    for (int i = 0; i < tamanhoS1; i++) {
        matriz[i][0] = i;
    }

    for (int i = 0; i < tamanhoS2; i++) {
        matriz[0][i] = i;
    }

    for (int i = 1; i < tamanhoS1; i++) {
        for (int j = 0; j < tamanhoS2; j++) {
            int custo = (string1[i] != string2[j]) ? 1 : 0;

            int valor1 = matriz[i - 1][j] + 1;
            int valor2 = matriz[i][j - 1] + 1;
            int valor3 = matriz[i - 1][j - 1] + custo;

            int menorValor = valor1;

            if (valor2 < menorValor) {
                menorValor = valor2;
            }

            if (valor3 < menorValor) {
                menorValor = valor3;
            }

            matriz[i][j] = menorValor;
        }
    }

    int quantidadeOperacoes = matriz[tamanhoS1 - 1][tamanhoS2 - 1];

    printf("%d operacoes", quantidadeOperacoes);

}