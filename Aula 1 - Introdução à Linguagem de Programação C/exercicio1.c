#include <stdio.h>

void impares(int n) {
    int cont = 0, i = 1;

    while(cont < n) {
        if(i%2 != 0) {
            if(cont < n-1) {
                printf("%d ", i);
                cont++;   
            } else {
                printf("%d\n", i);
                cont++;   
            }
        }
        i++;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    impares(n);
    return 0;
}
