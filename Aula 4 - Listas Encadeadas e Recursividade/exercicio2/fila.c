/*
 * Exercício: Filas dinâmicas
 * 
 * Neste exercício, vamos trabalhar com o gerenciamento de filas usando listas encadeadas em C. Neste exercício, vamos construir uma estrutura apropriada 
 * para manipulação e controle de filas. Vamos chamar essa estrutura de "Fila" para armazenar números inteiros positivos.
 * 
 * Sua tarefa será implementar funções que utilizem a estrutura "Fila", conforme definição a seguir:
 * 
 * typedef struct No {
 *      int valor;
 *      struct No* prox;
 * } No;
 * 
 * typedef struct {
 *      No* inicio;
 * }  Fila;
 * 
 * Você terá um arquivo chamado "fila.c". Siga as orientações:
 * 
 * 1) Você não pode mudar a assinatura das funções (nomes, parâmetros e tipos de retorno);
 * 2) Considere que a definição da estrutura string está definida no arquivo "pilha.h", também fornecido neste exercício;
 * 3) Faça o download do arquivo "fila.c" e implemente as funções (ou faça a edição online aqui no Moodle);
 * 4) Como essa estrutura de fila serve para trabalhar com números inteiros positivos, considere válidos somente valores inteiros maiores que zero.
 * 
 * Observação: Quando uma área de memória alocada dinamicamente não for mais necessária, você deve liberá-la! Códigos que não liberarem memória nesses 
 * casos serão penalizados em 20% da pontuação da atividade. Particularmente, preste atenção na função de remoção de elementos!
 */

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


/* Função que cria e devolve o endereço de uma fila. 
 * A fila criada estará vazia, com o inicio igual a NULL. 
 */
Fila* cria_fila(){
    Fila *F = (Fila *) malloc(sizeof(Fila));
    if(F == NULL) {
        printf("Não foi possível criar a Fila.\n");
        exit(1);
    }
    F->inicio = NULL;

    return F;
}

/* Verifica se a fila enviada como parâmetro está vazia ou não.
 * Devolve 1 se a fila estiver vazia, ou 0, caso contrário.
 */
int fila_vazia(Fila* F){
    if(F->inicio == NULL) {
        return 1;
    }
    return 0;
}

/* Função que realiza a inclusão de um elemento no fim da fila.*/
void enfileira (Fila* F, int n){ 
    No *novo = (No *) malloc(sizeof(No));
    if(novo == NULL) {
        printf("Não foi possível alocar memória para o nó.\n");
        exit(1);
    }
    novo->valor = n;
    novo->prox = NULL;

    if(F->inicio == NULL) {
        F->inicio = novo;
    } else {
        No *aux = F->inicio;
        while(aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

/* Função que devolve o elemento do inicio da fila após sua remoção.
 * Deve liberar a memória após de desenfileiramento. Se a fila estiver
 * vazia, deve devolver -1.                              
 */
int desenfileira (Fila* F){
    if(F->inicio == NULL) {
        return -1;
    }

    int valor_inicio = F->inicio->valor;

    No *aux = F->inicio;
    F->inicio = aux->prox;
    free(aux); // Libera a memória do nó que foi desenfileirado.

    return valor_inicio;
}

/* Função que retorna o elemento que está no inicio da fila, mas sem
 * remove-lo. Se a pilha estiver vazia, devolve -1.      
 */
int inicio_fila (Fila* F){
    if(F->inicio == NULL) {
        return -1;
    }

    return F->inicio->valor;
}

/* Função que mostra os elementos da fila passada como parâmetro.
 * Imprime os elementos da fila iniciando por seu inicio, separados
 * por um espaço branco. Imprime uma quebra de linha no final.
 */
void imprime (Fila* F){
    No *aux = F->inicio;
    while(aux != NULL) {
        if(aux->prox != NULL) {
            printf("%d ", aux->valor);
        } else {
            printf("%d\n", aux->valor);
        }
        aux = aux->prox;
    }
    free(aux);
}

/* Função main criada apenas para verificar se as funções estavam 
 * funcionando corretamente.
 */

/*
int main() {

    Fila *F = cria_fila();

    int i;

    printf("Testando se a Fila está vazia...\n");
    if(fila_vazia(F)) {
        printf("Fila vazia!\n");
    } else {
        printf("Fila não está vazia!\n");
    }

    printf("\n");
    for(i = 0; i < 10; i++) {
        printf("Enfileirando %d.\n", i+1);
        enfileira(F, i+1);
    }

    printf("\nTestando se a Fila está vazia...\n");
    if(fila_vazia(F)) {
        printf("Fila vazia!\n");
    } else {
        printf("Fila não está vazia!\n");
    }

    printf("\nInício da Fila: %d\n", inicio_fila(F));

    printf("\n");
    imprime(F);
    printf("\n");

    for(i = 0; i < 10; i++) {
        printf("Desenfileirando %d.\n", desenfileira(F));
    }

    printf("\nTestando se a Fila está vazia...\n");
    if(fila_vazia(F)) {
        printf("Fila vazia!\n");
    } else {
        printf("Fila não está vazia!\n");
    }

    return 0;
}
*/