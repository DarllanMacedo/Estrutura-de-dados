#include <stdio.h>

void zerarPilha(int *pilha, int tam) {
    int i;
    for(i = 0; i < tam; i++) {
        pilha[i] = -1;
    }
}

void inserirElemento(int *pilha, int *topo, int num, int tam) {
    if (*topo == tam - 1) {
        printf("\nA pilha esta cheia!");
        return;
    }
    (*topo)++;
    pilha[*topo] = num;
    printf("\nNumero inserido com sucesso!");
}

void removerElemento(int *pilha, int *topo) {
    if (*topo == -1) {
        printf("\nA pilha esta vazia.");
        return;
    }
    pilha[*topo] = -1;
    (*topo)--;
    printf("\nElemento removido.");
}

void imprimirPilha(int *pilha, int topo) {
    if (topo == -1) {
        printf("\nA pilha esta vazia.");
        return;
    }
    printf("\nElementos da pilha (do topo para a base):");
    int i;
    for(i = topo; i >= 0; i--) {
        printf("\n%d", pilha[i]);
    }
}

int menu() {
    int menu = -1;
    while(menu < 0 || menu > 3) {
        printf("\n///MENU/// \n1:Inserir numero \n2:Imprimir pilha \n3:Remover elemento \n0:Sair\n");
        scanf("%d", &menu);
    }
    return menu;
}

int main() {
    int tam = 10, num = 0, opc = -1, topo = -1;
    int pilha[tam];

    zerarPilha(pilha, tam);

    while(opc != 0) {
        opc = menu();

        switch(opc) {
            case 1:
                printf("\nQual numero sera inserido? ");
                scanf("%d", &num);
                inserirElemento(pilha, &topo, num, tam);
                break;
            case 2:
                imprimirPilha(pilha, topo);
                break;
            case 3:
                removerElemento(pilha, &topo);
                break;
        }
    }

    printf("\nFim do programa");
    return 0;
}