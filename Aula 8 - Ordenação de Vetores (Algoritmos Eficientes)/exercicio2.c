/*
 * Exercício: Ordenação Parcia
 * 
 * Modifique o algoritmo de ordenação por seleção (Selection Sort) para obter uma sequência ordenada parcial contendo apenas os k menores elementos da sequência 
 * ordenados na sua forma crescente. 
 * 
 * Entrada: O programa terá apenas um caso de teste. A primeira linha do caso de teste é um número inteiro N, 1 ≤ N ≤ 10000. Na linha seguinte serão dados N inteiros
 * separados por um espaço em branco cada. A terceira linha um número k (1 ≤ k ≤ N ).
 * 
 * Saída: O programa gera como saída duas linhas. A primeira linha trata-se do vetor original antes de invocar o procedimento para ordenação parcial.
 * A segunda linha trata-se da impressão do vetor após o termino do procedimento de ordenação. Salte uma linha ao final.
 * 
 * Exemplo:
 * Entrada	                    Saída
 * 
 * 10
 * 9 65 12 7 21 5 7 46 52 10
 * 3	                        
 *                              9 65 12 7 21 5 7 46 52 10
 *                              5 7 7 65 21 9 12 46 52 10
 * 
 * 10
 * 9 65 12 7 21 5 7 46 52 10
 * 5	
 *                              9 65 12 7 21 5 7 46 52 10
 *                              5 7 7 9 10 65 12 46 52 21
 * 
 * 10
 * 9 65 12 7 21 5 7 46 52 10
 * 9	
 *                              9 65 12 7 21 5 7 46 52 10
 *                              5 7 7 9 10 12 21 46 52 65
 */
#include <stdio.h>
#include <stdlib.h>

void preenche_vetor(int* v, int tam) {
    int i;
    for(i = 0; i < tam; i++) {
        scanf("%d", &v[i]);
    }
}

void imprime_vetor(int* v, int tam) {
    int i;
    for(i = 0; i < tam; i++) {
        if(i < tam-1) {
            printf("%d ", v[i]);
        } else {
            printf("%d\n", v[i]);
        }
    }
}

void selectionSort_parcial(int* v, int tam, int n) {
    int i, j, menor, aux;

    for(i = 0; i < tam-1 && i < n; i++) {

        menor = i;
        for(j = i+1; j < tam; j++) {
            if(v[j] < v[menor]) {
                menor = j;
            }
        }

        if(menor != i) {
            aux = v[i];
            v[i] = v[menor];
            v[menor] = aux;
        }

    }
}

int main() {

    int tam;
    scanf("%d", &tam);

    int* v = (int*) malloc(tam*sizeof(int));
    if(v == NULL) {
        printf("Não foi possível alocar memória.\n");
        exit(1);
    }

    preenche_vetor(v, tam);

    imprime_vetor(v, tam);

    int n;
    scanf("%d", &n);

    selectionSort_parcial(v, tam, n);

    imprime_vetor(v, tam);

    return 0;
}
