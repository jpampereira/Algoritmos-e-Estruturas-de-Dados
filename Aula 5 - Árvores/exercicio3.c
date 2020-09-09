/*
 * Exercício: Contando as folhas
 * 
 * Desenvolva um programa que recebe uma lista de palavras e constrói, a partir dela, uma árvore binária de busca. A inserção das palavras deve ser 
 * realizada na mesma ordem em que são apresentadas. Seu algoritmo deve calcular e exibir a quantidade de nós-folhas e de nós internos.
 * 
 * Por simplicidade, considere letras maiúsculas e minúsculas como iguais. Considere também que a árvore não armazena palavras repetidas.
 * 
 * Entrada: A entrada consiste em várias linhas. Em cada linha, há uma sequência de palavras separadas por espaços brancos. As palavras não possuem acentos. 
 * Para cada linha, deve ser construída uma árvore binária de busca.
 * 
 * Saída: Para cada linha da entrada, seu algoritmo deve exibir o número de nós-folha e de nós internos da árvore construída na linha correspondente. 
 * Os dois valores exibidos são separados por um espaço branco
 * 
 * Exemplo:
 * 
 * Entrada	                                Saída
 * 
 * O algoritmo faz a busca de palavras      3 4
 * Arvore binaria de busca                  1 3
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct No {
    char* palavra;
    int tamanho;
    struct No* esq;
    struct No* dir;
} No;

typedef struct Arvore {
    No* raiz;
} Arvore;

Arvore* cria_arvore() {
    Arvore* a = (Arvore*) malloc(sizeof(Arvore));
    if(a == NULL) {
        printf("Não foi possível alocar memória.\n");
        exit(1);
    }
    a->raiz = NULL;

    return a;
}

char* cria_string() {
    char* s = (char*) malloc(100*sizeof(char));
    if(s == NULL) {
        printf("Não foi possível alocar memória.\n");
        exit(1);
    }

    return s;
}

No* libera_no(No* no) {
    if(no == NULL) {
        return NULL;
    }

    no->esq = libera_no(no->esq);
    no->dir = libera_no(no->dir);

    free(no);
    no = NULL;

    return no;    
}

void libera_arvore(Arvore* a) {
    if(a == NULL) {
        return;
    }

    a->raiz = libera_no(a->raiz);
    free(a);
    a = NULL;
}

void libera_string(char* s) {
    free(s);
    s = NULL;
}

void insere_arvore(Arvore* a, char* palavra) {
    No *novo_no = (No *) malloc(sizeof(No));
    if(novo_no == NULL) {
        printf("Não foi possível alocar memória.\n");
        exit(1);
    }

    novo_no->esq = NULL;
    novo_no->dir = NULL;
    novo_no->tamanho = strlen(palavra) + 1;

    // Colocando todas as letras da palavra em maiúsculo
    int i;
    for(i = 0; i < strlen(palavra); i++) {
        palavra[i] = toupper(palavra[i]);
    }

    // Inserindo palavra no novo nó
    char* nova_palavra = (char*) malloc(novo_no->tamanho * sizeof(char));
    if(nova_palavra == NULL) {
        printf("Não foi possível alocar memória.\n");
        exit(1);
    }
    for(i = 0; i < novo_no->tamanho; i++) {
        nova_palavra[i] = palavra[i];
    }
    nova_palavra[i] = '\0';
    novo_no->palavra = nova_palavra;

    // Inserindo novo nó na árvore
    if(a->raiz == NULL) {
        a->raiz = novo_no;
    } else {
        No *ant = NULL, *atual = a->raiz;
        int comp;
        while(atual != NULL) {
            ant = atual;
            comp = strcmp(palavra, atual->palavra); // Compara a string que será adicionada com a string do nó atual
            if(comp == 0) {
                free(novo_no);
                return;
            } else if(comp < 0) {
                atual = atual->esq;
            } else {
                atual = atual->dir;
            }
        }

        if(comp < 0) {
            ant->esq = novo_no;
        } else {
            ant->dir = novo_no;
        }
    }

}

int contar_nos_internos(No* atual) {
    if(atual == NULL || (atual->esq == NULL && atual->dir == NULL)) {
        return 0;
    }

    int esq = contar_nos_internos(atual->esq);
    int dir = contar_nos_internos(atual->dir);

    return esq + dir + 1;
}

int contar_nos_folha(No* atual) {
    if(atual == NULL) {
        return 0;
    }

    if(atual->esq == NULL && atual->dir == NULL) {
        return 1;
    }

    int esq = contar_nos_folha(atual->esq);
    int dir = contar_nos_folha(atual->dir);

    return esq + dir;
}

int main() {
    Arvore* a;
    char frase[100];
    char* palavra;
    int j;

    while(scanf("%[^\n]s", frase) != EOF) {
        setbuf(stdin, NULL); // Liberar o buffer do teclado: https://www.youtube.com/watch?time_continue=234&v=ixk5RIqABjI&feature=emb_title

        a = cria_arvore();
        palavra = cria_string();

        j = 0;
        for(int i = 0; i <= strlen(frase); i++) {
            if(frase[i] == ' ' || frase[i] == '\0') {
                palavra[j] = '\0';
                insere_arvore(a, palavra);

                j = 0;
                libera_string(palavra);
                palavra = cria_string();
            } else {
                palavra[j] = frase[i];
                j++;
            }
        }

        printf("%d %d\n", contar_nos_folha(a->raiz), contar_nos_internos(a->raiz));

        libera_arvore(a);
        libera_string(palavra);
    }

    return 0;
}