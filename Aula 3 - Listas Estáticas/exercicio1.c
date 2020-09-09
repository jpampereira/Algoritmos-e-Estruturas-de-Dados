/*
 * Exercício: Lista Estática
 * 
 * Você deverá implementar uma lista que armazena valores inteiros.
 * 
 * Entrada: O programa receberá um número natural T, que representa a capacidade máxima da lista. Em seguida, seu programa deverá ler uma sequência de 
 * operações que deverá ser aplicada à lista, inicialmente vazia.
 * 
 * As operações possíveis são (considere <v> um valor inteiro):
 * 
 * I <v>    =>  inclusão do valor <v> na lista
 * E <v>	=>  exclusão do valor <v> na lista
 * 
 * Operações de inclusão devem ser ignoradas quando a lista estiver cheia. Da mesma forma, operações de exclusão de valores que não estão na lista devem 
 * ser ignoradas.
 * 
 * Saída: O seu programa deverá exibir a lista após a aplicação de todas as operações indicadas na entrada de dados.
 * 
 * Exemplo:
 * 
 * Entrada	Saída
 * 
 * 10       9 30 3
 * I 15
 * I 9
 * I 3
 * I 80
 * I 30
 * I 3
 * E 15
 * E 99
 * E 80
 * E 3
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Lista {
    int *dados;
    int qtd;
    int capacidade;
} Lista;

Lista * cria_lista(int c) {
    Lista *l = (Lista *) malloc(sizeof(Lista));
    if(l == NULL) {
        printf("Não foi possível alocar memória.\n");
        exit(1);
    }

    int *d = (int *) malloc(c*sizeof(int));
    if(d == NULL) {
        printf("Não foi possível alocar memória.\n");
        exit(1);
    }

    l->dados = d;
    l->qtd = 0;
    l->capacidade = c;

    return l;
}

void insere_lista(Lista *l, int v) {
    if(l->qtd < l->capacidade) {
        l->dados[l->qtd]= v;
        l->qtd++;
    }
}

void remove_lista(Lista *l, int v) {
    int i, j;

    for(i = 0; i < l->qtd && l->dados[i] != v; i++);

    if(i < l->qtd) {
        for(j = i; j < l->qtd-1; j++) {
            l->dados[j] = l->dados[j+1];
        }
        l->qtd--;
    }
}

void imprime_lista(Lista *l) {
    for(int i = 0; i < l->qtd; i++) {
        if(i < l->qtd-1) {
            printf("%d ", l->dados[i]);
        } else {
            printf("%d\n", l->dados[i]);
        }
    }
}

int main() {

    int capacidade;
    scanf("%d", &capacidade);

    Lista *l = cria_lista(capacidade);

    char operacao;
    int valor;

    while(scanf("%c %d", &operacao, &valor) != EOF) {
        if(operacao == 'I')
            insere_lista(l, valor);
        else if(operacao == 'E')
            remove_lista(l, valor);
    }

    imprime_lista(l);

    return 0;
}