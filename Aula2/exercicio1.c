#include <stdio.h>

void Hanoi(int n, char inicio, char final, char auxiliar){
    if(n==1){
        printf("Mover disco 1 da torre %c para a torre %c\n", inicio, final);
        return;
    }
    Hanoi(n-1, inicio,  auxiliar, final);
    printf("Mover disco %d da torre %c para torre %c\n", n, inicio, final);

    Hanoi(n -1, auxiliar, final, inicio);
}

int main(){
    int n = 3;
    char inicio = 'A', auxiliar = 'B', final = 'C';

    Hanoi(n, inicio, final, auxiliar);

    return 0;
}