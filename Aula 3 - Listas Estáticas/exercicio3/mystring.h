#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* Estrutura para criação de um tipo de 
   dados para manipulação de cadeias de
   caracteres 
*/
   
typedef struct {
    char* palavra;
    int tam;
} string;

/* Cria uma nova string */
string* novaString(char*);

/* Devolve o tamanho de uma string passada como parâmetro */
int tamanho (string*);

/* Devolve 1 se o caractere passado como parâmetro está na
   presente na string s. Devolve 0 caso contrário         */
int busca (string*, char);

/* Concatena duas strings. Devolve uma string formada pela
   concatenção das strings passadas como parâmetro. As strings
   originais não devem ser alteradas                      */
string* concatena (string*, string*);

/* Imprime a string dada na tela */
void imprime (string*);

/* Muda valor da string armazenada a partir de uma cadeia de caracteres*/
void copiaValor (string*, char*);

