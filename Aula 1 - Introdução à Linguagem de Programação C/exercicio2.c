#include <stdio.h>
#define LIMITE 1000 

int main() {
    int num = 0;
    
    for(int i = 1; num <= LIMITE; i++) {
        num = i * (i+1) * (i+2);
        if(num <= LIMITE) printf("%d\n", num);
    }
    
    return 0;
}
