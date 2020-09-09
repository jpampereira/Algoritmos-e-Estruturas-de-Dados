/*
 * Exercício: Os menores correm mais rápido!
 * 
 * Como se sabe, o bubble sort clássico faz trocas de modo que os elementos maiores sempre chegam mais rápido à sua posição definitiva. 
 * Neste exercício, você deve construir uma variação do bubble sort que desloca, primeiro, os elementos menores (ao invés dos maiores). 
 * Para cada rastreamento completo do vetor, você deve imprimir sua configuração. Você deve interromper o algoritmo assim que o vetor ficar ordenado
 * (ou seja, não deve haver impressões repetidas do vetor já ordenado). 
 * 
 * Entrada: A entrada consiste em 2 linhas. A primeira linha possui um número inteiro N (0 < N < 1024), tal que N é a quantidade de elementos do vetor. 
 * A segunda linha possui uma sequência de N números inteiros, que representam os números que devem ser armazenados no vetor. O armazenamento deve seguir 
 * a ordem em que os elementos são apresentados. 
 * 
 * Saída: A saída possui M linhas (0 < M < (N+1)). Cada linha deve mostrar a sequência de elementos no vetor após uma varredura de trocas do algoritmo 
 * bubble sort. A primeira linha possui a configuração inicial do vetor. A última linha possui a configuração do vetor já ordenado. Não deve haver linhas 
 * iguais.
 * 
 * Exemplo:
 * 
 * Entrada
 * 10
 * 4 -3 15 10 12 8 7 9 5 1 
 * 
 * Saída: 
 * 4 -3 15 10 12 8 7 9 5 1
 * -3 4 1 15 10 12 8 7 9 5
 * -3 1 4 5 15 10 12 8 7 9
 * -3 1 4 5 7 15 10 12 8 9
 * -3 1 4 5 7 8 15 10 12 9
 * -3 1 4 5 7 8 9 15 10 12
 * -3 1 4 5 7 8 9 10 15 12
 * -3 1 4 5 7 8 9 10 12 15
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

void bubbleSort(int* v, int n) {
    int i, aux, continua, inicio = 0;
    do {
        imprime(v, n);

        continua = 0;
        for(i = n-1; i > inicio; i--) {
            if(v[i] < v[i-1]) {
                aux = v[i];
                v[i] = v[i-1];
                v[i-1] = aux;
                continua = i;
            }
        }
        inicio++;
    } while(continua != 0);
}

int main() {
    int n;
    scanf("%d", &n);

    int* v = (int*) malloc(n*sizeof(int));
    if(v == NULL) {
        printf("Não foi possível alocar memória.\n");
        exit(1);
    }

    int i;

    for(i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    bubbleSort(v, n);

    return 0;
}