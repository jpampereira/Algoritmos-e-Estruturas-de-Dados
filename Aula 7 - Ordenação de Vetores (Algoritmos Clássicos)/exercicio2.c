/*
 * Exercício: Crescente ou Decrescente? Talvez nenhum deles!
 * 
 * Faça um programa que receba vários vetores de números inteiros e determina se eles estão ordenados ou não. A ordenação pode ser crescente (menores antes dos maiores) ou decrescente 
 * (maiores antes dos menores).
 * 
 * Entrada: O programa terá vários casos de teste. Cada caso de teste é composto por exatamente 2 linhas. A primeira linha do caso de teste contem um inteiro N, 0 ≤ N ≤ 10000, 
 * representando o tamanho do vetor. A segunda linha do caso de teste contém N números inteiros separados por um espaço em branco cada. A entrada termina com EOF.
 * 
 * Saída: O programa gera várias linhas de saída, uma para cada caso de teste informado na entrada. Caso o vetor esteja ordenado de forma crescente imprima uma letra C. Caso o vetor 
 * esteja ordenado de forma decrescente, imprima D. Caso o vetor não esteja ordenado, imprima a letra N. Após a impressão de cada letra, inclusive da última, salte uma linha.
 * 
 * Exemplo:
 * Entrada	                    Saída
 * 10                           
 * 0 1 2 3 4 5 6 7 8 9          C
 * 6                            
 * 9 5 0 2 4 1                  N
 * 8
 * 1 2 3 4 5 6 7 0              N
 * 10
 * 9 8 7 6 5 4 3 2 1 0          D
 * 7
 * 62 74 96 103 540 599 853     C
 */

#include <stdio.h>
#include <stdlib.h>

/* A variável c é um contador que registrará o número de vezes que precisamos permutar valores no vetor de N posições para ordená-lo de forma crescente.
 * Se c = 0 => Vetor estava ordenado de forma crescente
 * Se c = 1+2+3+...+(N-2)+(N-1) => Vetor estava ordenado de forma decrescente
 * Senão => Vetor não estava ordenado
*/

int bubbleSort(int* v, int n) {
    int i, aux, continua, fim = n, c = 0;

    do {
        continua = 0;
        for(i = 0; i < fim-1; i++) {
            if(v[i] > v[i+1]) {
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                continua = i;
                c++;
            }
        }
        fim--;
    } while(continua != 0);

    return c;
}

// Somatório de 1 até N = 1 + 2 + 3 + 4 + ... + (N-2) + (N-1) + N 
int somatorio(int n) {
    int soma = 0;
    for(int i = 1; i <= n; i++) soma += i;
    return soma;
}

void ordenacao(int* v, int n) {
    int c = bubbleSort(v, n);

    if(c == 0) {
        printf("C\n");
    } else if(c == somatorio(n-1)) {
        printf("D\n");
    } else {
        printf("N\n");
    }
}

int main() {
    int n, i;

    while(scanf("%d", &n) != EOF) {
        int* v = (int*) malloc(n*sizeof(int));
        if(v == NULL) {
            printf("Não foi possível alocar memória.\n");
            exit(1);
        }

        for(i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }

        ordenacao(v, n);

        free(v);
        v = NULL;
    }
    return 0;
}