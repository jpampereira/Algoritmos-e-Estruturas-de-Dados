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
