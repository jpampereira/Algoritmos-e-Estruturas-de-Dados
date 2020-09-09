/*
 * Exercício: Operações com strings
 * 
 * Neste exercício, vamos trabalhar com o gerenciamento de cadeias de caracteres em C. Para facilitar nosso trabalho com o uso de strings, vamos construir 
 * uma estrutura apropriada para manipulação e controle de cadeias de caracteres. Vamos chamar essa estrutura de "string".
 * 
 * Sua tarefa será implementar funções que utilizem a estrutura string, conforme definição a seguir:
 * 
 * typedef struct {
 *    char* palavra;
 *    int tam;
 * }  string;
 * 
 * Você terá um arquivo chamado "mystring.c". Siga as orientações:
 * 
 * 1) Você não pode mudar a assinatura das funções (nomes, parâmetros e tipos de retorno);
 * 2) Considere que a definição da estrutura string está definida no arquivo "mystring.h", também fornecido neste exercício;
 * 3) Faça o download do arquivo "mystring.c" e implemente as funções (ou faça a edição online aqui no Moodle).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystring.h"

/* Cria uma nova string */
string * novaString(char *s) {
    string *p = (string *) malloc(sizeof(string));
    if(p == NULL) {
        printf("Não foi possível alocar memória.\n");
        exit(1);
    }

    p->palavra = s;
    p->tam = strlen(s);

    return p;
}

/* Devolve o tamanho de uma string passada como parâmetro */
int tamanho (string *s) {
    return s->tam;
}

/* Devolve 1 se o caractere passado como parâmetro está na
 * presente na string s. Devolve 0 caso contrário         
 */
int busca (string *s, char c) {
    int i;
    for(i = 0; i < s->tam && s->palavra[i] != c; i++);

    if(i < s->tam) {
        return 1;
    }
    return 0;
}

/* Concatena duas strings. Devolve uma string formada pela
 * concatenção das strings passadas como parâmetro. As strings
 * originais não devem ser alteradas                      
 */
string * concatena (string *l, string *r) {
    char *nova_palavra = (char *) malloc(50 *sizeof(char));

    strcat(nova_palavra, l->palavra);
    strcat(nova_palavra, r->palavra);

    return novaString(nova_palavra);
}

/* Imprime a string dada na tela */
void imprime (string *s){
    printf("%s\n", s->palavra);
}

/* Muda valor da string armazenada a partir de uma cadeia de caracteres*/
void copiaValor (string *original, char *s) {
    original->palavra = s;
    original->tam = strlen(s);
}

/* Função main criada apenas para verificar se as funções estavam 
 * funcionando corretamente.
 */

/*
int main() {
    printf("Teste...\n");

    string *s1, *s2, *s3;

    s1 = novaString("Joao");
    s2 = novaString("Pedro");

    printf("\nStrings:\n");
    printf("s1 = ");
    imprime(s1);
    printf("s2 = ");
    imprime(s2);

    printf("\nTamanho das Strings:\n");
    printf("s1 = %d\ns2 = %d\n", tamanho(s1), tamanho(s2));

    printf("\nA letra \"P\" está presente em s1? %d\n", busca(s1, 'P'));
    printf("E em s2? %d\n", busca(s2, 'P'));

    printf("\nConcatenando s1 e s2 formando s3:\n");
    s3 = concatena(s1, s2);
    printf("s3: ");
    imprime(s3);
    printf("Tamanho de s3: %d\n", tamanho(s3));

    printf("\nTrocando o valor de s3:\n");
    printf("s3 antes: %s\n", s3->palavra);
    copiaValor(s3, "Henrique");
    printf("s3 depois: %s\n", s3->palavra);

    return 0;
}
*/