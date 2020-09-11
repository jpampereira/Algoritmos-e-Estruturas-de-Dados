#include <stdio.h>

void impares(int n) {
    int cont = 0;
    
    for(int i = 1; cont < n; i += 2) {   
        if(cont < n-1) printf("%d ", i);   
        else printf("%d\n", i);  
        
        cont++;    
    }
}

int main() {
    int n;
    scanf("%d", &n);
    impares(n);
    return 0;
}
