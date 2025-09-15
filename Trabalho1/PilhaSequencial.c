#include "PilhaSequencial.h"

// Inicializa a pilha, definindo o topo como -1 para indicar que está vazia.
void inicializarPilha(PilhaSequencial *p) {
    p->topo = -1;
}

// Retorna 1 se a pilha estiver vazia, 0 caso contrário.
int pilhaVazia(PilhaSequencial *p) {
    return p->topo == -1;
}

// Retorna 1 se a pilha estiver cheia, 0 caso contrário.
int pilhaCheia(PilhaSequencial *p) {
    return p->topo == TAMANHO_MAX - 1;
}

// Adiciona um elemento no topo da pilha.
int push(PilhaSequencial *p, Elemento valor) {
    if (pilhaCheia(p)) {
        return 0;
    }
    p->topo++;
    p->itens[p->topo] = valor;
    return 1;
}

// Remove o elemento do topo da pilha.
int pop(PilhaSequencial *p, Elemento *valor) {
    if (pilhaVazia(p)) {
        return 0;
    }
    *valor = p->itens[p->topo];
    p->topo--;
    return 1;
}