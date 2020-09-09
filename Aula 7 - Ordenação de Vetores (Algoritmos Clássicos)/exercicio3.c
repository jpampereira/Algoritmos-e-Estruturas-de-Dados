/*
 * Exercício: Selection Sort
 * 
 * Faça um programa que receba um vetor de inteiros de tamanho N e ordene os seus elementos usando o algoritmo de seleção (Selection Sort).
 * 
 * Entrada: O programa terá apenas um caso de teste. A primeira linha do caso de teste contem um inteiro N, 0 < N ≤ 10000, representando o tamanho do vetor. 
 * A segunda linha do caso de teste contem N números inteiros separados por um espaço em branco cada.
 * 
 * Saída: O programa gerá várias linhas de saída. A primeira linha, trata-se do vetor na sua ordem original, com os valores separados por espaço em branco. A cada troca que o algoritmo 
 * realizar, você deve imprimir todo o vetor, com seus valores separados por espaço em branco. A penúltima linha trata-se do vetor após passar pelo algoritmo de ordenação, ou seja, ordenado 
 * com seus valores separados por espaço em branco. A última linha trata-se de um inteiro representando o número de trocas (swap) entre elementos no vetor. Vale lembrar que antes do 
 * primeiro elemento do vetor não há nada impresso, assim como não há nada impresso depois do último elemento do vetor apenas uma quebra de linha. Após a impressão da última linha da saída,
 * salte uma linha. 
 * 
 * Exemplo:
 * Entrada	Saída
 * 10
 * 54 12 2 90 4 78 55 21 2 48
 * 
 * 54 12 2 90 4 78 55 21 2 48
 * 2 12 54 90 4 78 55 21 2 48
 * 2 2 54 90 4 78 55 21 12 48
 * 2 2 4 90 54 78 55 21 12 48
 * 2 2 4 12 54 78 55 21 90 48
 * 2 2 4 12 21 78 55 54 90 48
 * 2 2 4 12 21 48 55 54 90 78
 * 2 2 4 12 21 48 54 55 90 78
 * 2 2 4 12 21 48 54 55 90 78
 * 2 2 4 12 21 48 54 55 78 90
 * 2 2 4 12 21 48 54 55 78 90
 * 8
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

void selectionSort(int* v, int n) {
    int i, j, menor, aux, trocas = 0;

    imprime(v, n);
    for(int i = 0; i < n-1; i++) {
        // Encontra o menor valor no intervalo i - (n-1)
        menor = i;
        for(j = i+1; j < n; j++) {
            if(v[j] < v[menor]) {
                menor = j;
            }
        }

        // Efetua a troca de posição de valores, caso o menor valor não esteja na primeira posição dentro do intervalo i - (n-1)
        if(menor != i) {
            aux = v[i];
            v[i] = v[menor];
            v[menor] = aux;
            trocas++;
        }

        imprime(v, n);
    }
    imprime(v, n);

    printf("%d\n", trocas);
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

    selectionSort(v, n);
}