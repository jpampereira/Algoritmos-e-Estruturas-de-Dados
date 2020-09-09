/*
 * Exercício: Insertion Sort
 * 
 * Faça um programa que receba um vetor de inteiros de tamanho N e ordene os seus elementos usando o algoritmo de inserção (Insertion Sort).
 * 
 * Entrada: O programa terá apenas um caso de teste. A primeira linha do caso de teste contem um inteiro N, 0 < N ≤ 10000, representando o tamanho do vetor. A segunda linha do caso de 
 * teste contem N números inteiros separados por um espaço em branco cada. É garantido que não há repetição dos valores do vetor. 
 * 
 * Saída: O programa gerará várias linhas de saída. A primeira linha, trata-se do vetor na sua ordem original, com os valores separados por espaço em branco. A cada troca que o algoritmo
 * realizar, você deve imprimir todo o vetor, com seus valores separados por espaço em branco. A penúltima linha trata-se do vetor após passar pelo algoritmo de ordenação, ou seja, 
 * ordenado com seus valores separados por espaço em branco. A última linha trata-se de palavra “Trocas:X” seguida da quantidade de trocas que o algoritmo realizou. 
 * Observe que a letra T está em maiúsculo e após os dois pontos não há um espaço em branco antes do número inteiro X.
 *  
 * Após a impressão da última linha da saída, salte uma linha.
 * 
 * Exemplo:
 * Entrada
 * 10
 * 54 12 2 90 4 78 55 21 1 48
 * 
 * Saída
 * 54 12 2 90 4 78 55 21 1 48
 * 12 54 2 90 4 78 55 21 1 48
 * 12 2 54 90 4 78 55 21 1 48
 * 2 12 54 90 4 78 55 21 1 48
 * 2 12 54 4 90 78 55 21 1 48
 * 2 12 4 54 90 78 55 21 1 48
 * 2 4 12 54 90 78 55 21 1 48
 * 2 4 12 54 78 90 55 21 1 48
 * 2 4 12 54 78 55 90 21 1 48
 * 2 4 12 54 55 78 90 21 1 48
 * 2 4 12 54 55 78 21 90 1 48
 * 2 4 12 54 55 21 78 90 1 48
 * 2 4 12 54 21 55 78 90 1 48
 * 2 4 12 21 54 55 78 90 1 48
 * 2 4 12 21 54 55 78 1 90 48
 * 2 4 12 21 54 55 1 78 90 48
 * 2 4 12 21 54 1 55 78 90 48
 * 2 4 12 21 1 54 55 78 90 48
 * 2 4 12 1 21 54 55 78 90 48
 * 2 4 1 12 21 54 55 78 90 48
 * 2 1 4 12 21 54 55 78 90 48
 * 1 2 4 12 21 54 55 78 90 48
 * 1 2 4 12 21 54 55 78 48 90
 * 1 2 4 12 21 54 55 48 78 90
 * 1 2 4 12 21 54 48 55 78 90
 * 1 2 4 12 21 48 54 55 78 90
 * 1 2 4 12 21 48 54 55 78 90
 * Trocas:25
 */

#include <stdio.h>
#include <stdlib.h>

void imprime(int* v, int n) {
    for(int i = 0; i < n; i++) {
        if(i < n-1) {
            printf("%d ", v[i]);
        } else {
            printf("%d\n", v[i]);
        }
    }
}

void insertionSort(int* v, int n) {
    int i, j, aux1, aux2, trocas = 0;

    imprime(v, n);
    for(i = 1; i < n; i++) {
        aux1 = v[i];
        for(j = i; (j > 0) && (aux1 < v[j-1]); j--) {
            aux2 = v[j];
            v[j] = v[j-1];
            v[j-1] = aux2;
            trocas++;

            imprime(v, n);
        }
    }
    imprime(v, n);

    printf("Trocas:%d\n", trocas);
}

int main() {
    int n;
    scanf("%d", &n);

    int* v = (int*) malloc(n*sizeof(int));
    if(v == NULL) {
        printf("Não foi possível alocar memória.\n");
        exit(1);
    }

    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    insertionSort(v, n);

    return 0;
}