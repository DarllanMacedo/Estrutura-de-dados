#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilhaSequencial.h"
#include "FilaEncadeada.h"

// Avalia uma expressão em Notação Polonesa Reversa (NPR) usando uma fila e uma pilha.
void avaliarNPRComFila(FilaEncadeada* fila) {
    PilhaSequencial pilha;
    inicializarPilha(&pilha);
    
    char* token;

    // Processa cada token da fila.
    while (dequeue(fila, &token)) {
        // Verifica se o token é um operando (número).
        if (strspn(token, "0123456789") == strlen(token)) {
            int numero = atoi(token);
            push(&pilha, numero);
        } else {
            // Se for um operador, remove dois operandos da pilha, realiza a operação e insere o resultado.
            int op2, op1, resultado;
            if (!pop(&pilha, &op2) || !pop(&pilha, &op1)) {
                printf("Erro: Expressao mal formada (faltam operandos).\n");
                free(token);
                return;
            }

            switch (token[0]) {
                case '+': resultado = op1 + op2; break;
                case '-': resultado = op1 - op2; break;
                case '*': resultado = op1 * op2; break;
                case '/':
                    if (op2 == 0) {
                        printf("Erro: Divisao por zero.\n");
                        free(token);
                        return;
                    }
                    resultado = op1 / op2;
                    break;
            }
            push(&pilha, resultado);
        }
        free(token);
    }

    // Após o processamento, o resultado deve ser o único elemento restante na pilha.
    int resultadoFinal;
    if (pop(&pilha, &resultadoFinal) && pilhaVazia(&pilha)) {
        printf("Resultado: %d\n", resultadoFinal);
    } else {
        printf("Erro: Expressao mal formada.\n");
    }
}

int main() {
    int opcao;
    char expressaoInput[100];

    do {
        printf("\n--- Avaliador de Notacao Polonesa Reversa ---\n");
        printf("1. Digitar uma expressao\n");
        printf("2. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        while (getchar() != '\n'); 

        if (opcao == 1) {
            printf("Digite a expressao NPR (ex: 3 4 + 5 *): ");
            fgets(expressaoInput, sizeof(expressaoInput), stdin);
            expressaoInput[strcspn(expressaoInput, "\n")] = 0;

            FilaEncadeada filaDeTokens;
            inicializarFila(&filaDeTokens);

            // Quebra a string de entrada em tokens e os enfileira.
            char* token = strtok(expressaoInput, " ");
            while (token != NULL) {
                enqueue(&filaDeTokens, token);
                token = strtok(NULL, " ");
            }

            avaliarNPRComFila(&filaDeTokens);
            destruirFila(&filaDeTokens);
        } else if (opcao != 2) {
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 2);

    printf("Saindo do programa...\n");
    return 0;
}