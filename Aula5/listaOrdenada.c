#include <stdio.h>
#include <stdlib.h>

void novaLista(int *lista, int max){ //vai deixar a lista vazia
    for (int i = 0; i < max; i++)
    {
        lista[i] = -1;
    }
}

int posicaoElemento(int lista[], int num, int max) //encontra a posicao adequada para o numero
{
    int i;

    for (i = 0; i < max; i++)
    {
        if (num <= lista[i]) {
            return i;
        }
    }
    return max;
}

void insercaoElemento(int *lista, int num, int posi){ //adiciona um numero a lista
    lista[posi] = num;
}
void moverLista(int *lista, int max, int posi){ //move a lista
    for (int i = max; i > posi; i--) {
        lista[i] = lista[i - 1];
    }
}

void removerElemento(int *lista, int *max, int num){ //remove um elemento da lista
    int posi = -1, i;

    for(int i=0;i<*max;i++){
        if(lista[i]==num){
            posi = i;
            break;
        }
    }

    if(posi != -1){
        for (i = posi; i < *max - 1; i++) { //move a lista para esquerda
            lista[i] = lista[i + 1];
        }
        (*max)--; //diminui a lista
        printf("\nElemento removido");
    }else{
        printf("\nElemento nao encontrado");
    }
}

void aumentaLista(int *max){ //aumenta o tamanho da lista
    (*max)++;
}

void imprimirLista(int *lista, int max){ //imprime a lista
    int i;

    for(i=0;i<max;i++){
        printf("%d\n", lista[i]);
    }
    printf("\n");
}

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int menu(){ //menu né
    int opc = -1;

    while(opc==-1){
        printf("///MENU///\n1:Iserir elemento\n2:Listar elementos \n3:Remover elemento \n0:Sair");
        printf("Digite sua acao \n");
        scanf("%d", &opc);

        if(opc!=1 && opc!=2 && opc!=3 && opc!=0){
            opc = -1;
            printf("\nDigite um valor valido");
        }
    }
    return opc;
}

int main()
{
    int lista[100];
    int max = 5;   //tamanho atual da lista
    int posi = -1; //recebe a posicao em que o numero sera colocado
    int opc = -1; //opcoes do menu
    int num = -1; //numero usado para inserir ou remover

    lista[0] = 3;
    lista[1] = 6;
    lista[2] = 11;
    lista[3] = 22;
    lista[4] = 45;

    while(opc!=0){ //roda o menu encanto puder
        opc = menu();

        switch(opc){
        case 1: //iseri um elemento
            limparTela();
            printf("\nDigite o valor a ser inserido\n");
            scanf("%d",&num);
            posi = posicaoElemento(lista,num,max);
            
            moverLista(lista,max,posi);
            insercaoElemento(lista,num,posi);
            aumentaLista(&max);
        break;

        case 2: //imprimi a lista
            limparTela();
            imprimirLista(lista,max);
        break;

        case 3:
            limparTela();
            printf("\nDigite o valor a ser removido\n");
            scanf("%d",&num);
            removerElemento(lista,&max,num);
        break;

        default:

        break;
        }

    }
    printf("\nFim do programa");

    return 0;
}