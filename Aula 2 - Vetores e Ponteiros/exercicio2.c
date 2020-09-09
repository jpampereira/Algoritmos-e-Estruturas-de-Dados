/*
 * Exercício: Palíndromo
 *
 * Uma palavra é dita "palíndromo" quando apresenta a mesma sequência de letras se lida da esquerda para a direita, ou da direita para a esquerda.
 *
 * Escreva um programa que recebe uma lista de palavras e identifica palíndromos. Para fins de avaliação, seu programa deverá ignorar as diferenças 
 * entre letras maiúsculas e minúsculas. Cada palavra possui, no máximo, 40 caracteres.
 *
 * Entrada: A entrada de dados é formada por uma sequência de palavras, sendo uma em cada linha.
 *
 * Saída: Para cada palavra da entrada, a saída exibe a mensagem "PALINDROMO" caso a palavra seja um palíndromo, ou "NAO PALINDROMO" caso contrário.
 * 
 * Exemplo de teste:
 * 
 * Ana
 * PALINDROMO
 * 
 * cana
 * NAO PALINDROMO
 *
 * radar
 * PALINDROMO
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Verifica se a palavra passada como parâmetro é palíndromo
int palindromo(char *palavra) {
    int tam = strlen(palavra)-1;
    for(int i = 0; i < tam/2; i++) {
        if(palavra[i] != palavra[tam-i]) {
            return 0;
        }
    }
    return 1;
}

// Joga todas as letras da palavra para maiúsculo
void uppercase(char *palavra) {
    for(int i = 0; i < strlen(palavra); i++) {
        palavra[i] = toupper(palavra[i]);
    }
}

int main() {
    char *palavra = malloc(40 * sizeof(char));

    while(scanf("%s", palavra) != EOF) {
        uppercase(palavra);

        // Não existe tipo boolean em C, portanto True = 1 e False != 1
        if(palindromo(palavra)) {
            printf("PALINDROMO\n");
        } else {
            printf("NAO PALINDROMO\n");
        }
    }
    
    free(palavra);
    palavra = NULL;
    
    return 0;
}
