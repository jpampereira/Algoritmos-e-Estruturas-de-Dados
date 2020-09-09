/*
 * Exercício: Palavra mais longa da frase
 * 
 * Escreva uma função que receba uma string (vetor de caracteres) contendo uma frase e retorne o tamanho (número de caracteres) da palavra de maior comprimento da frase. Considere que cada palavra da frase de entrada possui no máximo 100 caracteres e não contém pontuações.
 *
 * Exemplo de teste:
 * 
 * Entrada:
 * Boa tarde
 *
 * Saída:
 * 5
 */

#include <stdio.h>
#include <string.h>
#define N 100

int main() {

    char string[N] = {};
    int cont = 0, maior = 0;

    printf("Entrada:\n");
    fgets(string, N, stdin); 

    for(int i = 0; i < strlen(string); i++) {
        if(string[i] == ' ' || string[i] == '\n') {
            if(cont > maior) {
                maior = cont;
            }
            cont = 0;
        } else {
            cont++;
        }
    }

    printf("\nSaída:\n");
    printf("%d\n", maior);

    return 0;
}
