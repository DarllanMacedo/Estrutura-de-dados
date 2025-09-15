#ifndef FILA_ENCADEADA_H
#define FILA_ENCADEADA_H

#include <stdlib.h>

// Define o tipo de dado dos elementos da fila.
typedef char* Elemento;

// Estrutura do nó da fila.
typedef struct No {
    Elemento dado;
    struct No* proximo;
} No;

// Estrutura da fila, com ponteiros para o início e o fim.
typedef struct {
    No* inicio;
    No* fim;
} FilaEncadeada;

// Protótipos das funções de manipulação da fila.
void inicializarFila(FilaEncadeada* f);
int filaVazia(FilaEncadeada* f);
void enqueue(FilaEncadeada* f, Elemento valor);
int dequeue(FilaEncadeada* f, Elemento* valor);
void destruirFila(FilaEncadeada* f);

#endif