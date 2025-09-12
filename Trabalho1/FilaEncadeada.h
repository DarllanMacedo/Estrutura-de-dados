// fila_encadeada.h

// Define o tipo de dado que a fila irá armazenar
typedef int Elemento;

// Estrutura do nó da fila
typedef struct No {
    Elemento dado;
    struct No* proximo;
} No;

// Estrutura da fila
typedef struct {
    No* inicio;
    No* fim;
} FilaEncadeada;

// Assinaturas das funções (protótipos)
void inicializarFila(FilaEncadeada* f);
int filaVazia(FilaEncadeada* f);
void enqueue(FilaEncadeada* f, Elemento valor);
int dequeue(FilaEncadeada* f, Elemento* valor);