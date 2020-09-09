/*
 * Exercício: Mostrando números ímpares
 *
 * Escreva um programa que imprime os n primeiros números naturais ímpares.
 * Faça a leitura de um número natural n e a chamada da função criada na função main.
 *
 * Exemplo de teste:
 *
 * Entrada:
 * 4
 *
 * Saída:
 * 1 3 5 7
 */

#include <stdio.h>

void impares(int n) {
    int cont = 0, i = 1;

    while(cont < n) {
        if(i%2 != 0) {
            if(cont < n-1) {
                printf("%d ", i);
                cont++;   
            } else {
                printf("%d\n", i);
                cont++;   
            }
        }
        i++;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    impares(n);
    return 0;
}
