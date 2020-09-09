/*
 * Exercício: Ordenação de Vetores
 *
 * Escreva um programa que lê um vetor de números inteiros. Seu programa deverá combinar os números de modo que eles fiquem ordenados crescentemente.
 *
 * Entrada: O primeiro valor da entrada é um número n, que representa a quantidade de números inteiros presente no vetor. 
 * Na linha seguinte são exibidos n números inteiros, que representam os valores do vetor propriamente dito. Esses números são apresentados na mesma linha e separados por espaço branco.
 *
 * Saída: A saída é formada pelos n números do vetor de entrada, exibidos em ordem crescente na mesma linha e separados por espaço branco.
 * 
 * Exemplo de teste:
 * 
 * Entrada:
 * 5
 *
 * 3 1 8 6 9
 * 
 * Saída:
 * 1 3 6 8 9
 */

#include <stdio.h>
#include <stdlib.h>

// Essa função serve para ordenar o vetor utilizando o algoritmo Bubble Sort
void ordenar(int *v, int n) {
    int aux = 0;

    for(int i = 0; i < n-1; i++) {
        for(int j = i; j < n; j++) {
            if(v[j] > v[j+1]) {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

int main() {
    int n = 0, i = 0;
    
    // Número de elementos do vetor
    printf("Entrada:\n");
    scanf("%d", &n);

    // Criação do vetor de n elementos
    int *v = malloc(n * sizeof(int));

    // Recebendo os valores do vetor
    printf("\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    ordenar(v, n-1);

    printf("\nSaída:\n");
    for(i = 0; i < n; i++) {
        if(i < n-1) {
            printf("%d ", *(v+i));
        } else {
            printf("%d\n", *(v+i));
        }
    }

    return 0;
}
