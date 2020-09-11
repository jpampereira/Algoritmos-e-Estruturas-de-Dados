#include <stdio.h>
#include <stdlib.h>

// Essa função serve para ordenar o vetor utilizando o algoritmo Bubble Sort
void ordenar(int *v, int n) {
    int aux = 0;

    for(int i = 0; i < n-1; i++) {
        for(int j = i; j < n; j++) {
            if(v[j] > v[j+1]) {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

int main() {
    int n = 0, i = 0;
    
    scanf("%d", &n);
    int *v = malloc(n * sizeof(int));

    printf("\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    ordenar(v, n-1);

    for(i = 0; i < n; i++) {
        if(i < n-1) {
            printf("%d ", *(v+i));
        } else {
            printf("%d\n", *(v+i));
        }
    }

    return 0;
}
