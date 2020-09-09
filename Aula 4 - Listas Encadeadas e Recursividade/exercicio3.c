/*
 * Exercício: Chaves, colchetes e parênteses
 * 
 * Escreva um programa que lê uma expressão (com no máximo 100 caracteres) matemática e verifica se todos os parênteses, colchetes e chaves estão 
 * corretamente abertos e fechados. O programa imprime "SIM" se os parênteses, colchetes e chaves estão corretamente organizados, ou "NAO" caso contrário.
 * 
 * Utilize uma estrutura de Pilha. Ela pode ajuda-lo(a) bastante!
 * 
 * Entrada: A entrada é formada por uma sequência de linhas, sendo que cada linha exibe exatamente uma expressão. A expressão matemática deverá ser avaliada 
 * em função da sequência de chaves, colchetes e parênteses.
 * 
 * Saída: Para cada linha de entrada, a saída deverá possuir as palavras, ou "SIM", ou "NAO". A saída será "SIM", caso a expressão esteja correta, ou "NAO", 
 * caso contrário.
 * 
 * Exemplo:
 * 
 * Entrada	                Saída
 * (10+60-[40+x]-{80})      SIM
 * [10+60-(40+x]-{80})      NAO
 * a + 4 * (3 + b) + 4      SIM
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Elemento {
    char caractere;
    struct Elemento *prox;
} Elemento;

typedef struct Pilha {
    Elemento *topo;
} Pilha;

Pilha * cria_pilha() {
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    if(p == NULL) {
        printf("Não foi possível alocar memória.\n");
        exit(1);
    }
    p->topo = NULL;

    return p;
}

void empilha(Pilha *p, char c) {
    Elemento *novo = (Elemento *) malloc(sizeof(Elemento));
    if(novo == NULL) {
        printf("Não foi possível alocar memória.\n");
        exit(1);
    }
    novo->caractere = c;
    novo->prox = p->topo;
    p->topo = novo;
}

char desempilha(Pilha *p) {
    if(p->topo == NULL) {
        return NULL;
    }
    
    char c = p->topo->caractere;

    Elemento *aux = p->topo;
    p->topo = aux->prox;
    free(aux);

    return c; 
}

int main() {
    char *expressao = (char *) malloc(MAX * sizeof(char));
    if(expressao == NULL) {
        printf("Não foi possível alocar memória.\n");
        exit(1);
    }

    Pilha *p = cria_pilha();
    char c;
    int abertos;

    while(scanf("%s", expressao) != EOF) {

        abertos = 0;

        for(int i = 0; i < strlen(expressao); i++) {
            if(expressao[i] == '(' || expressao[i] == '{' || expressao[i] == '[') {
                empilha(p, expressao[i]);
                abertos++;
            } else if(expressao[i] == ')' || expressao[i] == '}' || expressao[i] == ']') {
                c = desempilha(p);
                if(expressao[i] == ')' && c == '(' || expressao[i] == '}' && c == '{' || expressao[i] == ']' && c == '[') {
                    abertos--;
                } else {
                    break;
                }
            }
        }

        if(abertos == 0) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }

    }

    return 0;
}