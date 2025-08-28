#include <stdio.h>

void zerarFila(int *fila, int tam){ //"limpa" a fila
    int i;

    for(i=0;i<tam;i++){
        fila[i] = -1;
    }
}

void entrarFila(int *fila, int tam, int num, int final){ //adiciona um numero a fila
    int i;

    if(final!=-1){
        printf("A fila esta cheia");
    }
    for(i=0;i<tam;i++){
        if(fila[i]==-1){
            fila[i] = num;
            break;
        }
    }
}

void removeFila(int *fila, int tam){
    int i;

    if(fila[0]==-1){
        printf("\nA fila esta vazia");
        return;
    }

    fila[0] = -1;

    for(i=0;i<tam - 1;i++){
        if(fila[i+1] == -1){
            break;
        }
        fila[i] = fila[i+1];
    }
    fila[i] = -1;
    printf("\nElemento removido");
}

void imprimirFila(int *fila, int tam){
    int i;

    for(i=0;i<tam;i++){
        if(fila[0]==-1){
            printf("a fila esta vaiza");
            break;
        }
        if(fila[i]==-1){
            break;
        }
        printf("\n%d",fila[i]);
    }
}

int menu(){ //menu basico
    int menu = -1;

    while(menu!= 1 && menu!= 2 && menu!=3 &&menu!= 0){
        printf("\n///MENU/// \n1:Inserir numero \n2:Imprimir fila \n3:Remover elemento \n0:Sair\n");
        scanf("%d",&menu);
    }
    
    return menu;
}

int main(){
    int fila[10], num = 0, opc = -1, final = -1;
    int tam = 10; //determina o tamanho maximo da fila

    zerarFila(fila,tam);

    while(opc!=0){
        
        opc = menu();

        switch(opc){
            case 1:
                printf("\nQual numero sera inserido\n");
                scanf("%d",&num);

                entrarFila(fila,tam,num,final);
                final = fila[tam -1];
            break;
            case 2:
                imprimirFila(fila,tam);
            break;
            case 3:
                removeFila(fila,tam);
            break;
        }
    }

    printf("\nFim do programa");
    return 0;
}