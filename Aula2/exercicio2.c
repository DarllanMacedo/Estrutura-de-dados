#include <stdio.h>

int Fibonacci(int n, int i, int a, int b){
    if(i==n){
        return a;
    }

    int base = b;
    b = a + b;
    a = base;

    return Fibonacci(n, i + 1, a, b);
}

int main(){
    int n = 12, i = 0, a = 0, b = 1;

    printf("%d", Fibonacci(n, i, a, b));
}