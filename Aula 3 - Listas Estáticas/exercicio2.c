/*
 * Exercício: Lista Dinâmica com Vetores
 * 
 * Você deve implementar uma lista dinâmica de números inteiros. Sua lista deve conseguir receber um número qualquer de inserções e remoções de elementos.
 * 
 * Entrada: A entrada é formada por uma sequência de comandos. Cada comando ocupará exatamente uma linha da entrada. Os comandos possíveis estão na lista 
 * a seguir:
 * 
 * I [valor]	=>  insere o valor [valor] no fim da lista de números.
 * R [valor]	=>  remove o valor [valor] da lista, caso ele esteja nela.
 * B [valor]	=>  verifica se o valor [valor] está presente na lista ou não.
 * T	        =>  inverte a sequência de elementos da lista.
 * E	        =>  exibe os elementos da lista, separados por um espaço branco.
 * C	        =>  exibe a quantidade de elementos da lista.
 * 
 * Saída: A saída será construída a partir de cada comportamento dos comandos de entrada:
 * 
 * I [valor]	=>  não há saída.
 * R [valor]	=>  não há saída.
 * B [valor]	=>  exibe "SIM" ou "NAO", seguido de uma quebra de linha.
 * T	        =>  não há saída.
 * E	        =>  exibe os elementos da lista de forma sequencial, a partir da posição 0. Os elementos são separados por vírgula. Ao final, há uma quebra 
 *              de linha.
 * C	        =>  exibe a quantidade de elementos da lista, seguida de uma quebra de linha.
 * 
 * Exemplo:
 * 
 * Entrada	Saída
 * 
 * I 50
 * I 20
 * I 30
 * I 12
 * I -3
 * E        50, 20, 30, 12, -3
 * R 20
 * I 11
 * R 50
 * E        30, 12, -3, 11
 * B 50     NAO
 * T        
 * E        11, -3, 12, 30
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct Lista {
    int *dados;
    int qtd;
    int capacidade;
} Lista;

Lista * cria_lista() {
    Lista *l = (Lista *) malloc(sizeof(Lista));
    if(l == NULL) {
        printf("Não foi possível alocar memória.\n");
        exit(1);
    }

    int *d = (int *) malloc(MAX * sizeof(int));
    if(d == NULL) {
        printf("Não foi possível alocar memória.\n");
        exit(1);
    }

    l->dados = d;
    l->qtd = 0;
    l->capacidade = MAX;

    return l;
}

void aumenta_capacidade(Lista *l) {
    int *novo_dados = (int *) malloc((l->qtd + MAX)*sizeof(int));
    if(l == NULL) {
        printf("Não foi possível alocar memória.\n");
        exit(1);
    }

    for(int i = 0; i < l->qtd; i++) {
        novo_dados[i] = l->dados[i];
    }

    free(l->dados);
    l->dados = novo_dados;
    l->capacidade += MAX;
}

void insere_lista(Lista *l, int v) {
    if(l->qtd == l->capacidade) {
        aumenta_capacidade(l);
    }

    l->dados[l->qtd] = v;
    l->qtd++;
}

void remove_lista(Lista *l, int v) {
    if(l->qtd > 0) {
        int i, j;

        for(i = 0; i < l->qtd && l->dados[i] != v; i++);

        if(i < l->qtd) {
            for(j = i; j < l->qtd-1; j++) {
                l->dados[j] = l->dados[j+1];
            }
            l->qtd--;
        }
    }
}

char * consulta_lista(Lista *l, int v) {
    int i;
    for(i = 0; i < l->qtd && l->dados[i] != v; i++);

    if(i < l->qtd) {
        return "SIM";
    }
    return "NAO";
}

void inverte_lista(Lista *l) {
    int aux;
    for(int i = 0; i < l->qtd/2; i++) {
        aux = l->dados[i];
        l->dados[i] = l->dados[l->qtd-i-1];
        l->dados[l->qtd-i-1] = aux;
    }
}

void imprime_lista(Lista *l) {
    for(int i = 0; i < l->qtd; i++) {
        if(i < l->qtd-1) {
            printf("%d, ", l->dados[i]);
        } else {
            printf("%d\n", l->dados[i]);
        }
    }
}

int quantidade_elementos(Lista *l) {
    return l->qtd;
}

int main() {
    Lista *l = cria_lista();

    char operacao;
    int valor;

    while(scanf("%c", &operacao) != EOF) {
        switch(operacao) {
            case 'I':
                scanf("%d", &valor);
                insere_lista(l, valor);
                break;
            case 'R':
                scanf("%d", &valor);
                remove_lista(l, valor);
                break;
            case 'B':
                scanf("%d", &valor);
                printf("%s\n", consulta_lista(l, valor));
                break;
            case 'T':
                inverte_lista(l);
                break;
            case 'E':
                imprime_lista(l);
                break;
            case 'C':
                printf("%d\n", quantidade_elementos(l));
                break;
        }
    }

    return 0;
}