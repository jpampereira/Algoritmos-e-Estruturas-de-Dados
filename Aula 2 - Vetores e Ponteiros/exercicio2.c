#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int ehPalindromo(char *palavra) {
    int tam = strlen(palavra)-1;
    for(int i = 0; i < tam/2; i++) {
        if(palavra[i] != palavra[tam-i]) {
            return 0;
        }
    }
    return 1;
}

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
        if(ehPalindromo(palavra)) {
            printf("PALINDROMO\n");
        } else {
            printf("NAO PALINDROMO\n");
        }
    }
    
    free(palavra);
    palavra = NULL;
    
    return 0;
}
