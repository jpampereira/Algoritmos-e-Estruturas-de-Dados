#include <stdio.h>

int main() {
    int n = 0, soma = 0;

    // Tamanho da Matriz
    scanf("%d", &n);

    int matriz[n][n];

    // Recebendo os valores da matriz
    printf("\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Somando os valores abaixo da diagonal principal
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(j < i) {
                soma += matriz[i][j];
            }
        }
    }

    printf("%d\n", soma);
    return 0;
}
