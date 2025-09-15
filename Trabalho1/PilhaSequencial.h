#ifndef PILHA_SEQUENCIAL_H
#define PILHA_SEQUENCIAL_H

// Define o tamanho máximo da pilha sequencial.
#define TAMANHO_MAX 100

// Define o tipo de dado dos elementos da pilha.
typedef int Elemento;

// Estrutura da pilha, que usa um array e um índice para o topo.
typedef struct {
    Elemento itens[TAMANHO_MAX]; 
    int topo;                    
} PilhaSequencial;

// Protótipos das funções que manipulam a pilha.
void inicializarPilha(PilhaSequencial *p);
int pilhaVazia(PilhaSequencial *p);
int pilhaCheia(PilhaSequencial *p);
int push(PilhaSequencial *p, Elemento valor);
int pop(PilhaSequencial *p, Elemento *valor);

#endif