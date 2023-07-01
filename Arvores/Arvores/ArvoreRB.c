#include <stdlib.h>
#include <stdio.h>
#include <time.h>

enum coloracao { Vermelho, Preto };
typedef enum coloracao Cor;

typedef struct rbNo {
    struct rbNo* pai;
    struct rbNo* esquerda;
    struct rbNo* direita;
    Cor cor;
    int valor;
} NoRB;

typedef struct rbArvore {
    struct rbNo* raiz;
    struct rbNo* nulo;
} ArvoreRB;

long int RNcontador = 0;

NoRB* criarNoRB(ArvoreRB* arvore, NoRB* pai, int valor);
void balancearRB(ArvoreRB* arvore, NoRB* no);
void rotaticionarEsquerdaRB(ArvoreRB* arvore, NoRB* no);
void rotacionarDireitaRB(ArvoreRB* arvore, NoRB* no);

ArvoreRB* criarArvoreRB();
int vaziaRB(ArvoreRB* arvore);
NoRB* adicionarChaveRB(ArvoreRB* arvore, int valor);
NoRB* localizarRB(ArvoreRB* arvore, int valor);

ArvoreRB* criarArvoreRB() {
    ArvoreRB *arvore = malloc(sizeof(ArvoreRB));
    arvore->nulo = NULL;
    arvore->raiz = NULL;

    arvore->nulo = criarNoRB(arvore, NULL, 0);
    arvore->nulo->cor = Preto;

    return arvore;
}

int vaziaRB(ArvoreRB* arvore) {
    return arvore->raiz == NULL;
}

NoRB* criarNoRB(ArvoreRB* arvore, NoRB* pai, int valor) {
    NoRB* no = malloc(sizeof(NoRB));

    no->pai = pai;
    no->valor = valor;
    no->direita = arvore->nulo;
    no->esquerda = arvore->nulo;

    return no;
}

NoRB* adicioanrNoRB(ArvoreRB* arvore, NoRB* no, int valor) {
    RNcontador++;
    if (valor > no->valor) {
        if (no->direita == arvore->nulo) {
            no->direita = criarNoRB(arvore, no, valor);
            no->direita->cor = Vermelho;

            return no->direita;
        } else {
            return adicioanrNoRB(arvore, no->direita, valor);
        }
    } else {
        if (no->esquerda == arvore->nulo) {
            no->esquerda = criarNoRB(arvore, no, valor);
            no->esquerda->cor = Vermelho;

            return no->esquerda;
        } else {
            return adicioanrNoRB(arvore, no->esquerda, valor);
        }
    }
}

NoRB* adicionarChaveRB(ArvoreRB* arvore, int valor) {
    RNcontador++;
    if (vaziaRB(arvore)) {
        arvore->raiz = criarNoRB(arvore, arvore->nulo, valor);
        arvore->raiz->cor = Preto;

        return arvore->raiz;
    } else {
        NoRB* no = adicioanrNoRB(arvore, arvore->raiz, valor);
        balancearRB(arvore, no);

        return no;
    }
}

NoRB* localizarRB(ArvoreRB* arvore, int valor) {
    if (!vaziaRB(arvore)) {
        NoRB* no = arvore->raiz;

        while (no != arvore->nulo) {
            if (no->valor == valor) {
                return no;
            } else {
                no = valor < no->valor ? no->esquerda : no->direita;
            }
        }
    }

    return NULL;
}

void percorrerProfundidadeInOrder(ArvoreRB* arvore, NoRB* no, void (*callback)(int)) {
    if (no != arvore->nulo) {


        percorrerProfundidadeInOrder(arvore, no->esquerda,callback);
        callback(no->valor);
        percorrerProfundidadeInOrder(arvore, no->direita,callback);
    }
}

void percorrerProfundidadePreOrder(ArvoreRB* arvore, NoRB* no, void (*callback)(int)) {
    if (no != arvore->nulo) {
        callback(no->valor);
        percorrerProfundidadePreOrder(arvore, no->esquerda,callback);
        percorrerProfundidadePreOrder(arvore, no->direita,callback);
    }
}

void percorrerProfundidadePosOrder(ArvoreRB* arvore, NoRB* no, void (callback)(int)) {
    if (no != arvore->nulo) {
        percorrerProfundidadePosOrder(arvore, no->esquerda,callback);
        percorrerProfundidadePosOrder(arvore, no->direita,callback);
        callback(no->valor);
    }
}

void visitar(int valor){
    printf("%d ", valor);
}

void balancearRB(ArvoreRB* arvore, NoRB* no) {
    while (no->pai->cor == Vermelho) {
        RNcontador++;
        if (no->pai == no->pai->pai->esquerda) {
            NoRB *tio = no->pai->pai->direita;

            if (tio->cor == Vermelho) {
                RNcontador++;
                tio->cor = Preto; //Caso 1
                no->pai->cor = Preto;

                no->pai->pai->cor = Vermelho; //Caso 1
                no = no->pai->pai; //Caso 1
            } else {
                if (no == no->pai->direita) {
                    RNcontador++;
                    no = no->pai; //Caso 2
                    rotaticionarEsquerdaRB(arvore, no); //Caso 2
                } else {
                    RNcontador++;
                    no->pai->cor = Preto;
                    no->pai->pai->cor = Vermelho; //Caso 3
                    rotacionarDireitaRB(arvore, no->pai->pai); //Caso 3
                }
            }
        } else {
            NoRB *tio = no->pai->pai->esquerda;

            if (tio->cor == Vermelho) {
                RNcontador++;
                tio->cor = Preto; //Caso 1
                no->pai->cor = Preto;

                no->pai->pai->cor = Vermelho; //Caso 1
                no = no->pai->pai; //Caso 1
            } else {
                if (no == no->pai->esquerda) {
                    RNcontador++;
                    no = no->pai; //Caso 2
                    rotacionarDireitaRB(arvore, no); //Caso 2
                } else {
                    RNcontador++;
                    no->pai->cor = Preto;
                    no->pai->pai->cor = Vermelho; //Caso 3
                    rotaticionarEsquerdaRB(arvore, no->pai->pai); //Caso 3
                }
            }
        }
    }
    arvore->raiz->cor = Preto; //Conserta possível quebra regra 2
}

void rotaticionarEsquerdaRB(ArvoreRB* arvore, NoRB* no) {
    RNcontador++;
    NoRB* direita = no->direita;
    no->direita = direita->esquerda;

    if (direita->esquerda != arvore->nulo) {
        direita->esquerda->pai = no;
    }

    direita->pai = no->pai;

    if (no->pai == arvore->nulo) {
        arvore->raiz = direita;
    } else if (no == no->pai->esquerda) {
        no->pai->esquerda = direita;
    } else {
        no->pai->direita = direita;
    }

    direita->esquerda = no;
    no->pai = direita;
}

void rotacionarDireitaRB(ArvoreRB* arvore, NoRB* no) {
    RNcontador++;
    NoRB* esquerda = no->esquerda;
    no->esquerda = esquerda->direita;

    if (esquerda->direita != arvore->nulo) {
        esquerda->direita->pai = no;
    }

    esquerda->pai = no->pai;

    if (no->pai == arvore->nulo) {
        arvore->raiz = esquerda;
    } else if (no == no->pai->esquerda) {
        no->pai->esquerda = esquerda;
    } else {
        no->pai->direita = esquerda;
    }

    esquerda->direita = no;
    no->pai = esquerda;
}

