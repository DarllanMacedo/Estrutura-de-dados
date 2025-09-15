#include "FilaEncadeada.h"
#include <string.h>

// Inicializa a fila, definindo os ponteiros de início e fim como nulos.
void inicializarFila(FilaEncadeada* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

// Retorna 1 se a fila estiver vazia, 0 caso contrário.
int filaVazia(FilaEncadeada* f) {
    return f->inicio == NULL;
}

// Adiciona um elemento ao final da fila.
void enqueue(FilaEncadeada* f, Elemento valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) return;

    novoNo->dado = strdup(valor);
    novoNo->proximo = NULL;

    if (filaVazia(f)) {
        f->inicio = novoNo;
    } else {
        f->fim->proximo = novoNo;
    }
    f->fim = novoNo;
}

// Remove o elemento do início da fila.
int dequeue(FilaEncadeada* f, Elemento* valor) {
    if (filaVazia(f)) return 0;

    No* noTemporario = f->inicio;
    *valor = noTemporario->dado;
    f->inicio = f->inicio->proximo;

    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(noTemporario);
    return 1;
}

// Libera a memória alocada por todos os nós da fila.
void destruirFila(FilaEncadeada* f) {
    Elemento temp_dado;
    while (!filaVazia(f)) {
        dequeue(f, &temp_dado);
        free(temp_dado);
    }
}