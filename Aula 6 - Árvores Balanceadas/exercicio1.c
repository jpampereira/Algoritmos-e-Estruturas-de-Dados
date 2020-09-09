/*
 * Exercício: Cuidado para não desequilibrar!
 * 
 * Uma árvore binária de busca apresenta melhores resultados se houver equilíbrio de altura entre suas sub-árvores esquerda e direita de seus nós. 
 * Para buscar identificar nós em estado de desequilíbrio, você deve construir um programa capaz de identificar os nós em desequilíbrio.
 * 
 * Para caracterizar o desequilíbrio de altura, vamos usar o conceito de fator de balanceamento (FB), normalmente aplicado em árvores AVL. 
 * Considere o fator de balanceamento de um nó n como a diferença entre as alturas das sub-árvores direita (h(ndir)) e esquerda (h(nesq)) de n.
 * 
 * FB(n) = h(ndir) - h(nesq)
 * 
 * Um nó n é considerado desequilibrado se FB(n) > 1 ou FB(n) < -1.
 * 
 * Considere que a inserção dos nós é realizada usando o algoritmo padrão de inserção de nós em ABBs, como disponível nos exercícios do tópico de Árvores.
 * 
 * Entrada: Sequência de números que devem ser inseridos na árvore na ordem em que são apresentados.
 * 
 * Saída: A saída é formada por várias linhas, que exibem a lista de nós com fator de balanceamento em desequilíbrio. 
 * Cada linha da saída deve apresentar o valor armazenado pelo nó e seu fator de balanceamento, separados por um espaço branco. 
 * A lista de valores deve ser dada em ordem crescente do valor armazenado em cada nó.
 * 
 * A lista deverá ser calculada somente após a inserção de todos os elementos.
 * 
 * Exemplo:
 * 
 * Entrada	Saída
 * 1 2 3 4  1 3
 *          2 2
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

// VERSÃO RECURSIVA
No* insere_arvore(No* no, int valor) {
    if (no == NULL) {
       No* novo_no = malloc(sizeof(No));
       if(novo_no == NULL) {
           printf("Não foi possível alocar memória.\n");
           exit(1);
       } 

       novo_no->valor = valor;
       novo_no->esq = NULL;
       novo_no->dir = NULL;

       return novo_no;
    }

    if (valor <= no->valor) {
        no->esq = insere_arvore(no->esq, valor);
    } else {
        no->dir = insere_arvore(no->dir, valor);
    }

    return no;
}

// VERSÃO NÃO RECURSIVA
/*
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
            if(valor <= atual->valor) {
                atual = atual->esq;
            } else {
                atual = atual->dir;
            }
        }

        if(valor <= ant->valor) {
            ant->esq = novo_no;
        } else {
            ant->dir = novo_no;
        }
    }
*/

int altura_arvore(No *no) {
    if(no == NULL) {
        return -1;
    }

    int alt_esq = altura_arvore(no->esq);
    int alt_dir = altura_arvore(no->dir);

    if(alt_esq > alt_dir) {
        return alt_esq + 1;
    } else {
        return alt_dir + 1;
    }
}

void calcula_fb(No *no) {
    if(no == NULL) {
        return;
    }

    calcula_fb(no->esq);

    int fb = altura_arvore(no->dir) - altura_arvore(no->esq);
    if(fb < -1 || fb > 1) {
        printf("%d %d\n", no->valor, fb);
    }

    calcula_fb(no->dir);
}

int main() {

    Arvore *a = cria_arvore();

    int valor;

    while(scanf("%d", &valor) != EOF) {
        a->raiz = insere_arvore(a->raiz, valor); //Versão Recursiva
        //insere_arvore(a, valor); // Versão Não-Recursiva
    }

    calcula_fb(a->raiz);

    return 0;
}