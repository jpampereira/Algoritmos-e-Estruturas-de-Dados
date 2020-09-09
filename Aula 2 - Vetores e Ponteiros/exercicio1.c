/* 
 * Exercício: Mínimo e máximo
 *
 * Escreva um programa que, dada uma sequência de números inteiros, calcula e devolve o menor e o maior valor dessa sequência.
 *
 * Entrada: Para uma sequência de n números, a entrada é formada por n + 1 valores. O primeiro número indica a quantidade de números que a sequência possui. 
 * Após esse número, a entrada é formada por n números, que compõem a sequência propriamente dita.
 * 
 * Saída: A saída consiste em apenas dois números: o menor valor presente na sequência e o maior valor presente na sequência dada como entrada.
 *
 * Exemplo de teste:
 * 
 * Entrada:
 * 5
 *
 * 3 6 8 2 1
 * 
 * Saída:
 * 1 8
 */

#include <stdio.h>

int main() {
    int n = 0, i = 0;

    // Quantidade de números da sequência
    printf("Entrada:\n");
    scanf("%d", &n);

    int valores[n];

    // Recebendo os números da sequência
    printf("\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &valores[i]);
    }

    // Encontrando o menor e o maior valor da sequência
    int maior = valores[0], menor = valores[0];
    for(i = 1; i < n; i++) {
        if(valores[i] > maior) {
            maior = valores[i];
        } else if(valores[i] < menor) {
            menor = valores[i];
        }
    }

    printf("\nSaída:\n");
    printf("%d %d\n", menor, maior);

    return 0;
}
