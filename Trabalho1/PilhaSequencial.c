// PilhaSequencial.c
#include "PilhaSequencial.h" // Verifique se está com a capitalização correta
// ... restante do código

// Inicializa a pilha, definindo o topo como -1
void inicializarPilha(PilhaSequencial *p) {
    p->topo = -1;
}

// Retorna 1 se a pilha estiver vazia, 0 caso contrário
int pilhaVazia(PilhaSequencial *p) {
    return p->topo == -1;
}

// Retorna 1 se a pilha estiver cheia, 0 caso contrário
int pilhaCheia(PilhaSequencial *p) {
    return p->topo == TAMANHO_MAX - 1;
}

// Insere um elemento no topo da pilha
// Retorna 1 em caso de sucesso, 0 se a pilha estiver cheia
int push(PilhaSequencial *p, Elemento valor) {
    if (pilhaCheia(p)) {
        return 0; // Erro: pilha cheia
    }
    p->topo++;
    p->itens[p->topo] = valor;
    return 1; // Sucesso
}

// Remove o elemento do topo da pilha
// Retorna 1 em caso de sucesso, 0 se a pilha estiver vazia
int pop(PilhaSequencial *p, Elemento *valor) {
    if (pilhaVazia(p)) {
        return 0; // Erro: pilha vazia
    }
    *valor = p->itens[p->topo];
    p->topo--;
    return 1; // Sucesso
}