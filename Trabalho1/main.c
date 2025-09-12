#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilhaSequencial.h"  // Corrigido para "PilhaSequencial.h"
#include "FilaEncadeada.h"   // Corrigido para "FilaEncadeada.h"

// Função auxiliar para processar e avaliar a expressão NPR
// Esta função irá usar a pilha para o cálculo
void avaliarNPR(char* expressao) {
    PilhaSequencial pilha;
    inicializarPilha(&pilha);
    
    char* token = strtok(expressao, " "); // Divide a string por espaços

    while (token != NULL) {
        // Verifica se o token é um número ou um operador
        if (strchr("+-*/", token[0]) == NULL) {
            // É um número (operando)
            int numero = atoi(token); // Converte string para int
            push(&pilha, numero);
        } else {
            // É um operador
            int op2, op1, resultado;
            pop(&pilha, &op2);
            pop(&pilha, &op1);

            switch (token[0]) {
                case '+':
                    resultado = op1 + op2;
                    break;
                case '-':
                    resultado = op1 - op2;
                    break;
                case '*':
                    resultado = op1 * op2;
                    break;
                case '/':
                    resultado = op1 / op2;
                    break;
            }
            push(&pilha, resultado);
        }
        token = strtok(NULL, " ");
    }

    int resultadoFinal;
    if (pop(&pilha, &resultadoFinal)) {
        printf("Resultado: %d\n", resultadoFinal);
    } else {
        printf("Erro na expressao.\n");
    }
}

int main() {
    int opcao;
    char expressao[100];

    do {
        printf("\n--- Avaliador de Notacao Polonesa Reversa ---\n");
        printf("1. Digitar uma expressao\n");
        printf("2. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a expressao NPR (ex: 3 4 + 5 *): ");
                // Limpa o buffer de entrada para evitar problemas com fgets
                while (getchar() != '\n');
                fgets(expressao, sizeof(expressao), stdin);
                expressao[strcspn(expressao, "\n")] = 0; // Remove o '\n'

                avaliarNPR(expressao);
                break;
            case 2:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 2);

    return 0;
}