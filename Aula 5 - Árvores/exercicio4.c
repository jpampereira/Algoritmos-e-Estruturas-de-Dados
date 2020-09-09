/*
 * Exercício: Operações com árvores binárias de busca
 * 
 * Escreva um programa que realiza as operações básicas de uma árvore binária de busca (ABB) que armazena números inteiros. 
 * Seu programa deverá reconhecer sequências de comandos e processá-los usando uma ABB. Veja a descrição dos comandos a seguir:
 * 
 * I n: Insere o número inteiro n em uma ABB.
 * P: imprime os elementos em pré-ordem (separados por um espaço branco)
 * N: imprime os elementos em inordem (separados por um espaço branco)
 * S: imprime os elementos em pós-ordem (separados por um espaço branco)
 * B n: Busca o valor n na ABB. Se n estiver na árvore, imprime "SIM"; caso contrário "NAO".
 * R n: Remove o elemento n da ABB. Se n não estiver na árvore, o comando deve ser ignorado.
 * H: Exibe a altura da ABB.
 * 
 * As operações podem aparecer em qualquer ordem. Para a remoção, deve-se considerar que o elemento antecessor (maior elemento da sub-árvore esquerda 
 * do nó removido) do nó removido deve ocupar o seu lugar, se possível.
 * 
 * Considere que todos os elementos da árvore são diferentes. Sendo assim, inserções do mesmo elemento devem ser ignoradas.
 * 
 * A entrada consiste em N linhas e cada linha contém uma operação. A ABB pode armazenar qualquer número inteiro x (-1024 < x < 1024).
 * 
 * Saída: Cada linha da entrada que realiza alguma operação válida na ABB deve ter uma linha correspondente na saída, conforme suas orientações, 
 * exceto as operações I (inserção) e R (remoção).
 * 
 * Exemplo:
 * 
 * Entrada	Saída
 * I 12
 * R 20
 * I 4
 * I 8
 * I 1
 * I 4
 * I 15
 * N        1 4 8 12 15
 * P        12 4 1 8 15
 * S        1 8 4 15 12
 * H        2
 * B 12     SIM
 * B 21     NAO
 * R 4
 * N        1 8 12 15
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
    if(no == NULL) {
        No *novo_no = (No *) malloc(sizeof(No));
        if(novo_no == NULL) {
            printf("Não foi possível alocar memória.\n");
            exit(1);
        }
        novo_no->valor = valor;
        novo_no->esq = NULL;
        novo_no->dir = NULL;

        return novo_no;
    }

    if(valor < no->valor) {
        no->esq = insere_arvore(no->esq, valor);
    } else if(valor > no->valor) {
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
            if(atual->valor == valor) {
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
*/

void imprime_preordem(No *no) {
    if(no != NULL) {
        printf("%d ", no->valor);
        imprime_preordem(no->esq);
        imprime_preordem(no->dir);
    }
}

void imprime_emordem(No *no) {
    if(no != NULL) {
        imprime_emordem(no->esq);
        printf("%d ", no->valor);
        imprime_emordem(no->dir);
    }
}

void imprime_posordem(No *no) {
    if(no != NULL) {
        imprime_posordem(no->esq);
        imprime_posordem(no->dir);
        printf("%d ", no->valor);
    }
}

No* remove_no(No *no) {
    No *ant, *atual;

    /* Nó a ser removido não possui sub-árvore esquerda (esse caso 
     * trata os casos de ter apenas o filho a direita e também o caso 
     * onde o nó a ser removido é folha).
     */
    if(no->esq == NULL) {
        atual = no->dir;
        free(no);
        return atual;
    }

    /* Procura o nó mais a direita. */
    ant = no;
    atual = no->esq;
    while(atual->dir != NULL) {
        ant = atual;
        atual = atual->dir;
    }

    /* Caso o nó raiz da sub-árvore esquerda do nó que 
     * será removido possua uma sub-árvore direita.
     */
    if(ant != no) {
        ant->dir = atual->esq;
        atual->esq = no->esq;
    }
    atual->dir = no->dir;
    free(no);

    return atual;
}

// VERSÃO RECURSIVA
No* remove_arvore(No* no, int valor) {
    if(no == NULL) { // Não encontrou
        return NULL;
    }

    if(no->valor == valor) { // Encontrou
        return remove_no(no);
    }

    if(valor < no->valor) { 
        no->esq = remove_arvore(no->esq, valor);
    } else {
        no->dir = remove_arvore(no->dir, valor);
    }

    return no;
}

// VERSÃO NÃO-RECURSIVA
/*
void remove_arvore(Arvore *a, int valor) {
    No *ant = NULL, *atual = a->raiz;

    while(atual != NULL) {
        if(atual->valor == valor) {
            if(atual == a->raiz) {
                a->raiz = remove_no(atual);
            } else if(atual == ant->esq) {
                ant->esq = remove_no(atual);
            } else {
                ant->dir = remove_no(atual);
            }
            return;
        }
        ant = atual;
        if(valor < atual->valor) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }
}
*/

void busca_arvore(Arvore *a, int valor) {
    No *aux = a->raiz;
    while(aux != NULL) {
        if(valor == aux->valor) {
            printf("SIM\n");
            return;
        }
        
        if(valor < aux->valor) {
            aux = aux->esq;
        } else {
            aux = aux->dir;
        }
    }
    printf("NAO\n");
}

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

int main() {
    Arvore *a = cria_arvore();

    char opcao;
    int valor;

    while(scanf("%c", &opcao) != EOF) {
        switch(opcao) {
            case 'I':
                scanf("%d", &valor);
                a->raiz = insere_arvore(a->raiz, valor);
                break;
            case 'P':
                imprime_preordem(a->raiz);
                printf("\n");
                break;
            case 'N':
                imprime_emordem(a->raiz);
                printf("\n");
                break;
            case 'S':
                imprime_posordem(a->raiz);
                printf("\n");
                break;
            case 'B':
                scanf("%d", &valor);
                busca_arvore(a, valor);
                break;
            case 'R':
                scanf("%d", &valor);
                a->raiz = remove_arvore(a->raiz, valor);
                break;
            case 'H':
                printf("%d\n", altura_arvore(a->raiz));
                break;
        }
    }

    return 0;
}