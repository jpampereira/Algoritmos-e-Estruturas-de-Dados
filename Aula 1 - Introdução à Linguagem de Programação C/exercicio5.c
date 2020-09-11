#include <stdio.h>

int main() {
    int n = 0, i = 0, aux = 0;
    
    // Quantidade de numeros da sequencia
    scanf("%d", &n);

    int numeros[n];

    // Recebendo os numeros da sequencia
    for(i = 0; i < n; i++) {
        scanf("%d", &numeros[i]);
    }

    // Invertendo a posicao dos numeros
    for(i = 0; i < n/2; i++) {
        if(i != n-i-1) {
            aux = numeros[i];
            numeros[i] = numeros[n-i-1];
            numeros[n-i-1] = aux;
        }
    }

    // Imprimindo sequencia de numeros invertida
    for(i = 0; i < n; i++) {
        if(i < n-1) printf("%d ", numeros[i]);
        else printf("%d\n", numeros[i]);
    }

    return 0;
}
