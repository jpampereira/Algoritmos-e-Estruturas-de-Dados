/*
 * Exercício: Altura mínima
 * 
 * 
 * Faça um algoritmo calcula a menor altura possível de uma árvore binária de busca.
 * 
 * Entrada: A entrada consiste em várias linhas. Em cada linha, há um número inteiro não-negativo, que representa a quantidade de elementos que a 
 * árvore binária de busca deverá armazenar.
 * 
 * Saída: Para cada linha da entrada, seu algoritmo deve descobrir a menor altura possível de uma árvore binária de busca capaz de armazenar todos 
 * os elementos indicados na entrada correspondente.
 * 
 * Exemplo:
 * 
 * Entrada	Saída
 * 7        2
 * 8        3
 * 255      7
 * 1500     10
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    /* Árvores Binárias Completas são árvores estritamente binárias (os nós possuem 0 ou 2 filhos) e seus nós folhas estão todos no mesmo nível. 
     * É a configuração onde os nós estão mais bem distribuídos pela árvore, portanto, é a configuração onde dado um determinado número de elementos,
     * a árvore formada terá a menor altura possível. Sabemos que podemos calcular o número de nós em uma árvore binária completa através de 2^h - 1, 
     * onde h é a altura da árvore. 
     */
    int n_elementos, cont, altura;
    while(scanf("%d", &n_elementos) != EOF) {
        altura = 0;
        while((pow(2, altura)-1) < n_elementos) {
            altura++;
        }
        printf("%d\n", altura-1);
    }

    return 0;
}