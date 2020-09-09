/*
 * Exercício: Soma Abaixo da Diagonal
 *
 * Escreva uma função que recebe uma matriz quadrada de inteiros de dimensão n. 
 * Seu programa deve calcular e devolver a soma dos elementos abaixo da diagonal principal (excluindo a diagonal principal).
 * 
 * Exemplo de teste:
 *
 * Entrada:
 * 3
 *
 * 0 1 0
 * 2 4 7
 * 1 3 5
 * 
 * Saída:
 * 6
 */

#include <stdio.h>

int main() {
    int n = 0, soma = 0;

    // Tamanho da Matriz
    printf("Entrada:\n");
    scanf("%d", &n);

    int matriz[n][n];

    // Recebendo os valores da matriz
    printf("\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Somando os valores abaixo da diagonal principal
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(j < i) {
                soma += matriz[i][j];
            }
        }
    }

    printf("\nSaída:\n");
    printf("%d\n", soma);
    return 0;
}
