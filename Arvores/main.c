#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Arvores/ArvoreAVL.c"
#include "Arvores/ArvoreB.c"
#include "Arvores/ArvoreRB.c"

void main()
{
    ArvoreAVL *arvoreAVL = criaArvoreAVL();
    ArvoreRB *arvoreRB = criarArvoreRB();
    ArvoreB *arvoreBOrdem1 = criaArvoreB(1);
    ArvoreB *arvoreBOrdem5 = criaArvoreB(5);
    ArvoreB *arvoreBOrdem10 = criaArvoreB(10);

    // Populando vetor de números aleatórios
    int numerosASeremInseridos[1000];

    srand(time(NULL));

    for (int i = 0; i < 1000; i++)
    {
        numerosASeremInseridos[i] = rand() % 1000 + 1;
    }

    for (int i = 0; i < 1000; i++)
    {
        int valor = numerosASeremInseridos[i];

        adicionarChaveAVL(arvoreAVL, valor);
        adicionarChaveRB(arvoreRB, valor);
        adicionaChaveB(arvoreBOrdem1, valor);
        adicionaChaveB(arvoreBOrdem5, valor);
        adicionaChaveB(arvoreBOrdem10, valor);
    }
}
