/*
 * Exercício: Inverte sequência de números
 *
 * Escreva um programa que recebe uma lista de números inteiros  e inverte os elementos dessa lista.
 *
 * A entrada de dados conterá um número natural positivo n, que representa a quantidade de números da sequência. 
 * Após esse número, serão fornecidos os n números (inteiros quaisquer) propriamente ditos.
 *
 * Exemplo de teste:
 * 
 * Entrada:
 * 3
 * 
 * 1
 * 2
 * 3
 * 
 * Saída:
 * 3 2 1
 */

#include <stdio.h>

int main() {
    int n = 0, i = 0, aux = 0;
    
    // Quantidade de números da sequência
    printf("Entrada:\n");
    scanf("%d", &n);

    int numeros[n];

    // Recebendo os números da sequência
    printf("\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &numeros[i]);
    }

    // Invertendo a posição dos números
    for(i = 0; i < n/2; i++) {
        if(i != n-i-1) {
            aux = numeros[i];
            numeros[i] = numeros[n-i-1];
            numeros[n-i-1] = aux;
        }
    }

    // Imprimindo sequência de números invertida
    printf("\nSaída:\n");
    for(i = 0; i < n; i++) {
        if(i < n-1) {
            printf("%d ", numeros[i]);
        } else {
            printf("%d\n", numeros[i]);
        }
    }

    return 0;
}
