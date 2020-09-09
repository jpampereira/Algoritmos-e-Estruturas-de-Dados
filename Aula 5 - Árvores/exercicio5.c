/*
 * Exercício: Busca pelos pais
 * 
 * Dada uma sequência de números inteiros, você deve desenvolver um programa que constrói uma árvore binária de busca a partir desses números, 
 * obedecendo a ordem em que eles são apresentados.
 * 
 * Após a construção da árvore, serão exibidos vários valores. Para os valores que estão na árvore, seu programa deve exibir o valor do nó pai, caso possível.
 * 
 * Entrada: A entrada consiste em várias linhas. Na primeira linha, você terá um número n, que indica a quantidade de números que deverão ser inseridos na 
 * árvore binária de busca. Na segunda linha, você terá os n números que devem ser inseridos na árvore. A partir da terceira linha, você terá um número por 
 * linha, indicando o valor do nó para o qual se deve procurar o nó-pai na árvore construída.
 * 
 * Por simplicidade, assuma que não serão inseridos números repetidos na árvore e os números são inteiros positivos.
 * 
 * Saída: Para cada linha da entrada, a partir da terceira, seu programa deverá apresentar o valor do nó-pai correspondente. 
 * Se o valor da entrada não estiver na árvore, a saída deverá ser -2. Se o valor da entrada estiver na árvore, mas não tiver 
 * nó-pai (caso da raiz da árvore), a saída deverá ser -1.
 * 
 * Exemplo:
 * 
 * Entrada	                Saída
 * 
 * 7
 * 21 17 18 32 12 25 26
 * 18                       17
 * 17                       21
 * 25                       32
 * 26                       25
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

typedef struct Arvore {
    No *raiz;
} Arvore;

Arvore * cria_arvore() {
    Arvore *a = (Arvore *) malloc(sizeof(Arvore));
    if(a == NULL) {
        printf("Não foi possível alocar memória.\n");
        exit(1);
    }
    a->raiz = NULL;

    return a;
}

void insere_arvore(Arvore *a, int valor) {
    No *novo_no = (No *) malloc(sizeof(No));
    if(novo_no == NULL) {
        printf("Não foi possível alocar memória.\n");
        exit(1);
    }
    novo_no->valor = valor;
    novo_no->esq = NULL;
    novo_no->dir = NULL;

    if(a->raiz == NULL) {
        a->raiz = novo_no;
    } else {
        No *ant = NULL, *atual = a->raiz;
        while(atual != NULL) {
            if(valor == atual->valor) {
                free(novo_no);
                return;
            }
            ant = atual;

            if(valor < atual->valor) {
                atual = atual->esq;
            } else {
                atual = atual->dir;
            }
        }

        if(valor < ant->valor) {
            ant->esq = novo_no;
        } else {
            ant->dir = novo_no;
        }
    }

}

int procurapai_arvore(Arvore *a, int valor) {
    if(a->raiz->valor == valor) { // Raiz é o valor que procuramos
        return -1;
    } else {
        No *ant = NULL, *atual = a->raiz;

        while(atual != NULL) {
            if(valor == atual->valor) { // Encontramos o valor
                return ant->valor;
            }
            ant = atual;
            if(valor < atual->valor) {
                atual = atual->esq;
            } else {
                atual = atual->dir;
            }
        }
    }
    return -2; // Não encontramos o valor
}

int main() {
    Arvore *a = cria_arvore();

    int n, valor;
    
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &valor);
        insere_arvore(a, valor);
    }

    while(scanf("%d", &valor) != EOF) {
        printf("%d\n", procurapai_arvore(a, valor));
    }

    return 0;
}