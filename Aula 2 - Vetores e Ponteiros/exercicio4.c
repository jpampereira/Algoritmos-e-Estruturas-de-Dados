#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50

char * intercala_caracteres(char *p1, char *p2) {
    char *s = (char *) malloc(2*TAM*sizeof(char));
    if(s == NULL) {
        printf("Não foi possível alocar memória.\n");
        exit(1);
    }

    int cont_p1 = 0, cont_p2 = 0, turno = 0;
    for(int i = 0; i < (2*TAM*sizeof(char)); i++) {

        if(turno == 0) {
            if(cont_p1 < strlen(p1)) { // P1 possui caracteres para inserir em S
                s[i] = p1[cont_p1++];
            } else if(cont_p2 < strlen(p2)) { // P2 ainda possui caracteres para inserir em S
                i--;
            } else { // P1 e P2 não possuem mais caracteres para inserir em S
                break;
            }
            turno = 1;
        } else {
            if(cont_p2 < strlen(p2)) { // P2 possui caracteres para inserir em S
                s[i] = p2[cont_p2++];
            } else if(cont_p1 < strlen(p1)) { // P1 ainda possui caracteres para inserir em S
                i--;
            } else { // P1 e P2 não possuem mais caracteres para inserir em S
                break;
            }
            turno = 0;
        }

    }

    return s;
}

int main() {
    char *p1 = (char *) malloc(TAM * sizeof(char));
    char *p2 = (char *) malloc(TAM * sizeof(char));
    if(p1 == NULL || p2 == NULL) {
        printf("Não foi possível alocar memória.\n");
        exit(1);
    }

    char *s;

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%s", p1);
        scanf("%s", p2);

        s = intercala_caracteres(p1, p2);

        printf("%s\n", s);
    } 

    return 0;
}
