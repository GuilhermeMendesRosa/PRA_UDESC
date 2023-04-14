#include <stdlib.h>
#include <stdio.h>

void main() {

    // Inserir o tamanho aqui
    int tamanho = 10;

    // Definir as luvas
    int luvas[] = {0, 2, 2, 2, 3, 1, 2, 2, 2, 3};

    int quantidadePares = 0;

    // Limpa o array de posições
    int posicoesMarcadas[tamanho];
    for (int i = 0; i < tamanho; i++) {
        posicoesMarcadas[i] = 0;
    }

    for (int i = 0; i < tamanho; i++) {
        int luvaProcurada = luvas[i];

        for (int j = 0; j < tamanho; j++) {
            if (j == i || posicoesMarcadas[i] == 1 || posicoesMarcadas[j] == 1) {
                continue;
            }

            int luvaAtual = luvas[j];

            if (luvaProcurada == luvaAtual) {
                quantidadePares++;
                posicoesMarcadas[i] = 1;
                posicoesMarcadas[j] = 1;
            }
        }
    }

    printf("%d pares", quantidadePares);

}