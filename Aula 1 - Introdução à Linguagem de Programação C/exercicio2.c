/*
 * Exercício: Número Triangular
 *
 * Escreva um programa que exibe todos os números triangulares entre 1 e 1000.
 *
 * Um número n é triangular se é igual ao produto de 3 números inteiros consecutivos. Por exemplo, 120 é triangular pois 4x5x6 = 120.
 *
 * O programa não possui entrada de dados, somente a exibição dos números triangulares entre 1 e 1000.
 */

#include <stdio.h>
#define LIMITE 1000 

int main() {
    int i = 1, n = 0;

    do {
        n = i * (i+1) * (i+2);
        if(n <= LIMITE) {
            printf("%d\n", n);
        }
        i++;
    } while(n <= LIMITE);

    return 0;
}
