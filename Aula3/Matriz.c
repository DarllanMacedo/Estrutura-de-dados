#include <stdio.h>

void SomaMatriz(int linha, int coluna,int matriz1[][coluna], int matriz2[][coluna], int matriz3[][coluna]){ 
    int i,j;

    for(i=0;i<linha;i++){
        for(j=0;j<coluna;j++){
            matriz3[i][j] = matriz1[i][j] + matriz2[i][j];
        }  
    }
}

void MultiplicacaoMatriz(int linha, int coluna, int matriz1[][coluna], int matriz2[][coluna], int matriz3[][coluna]){
    int base=0;
    int i,j,k;

    for(i=0;i<linha;i++){
        for(j=0;j<coluna;j++){
            matriz3[i][j] = 0;
            for(k=0;k<coluna;k++){
                base =  matriz1[i][k] * matriz2[k][j]; 
                matriz3[i][j] += base;
            }
        }
    }
}

void ImprimirMatriz(int linha, int coluna, int matriz3[][coluna]){
    int i,j;

    for(i=0;i<linha;i++){
        for(j=0;j<coluna;j++){
            printf("%d ", matriz3[i][j]);
        }
        printf("\n");
    }
}

void Menu(int linha,int coluna,int matriz1[][coluna], int matriz2[][coluna], int matriz3[][coluna]){
    int menu;
    while(menu!=0){
        printf("///MENU///\n 1:Somar matriz \n 2:Multiplicar Matriz \n 0:Sair \n Digite sua acao... \n");
        scanf("%d",&menu);

        switch(menu){
        case 1:
            SomaMatriz(linha,coluna,matriz1,matriz2,matriz3);
        break;
        case 2:
            MultiplicacaoMatriz(linha, coluna, matriz1, matriz2, matriz3);
        break;
        default:
            printf("Digite uma opcao valida\n");
        break;
        }
        
        ImprimirMatriz(linha,coluna,matriz3);
    }
}

int main(){
    int linha = 3, coluna = 3;
    int matriz1[3][3] = {  
                           {3,4,5},
                           {1,1,1},
                           {5,5,5} 
                         };

    int matriz2[3][3] = { 
                           {2,2,2},
                           {0,0,0},
                           {6,6,6} 
                         };

    int matriz3[3][3] = { 
                           {0,0,0},
                           {0,0,0},
                           {0,0,0} 
                         };

    Menu(linha,coluna,matriz1,matriz2,matriz3);

    return 0;
}