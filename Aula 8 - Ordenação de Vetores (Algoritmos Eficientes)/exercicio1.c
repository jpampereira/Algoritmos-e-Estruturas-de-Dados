/* 
 * Exercício: Quicksort
 * 
 * Implemente o algoritmo de ordenação Quick Sort (versão que seleciona o último elemento do vetor como pivô) e imprima o número total de comparações necessárias para 
 * ordenar um vetor de números inteiros. 
 * 
 * Obs: Não use variáveis globais!
 * 
 * Entrada: O programa terá apenas um caso de teste. A primeira linha do caso de teste é um número inteiro N, 1 ≤ N ≤ 10000. Na linha seguinte serão dados N inteiros
 * separados por um espaço em branco cada.
 * 
 * Saída: O programa gera como saída três linhas. A primeira linha trata-se do vetor original antes de invocar o procedimento para ordenação. A segunda linha trata-se
 * da impressão do vetor após o termino do procedimento de ordenação. Quebre uma linha ao final. A terceira linha trata-se do número de comparações necessárias para
 * ordenar o vetor. Apenas conte o número de comparações em que pelo menos um elemento do vetor seja utilizado na comparação.
 * 
 * Exemplo:
 * Entrada	                    Saída
 * 
 * 10
 * 9 65 12 7 21 5 7 46 52 10	
 *                              9 65 12 7 21 5 7 46 52 10
 *                              5 7 7 9 10 12 21 46 52 65
 *                              Comparacoes: 20
 * 
 * 1
 * 20
 *                              20
 *                              20
 *                              Comparacoes: 0
 * 
 * 10
 * 0 1 2 3 4 5 6 7 8 9	
 *                              0 1 2 3 4 5 6 7 8 9
 *                              0 1 2 3 4 5 6 7 8 9
 *                              Comparacoes: 45
 */
#include <stdio.h>
#include <stdlib.h>

int* cria_vetor(int n) {

    int* v = (int*) malloc(n*sizeof(int));
    if(v == NULL) {
        printf("Não foi possível alocar memória.\n");
        exit(1);
    }

    return v;

}

void insere_vetor(int* v, int n) {

    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

}

void imprime_vetor(int* v, int n) {

    for(int i = 0; i < n; i++) {
        if(i < n-1) {
            printf("%d ", v[i]);
        } else {
            printf("%d\n", v[i]);
        }
    }

}

int particiona(int* v, int inicio, int fim) {

    int esq, dir, pivo, aux;

    esq = inicio;
    dir = fim-1;
    pivo = v[inicio];
    
    while(esq < dir) {
        while(v[esq] <= pivo) esq++;
        while(v[dir] > pivo) dir--;

        if(esq < dir) {
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        }
    }

    v[inicio] = v[dir];
    v[dir] = pivo;

    return dir;

}

void quickSort(int* v, int inicio, int fim) {

    if(inicio < fim) {
        int pivo = particiona(v, inicio, fim);
        quickSort(v, inicio, pivo-1);
        quickSort(v, pivo+1, fim);
    }

}

int main() {

    int n;
    scanf("%d", &n);

    int* v = cria_vetor(n);

    insere_vetor(v, n);

    imprime_vetor(v, n);

    quickSort(v, 0, n);

    imprime_vetor(v, n);

    return 0;

}