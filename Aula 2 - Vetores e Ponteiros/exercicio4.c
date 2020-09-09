/*
 * Exercício: Intercalação de caracteres 
 * 
 * Escreva um programa de intercalação de caracteres. 
 * O seu programa deverá ler duas palavras p1 e p2 e produzir uma terceira s, formada pela intercalação das duas palavras iniciais. 
 * A primeira letra de s é a primeira letra de p1, seguida pela primeira letra de p2, seguida pela segunda letra de p1, seguida pela segunda 
 * letra de p2 e assim por diante.
 *
 * Caso p1 termine, o restante de p2 é concatenado com s. O mesmo raciocínio vale para p2.
 *
 * Entrada: A entrada possui vários casos de teste. O primeira linha contém um número inteiro N que indica o número de testes. 
 * Cada teste é composto por duas palavras apresentadas na mesma linha e separadas por um espaço branco. Cada palavra possui  entre 1 e 50 caracteres, inclusive.
 *
 * Saída: A saída é formada por uma única palavra, que é a intercalação das duas palavras lidas na entrada.
 * 
 * Exemplo de teste:
 * 
 * Entrada      Saída
 * 2
 * Tpo oCder    TopCoder
 * aa bb        abab
 */

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
