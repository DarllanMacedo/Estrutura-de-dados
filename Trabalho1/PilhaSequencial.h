// PilhaSequencial.h

#define TAMANHO_MAX 100

typedef int Elemento;

typedef struct {
    Elemento itens[TAMANHO_MAX];
    int topo;
} PilhaSequencial;

// Assinaturas das funções (protótipos)
void inicializarPilha(PilhaSequencial *p);
int pilhaVazia(PilhaSequencial *p);
int pilhaCheia(PilhaSequencial *p);
int push(PilhaSequencial *p, Elemento valor);
int pop(PilhaSequencial *p, Elemento *valor); // Adicionei essa linha