// FilaEncadeada.c
#include "FilaEncadeada.h"  // Corrigido para "FilaEncadeada.h"
#include <stdlib.h>
// ... restante do código

// Inicializa a fila, definindo os ponteiros de início e fim como NULL
void inicializarFila(FilaEncadeada* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

// Retorna 1 se a fila estiver vazia, 0 caso contrário
int filaVazia(FilaEncadeada* f) {
    return f->inicio == NULL;
}

// Insere um elemento no final da fila
void enqueue(FilaEncadeada* f, Elemento valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        // Lidar com falha na alocação de memória (opcional)
        return;
    }
    novoNo->dado = valor;
    novoNo->proximo = NULL;

    if (filaVazia(f)) {
        f->inicio = novoNo;
    } else {
        f->fim->proximo = novoNo;
    }
    f->fim = novoNo;
}

// Remove o elemento do início da fila
// Retorna 1 em caso de sucesso, 0 se a fila estiver vazia
int dequeue(FilaEncadeada* f, Elemento* valor) {
    if (filaVazia(f)) {
        return 0; // Erro: fila vazia
    }
    No* noTemporario = f->inicio;
    *valor = noTemporario->dado;
    f->inicio = f->inicio->proximo;

    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(noTemporario);
    return 1; // Sucesso
}