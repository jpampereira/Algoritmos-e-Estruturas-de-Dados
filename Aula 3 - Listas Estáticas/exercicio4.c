/*
 * Exercício: Pilhas dinâmicas com vetores
 * 
 * Você deve implementar uma pilha dinâmica de números inteiros utilizando vetores. Sua lista deve conseguir receber um número qualquer de inserções e 
 * remoções de elementos.
 * 
 * Entrada: A entrada é formada por uma sequência de comandos. Cada comando ocupará exatamente uma linha da entrada. Os comandos possíveis estão na lista 
 * a seguir:
 * 
 * E [valor]    => empilha um novo elemento na pilha.
 * D            => desempilha o elemento do topo da pilha. Se a pilha estiver vazia, nada deverá ser feito
 * T	        => Devolve o elemento do topo da pilha (sem, entretanto, desempilha-lo), ou -1 se a pilha estiver vazia.
 * C	        => exibe a quantidade de elementos da pilha.
 * M	        => exibe os elementos da pilha, separados por um espaço branco.
 * 
 * Saída: A saída será construída a partir de cada comportamento dos comandos de entrada:
 * 
 * E [valor]    =>  não há saída.
 * D	        =>  exibe o elemento desempilhado, ou -1, se a pilha estiver vazia. Ao final, exibe uma quebra de linha.
 * T	        => exibe o elemento do topo da pilha, ou -1, se a pilha estiver vazia. Ao final, exibe uma quebra de linha
 * C	        => exibe a quantidade de elementos da pilha, seguida de uma quebra de linha.
 * M	        => exibe os elementos da pilha de forma sequencial, a partir do topo. Os elementos são separados por um espaço branco. 
 *              Ao final, há uma quebra de linha.
 * 
 * Exemplo:
 * 
 * Entrada	Saída
 * 
 * E 4
 * E 7
 * E 8
 * E 1
 * M        1 8 7 4
 * C        4
 * E 4
 * E 9 
 * D        9
 * D        4
 * T        1
 * D        1
 * D        8
 * D        7
 * D        4
 * D        -1
 * E 4
 * M        4
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct Pilha {
    int *dados;
    int topo;
    int capacidade;
} Pilha;

Pilha * cria_pilha() {
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    if(p == NULL) {
        printf("Não foi possível alocar memória");
        exit(1);
    }

    int *d = (int *) malloc(MAX * sizeof(int));
    if(d == NULL) {
        printf("Não foi possível alocar memória");
        exit(1);
    }

    p->dados = d;
    p->topo = 0;
    p->capacidade = MAX;

    return p;
}

void aumentar_capacidade(Pilha *p) {
    int *novo_dados = (int *) malloc((p->capacidade + MAX) * sizeof(int));
    if(novo_dados == NULL) {
        printf("Não foi possível alocar memória");
        exit(1);
    }

    for(int i = 0; i < p->topo; i++) {
        novo_dados[i] = p->dados[i];
    }

    free(p->dados);
    p->dados = novo_dados;
    p->capacidade += MAX;
}

void empilha(Pilha *p, int v) {
    if(p->topo == p->capacidade) {
        aumentar_capacidade(p);
    }

    p->dados[p->topo] = v;
    p->topo++;
}

int desempilha(Pilha *p) {
    if(p->topo == 0) {
        return -1;
    }

    int v = p->dados[p->topo-1];
    p->topo--;

    return v;
}

int consulta(Pilha *p) {
    if(p->topo == 0) {
        return -1;
    }

    return p->dados[p->topo-1];
}

int qtd_elementos(Pilha *p) {
    return p->topo;
}

void imprime(Pilha *p) {
    for(int i = p->topo-1; i >= 0; i--) {
        if(i > 0) {
            printf("%d ", p->dados[i]);
        } else {
            printf("%d\n", p->dados[i]);
        }
    }
}

int main() {
    Pilha *p = cria_pilha();

    char opcao;
    int valor;

    while(scanf("%c", &opcao) != EOF) {
        switch(opcao) {
            case 'E':
                scanf("%d", &valor);
                empilha(p, valor);
                break;
            case 'D':
                printf("%d\n", desempilha(p));
                break;
            case 'T':
                printf("%d\n", consulta(p));
                break;
            case 'C':
                printf("%d\n", qtd_elementos(p));
                break;
            case 'M':
                imprime(p);
                break;
        }
    }

    return 0;
}