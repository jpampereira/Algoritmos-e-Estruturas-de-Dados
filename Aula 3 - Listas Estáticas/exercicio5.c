/*
 * Exercício: Filas Dinâmicas com Vetores
 * 
 * Você deve implementar uma fila dinâmica de números inteiros utilizando vetores. Sua fila deve conseguir receber um número qualquer de inserções e 
 * remoções de elementos.
 * 
 * Entrada: A entrada é formada por uma sequência de comandos. Cada comando ocupará exatamente uma linha da entrada. Os comandos possíveis estão na 
 * lista a seguir:
 * 
 * E [valor]    =>  enfileira um novo elemento na fila.
 * D	        =>  desenfileira o elemento do início da fila. Se a fila estiver vazia, nada deverá ser feito.
 * C	        =>  exibe a quantidade de elementos da fila.
 * M	        =>  exibe os elementos da fila, separados por um espaço branco.
 * 
 * Saída: A saída será construída a partir de cada comportamento dos comandos de entrada:
 * 
 * E [valor]	=>  não há saída.
 * D	        =>  exibe o elemento removido da fila seguido de uma quebra de linha. Se a fila estiver vazia, deve exibir somente a quebra de linha.
 * C	        =>  exibe a quantidade de elementos da fila, seguida de uma quebra de linha.
 * M	        => exibe os elementos da fila de forma sequencial, a partir de seu início. Os elementos são separados por um espaço branco. Ao final, 
 *              há uma quebra de linha.
 * 
 * Exemplo:
 * 
 * Entrada	Saída
 * E 4      
 * E 7
 * E 8
 * E 1
 * M        4 7 8 1
 * C        4
 * E 4      
 * E 9 
 * D        4
 * D        7
 * D        8
 * D        1
 * D        4
 * D        9
 * D        
 * E 4  
 * M        4
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Fila {
    int *dados;
    int inicio;
    int final;
    int qtd;
    int capacidade;
} Fila;

Fila * cria_fila() {
    Fila *f = (Fila *) malloc(sizeof(Fila));
    if(f == NULL) {
        printf("Não foi possível alocar memória.\n");
        exit(1);
    }

    int *d = (int *) malloc(MAX * sizeof(int));
    if(d == NULL) {
        printf("Não foi possível alocar memória.\n");
        exit(1);
    }

    f->dados = d;
    f->inicio = 0;
    f->final = 0;
    f->qtd = 0;
    f->capacidade = MAX;

    return f;
}

void aumenta_capacidade(Fila *f) {
    int *novo_dados = (int *) malloc((f->capacidade + MAX) * sizeof(int));
    if(novo_dados == NULL) {
        printf("Não foi possível alocar memória.\n");
        exit(1);
    }

    int j = 0;
    for(int i = f->inicio; i < f->final; i++) {
        novo_dados[j] = f->dados[i];
        j++;
    }

    free(f->dados);

    f->dados = novo_dados;
    f->inicio = 0;
    f->final = f->qtd;
    f->capacidade += MAX;
}

void enfileira(Fila *f, int v) {
    if(f->qtd == f->capacidade) {
        aumenta_capacidade(f);
    }

    f->dados[f->final] = v;
    f->final++;
    f->qtd++;
}

void desenfileira(Fila *f) {
    if(f->qtd != 0) {
        printf("%d\n", f->dados[f->inicio]);

        for(int i = f->inicio; i < f->final-1; i++) {
            f->dados[i] = f->dados[i+1];
        }
        f->final--;
        f->qtd--;
    }
}

int qtd_elementos(Fila *f) {
    return f->qtd;
}

void imprime_fila(Fila *f) {
    for(int i = f->inicio; i < f->final; i++) {
        if(i < f->final-1) {
            printf("%d ", f->dados[i]);
        } else {
            printf("%d\n", f->dados[i]);
        }
    }
}

int main() {

    Fila *f = cria_fila();

    char opcao;
    int valor;

    while(scanf("%c", &opcao) != EOF) {
        switch(opcao) {
            case 'E':
                scanf("%d", &valor);
                enfileira(f, valor);
                break;
            case 'D':
                desenfileira(f);
                break;
            case 'C':
                printf("%d\n", qtd_elementos(f));
                break;
            case 'M':
                imprime_fila(f);
                break;
        }
    }

    return 0;
}