#include <stdio.h>
#include <stdlib.h>

struct realType{
    int left;
    int right;
};

double Numero(){
    double numero;

    printf("Digite o numero \n");
    scanf("%lf",numero);

    return numero;
}

void SepararNumero(double numero){
    int partLeft = (int)numero;
    double Decimal = numero - partLeft;
    
      
}