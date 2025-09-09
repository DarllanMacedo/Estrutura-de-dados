#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

No* criar_no(int valor) {
    No *novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return NULL;
    }
    novo_no->valor = valor;
    novo_no->prox = NULL;
    return novo_no;
}

void imprimir_lista(No *lista) {
    No *aux = lista;
    printf("Lista atual: ");
    if (aux == NULL) {
        printf("(vazia)");
    }
    while (aux != NULL) {
        printf("%d -> ", aux->valor);
        aux = aux->prox;
    }
    printf("NULL\n");
}

void liberar_lista(No **lista) {
    if (*lista == NULL) {
        return;
    }
    No *atual = *lista;
    No *proximo_no;
    while (atual != NULL) {
        proximo_no = atual->prox;
        free(atual);
        atual = proximo_no;
    }
    *lista = NULL;
}

No* buscar_ordenado(No *lista, int valor_buscado) {
    No *aux = lista;
    while (aux != NULL && aux->valor <= valor_buscado) {
        if (aux->valor == valor_buscado) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

void inserir_ordenado(No **lista, int valor) {
    No *novo_no = criar_no(valor);
    if (novo_no == NULL) {
        return;
    }
    No *anterior = NULL;
    No *atual = *lista;
    while (atual != NULL && atual->valor < valor) {
        anterior = atual;
        atual = atual->prox;
    }
    novo_no->prox = atual;
    if (anterior == NULL) {
        *lista = novo_no;
    } else {
        anterior->prox = novo_no;
    }
}

int remover_ordenado(No **lista, int valor) {
    No *anterior = NULL;
    No *atual = *lista;
    while (atual != NULL && atual->valor != valor) {
        if (atual->valor > valor) {
            break; 
        }
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL || atual->valor != valor) {
        return 0;
    }
    if (anterior == NULL) {
        *lista = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }
    free(atual);
    return 1;
}

int main() {
    No *lista = NULL;

    inserir_ordenado(&lista, 10);
    inserir_ordenado(&lista, 5);
    inserir_ordenado(&lista, 20);
    inserir_ordenado(&lista, 15);
    
    printf("Valores inseridos.\n");
    imprimir_lista(lista);
    printf("\n");

    int valor_para_buscar = 15;
    if (buscar_ordenado(lista, valor_para_buscar) != NULL) {
        printf("O valor %d foi encontrado na lista.\n", valor_para_buscar);
    } else {
        printf("O valor %d nao foi encontrado na lista.\n", valor_para_buscar);
    }
    
    valor_para_buscar = 99;
    if (buscar_ordenado(lista, valor_para_buscar) != NULL) {
        printf("O valor %d foi encontrado na lista.\n", valor_para_buscar);
    } else {
        printf("O valor %d nao foi encontrado na lista.\n", valor_para_buscar);
    }
    printf("\n");

    printf("Removendo o valor 5.\n");
    remover_ordenado(&lista, 5);
    imprimir_lista(lista);

    printf("Removendo o valor 20.\n");
    remover_ordenado(&lista, 20);
    imprimir_lista(lista);
    printf("\n");

    printf("Liberando toda a memoria alocada.\n");
    liberar_lista(&lista);
    imprimir_lista(lista);

    return 0;
}