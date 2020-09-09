/*
 * Exercício: Calculando Alturas
 * 
 * Considerando o algoritmo padrão para inserção de elementos em uma árvore binária de busca (apresentado no vídeo desta semana). Escreva um programa que lê um conjunto de números 
 * inteiros e constrói a árvore binária de busca correspondente. Seu programa deve calcular a altura da árvore.
 * 
 * Considere que o conjunto de números dados como entrada sempre possui, pelo menos, 1 elemento.  Considere, ainda, que um nó-folha possui altura 0.
 * 
 * Entrada: A entrada é composta por uma única linha contendo uma sequência de números. Seu programa deve ler os números e construir uma árvore binária de busca correspondente. 
 * A inserção dos valores deve ocorrer na ordem em que eles são apresentados.
 * 
 * Saída: Seu programa deve calcular e exibir a altura da árvore binária construída a partir dos dados da entrada.
 * 
 * Exemplo:
 * 
 * Entrada	Saída
 * 
 * 29       3 
 * 25 
 * 13 
 * 14 
 * 27 
 * 56 
 * 98
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

Arvore * cria_Arvore() {
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

int altura_arvore(No *raiz) {
    if(raiz == NULL) {
        return -1;
    }

    int alt_esq = altura_arvore(raiz->esq);
    int alt_dir = altura_arvore(raiz->dir);

    if(alt_esq > alt_dir) {
        return alt_esq + 1;
    } else {
        return alt_dir + 1;
    }
}

int main() {

    Arvore *a = cria_Arvore();

    int valor;
    while(scanf("%d", &valor) != EOF) {
        insere_arvore(a, valor);
    }
    
    int altura = altura_arvore(a->raiz);

    if(altura >= 0) {
        printf("%d\n", altura);
    }

    imprime_preordem(a->raiz);
    printf("\n");
    imprime_emordem(a->raiz);
    printf("\n");
    imprime_posordem(a->raiz);
    printf("\n");

    return 0;
}