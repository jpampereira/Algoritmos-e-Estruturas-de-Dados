/*
 * Exercício: Subindo a árvore com equilíbrio
 * 
 * Escreva um programa que realiza as operações básicas de uma árvore AVL que armazena números inteiros. Seu programa deverá reconhecer sequências 
 * de comandos e processá-los usando uma árvore AVL. Veja a descrição dos comandos a seguir:
 * 
 * I n: Insere o número inteiro n em uma árvore AVL.
 * P: imprime os elementos em pré-ordem (separados por um espaço branco)
 * N: imprime os elementos em inordem (separados por um espaço branco)
 * S: imprime os elementos em pós-ordem (separados por um espaço branco)
 * H: Exibe a altura da árvore AVL.
 * B: Busca um elemento na árvore AVL.
 * 
 * As operações podem aparecer em qualquer ordem. Considere que todos os elementos da árvore são diferentes. Sendo assim, inserções do mesmo elemento 
 * devem ser ignoradas.
 * 
 * Entrada: A entrada consiste em N linhas e cada linha contém uma operação. A árvore AVL pode armazenar qualquer número inteiro x (-1024 < x < 1024). 
 * 
 * Saída: Cada linha da entrada que realiza alguma operação válida na árvore AVL deve ter uma linha correspondente na saída, conforme suas orientações, 
 * exceto as operações I (inserção). Sempre que uma operação de inserção obrigar uma rotação, deve-se exibir uma linha contendo a rotação usada 
 * (L, R, LR, RL). Para as rotações, as possibilidades são:
 * 
 * Rotacao L: Rotação Simples à esquerda.
 * Rotacao R: Rotação Simples à direita.
 * Rotacao LR: Rotação Dupla Esquerda-Direita.
 * Rotacao RL: Rotação Dupla Direita-Esquerda.
 * 
 * Exemplo:
 * 
 * Entrada	Saída
 * I 12
 * I 4
 * H        1
 * I 8      Rotacao LR
 * H        1
 * I 1     
 * I 4 
 * I -3     Rotacao R
 * N        -3 1 4 8 12
 * P        8 1 -3 4 12
 * S        -3 4 1 12 8
 * H        2
 * B 12     SIM
 * B 21     NAO
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
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

int altura_arvore(No* no) {
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

int fator_balanceamento(No* no) {
    return abs(altura_arvore(no->dir) - altura_arvore(no->esq)); // Função abs(): Número absoluto (sem sinal)
}

No* rotacaoL(No* no) {
    No* aux = no->dir;
    no->dir = aux->esq;
    aux->esq = no;
    no = aux;

    return  no;
}

No* rotacaoR(No* no) {
    No* aux = no->esq;
    no->esq = aux->dir;
    aux->dir = no;
    no = aux;

    return no;
}

No* rotacaoLR(No* no) {
    no->esq = rotacaoL(no->esq);
    no = rotacaoR(no);
}

No* rotacaoRL(No* no) {
    no->dir = rotacaoR(no->dir);
    no = rotacaoL(no);
}

No* insere_arvoreAVL(No* no, int valor) {
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

    if(valor < no->valor) {
        no->esq = insere_arvoreAVL(no->esq, valor);
        
        if(fator_balanceamento(no) >= 2) {
            if(valor < no->esq->valor) {
                printf("Rotacao R\n"); // Rotação Simples à Direita
                no = rotacaoR(no);
            } else {
                printf("Rotacao LR\n"); // Rotação Dupla Esquerda-Direita
                no = rotacaoLR(no);
            }
        }
    } else if(valor > no->valor) {
        no->dir = insere_arvoreAVL(no->dir, valor);

        if(fator_balanceamento(no) >= 2) {
            if(valor > no->dir->valor) {
                printf("Rotacao L\n"); // Rotação Simples à Esquerda
                no = rotacaoL(no);
            } else {
                printf("Rotacao RL\n"); // Rotação Dupla Direita-Esquerda
                no = rotacaoRL(no);
            }
        }
    }

    return no;
}

void imprime_preordem(No* no) {
    if(no == NULL) {
        return;
    }

    printf("%d ", no->valor);
    imprime_preordem(no->esq);
    imprime_preordem(no->dir);
}

void imprime_emordem(No* no) {
    if(no == NULL) {
        return;
    }

    imprime_emordem(no->esq);
    printf("%d ", no->valor);
    imprime_emordem(no->dir);
}

void imprime_posordem(No* no) {
    if(no == NULL) {
        return;
    }

    imprime_posordem(no->esq);
    imprime_posordem(no->dir);
    printf("%d ", no->valor);
}

int busca_arvore(No* no, int valor) {
    if(no == NULL) { // Não foi encontrado
        return 0;
    }

    if(no->valor == valor) { // Valor encontrado
        return 1;
    }

    if(valor < no->valor) {
        return busca_arvore(no->esq, valor);
    } else {
        return busca_arvore(no->dir, valor);
    }
}

int main() {
    Arvore* a = cria_arvore();

    char opcao;
    int valor;

    while(scanf("%c", &opcao) != EOF) {
        switch(opcao) {
            case 'I':
                scanf("%d", &valor);
                a->raiz = insere_arvoreAVL(a->raiz, valor);
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
            case 'H':
                printf("%d\n", altura_arvore(a->raiz));
                break;
            case 'B':
                scanf("%d", &valor);
                if(busca_arvore(a->raiz, valor)) {
                    printf("SIM\n");
                } else {
                    printf("NAO\n");
                }
        }
    }

    return 0;
}