/*
 * Exercício: Pilhas dinâmicas
 *
 * Neste exercício, vamos trabalhar com o gerenciamento de pilhas usando listas encadeadas em C. Neste exercício, vamos construir uma estrutura 
 * apropriada para manipulação e controle de pilhas. Vamos chamar essa estrutura de "Pilha" para armazenar números inteiros positivos.
 *
 * Sua tarefa será implementar funções que utilizem a estrutura "Pilha", conforme definição a seguir:
 *
 * typedef struct No{
 *      int valor;
 *      struct No* prox;
 * } No;
 *
 * typedef struct {
 *      No* topo;
 * }  Pilha;
 *
 * Você terá um arquivo chamado "pilha.c". Siga as orientações:
 *
 * 1) Você não pode mudar a assinatura das funções (nomes, parâmetros e tipos de retorno);
 * 2) Considere que a definição da estrutura string está definida no arquivo "pilha.h", também fornecido neste exercício;
 * 3) Faça o download do arquivo "pilha.c" e implemente as funções (ou faça a edição online aqui no Moodle);
 * 4) Como essa estrutura de pilha serve para trabalhar com números inteiros positivos, considere válidos somente valores inteiros maiores que zero.
 *
 * Observação: Quando uma área de memória alocada dinamicamente não for mais necessária, você deve liberá-la! Códigos que não liberarem memória nesses 
 * casos serão penalizados em 20% da pontuação da atividade. Particularmente, preste atenção na função de remoção de elementos!
 */

/****************************************************/
/*                                                  */
/*           PILHA DE INTEIROS POSITIVOS            */
/*                                                  */
/****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

/* Função que cria e devolve o endereço de uma pilha. 
 * A pilha criada estará vazia, com o topo igual a NULL. 
 */
Pilha* cria_pilha(){
    Pilha *P = (Pilha *) malloc(sizeof(Pilha));
    if(P == NULL) {
        printf("Não foi possível criar a Pilha.\n");
        exit(1);
    }
    P->topo = NULL;

    return P;
}

/* Verifica se a pilha enviada como parâmetro está vazia ou não.
 * Devolve 1 se a pilha estiver vazia, ou 0, caso contrário 
 */
int pilha_vazia(Pilha* P){
    if(P->topo == NULL) {
        return 1;
    }
    return 0;
}

/* Função que realiza a inclusão de um elemento na pilha. 
 * O elemento sempre é colocado no topo da pilha               
 */
void empilha (Pilha* P, int n){
    No *novo = (No *) malloc(sizeof(No));
    if(novo == NULL) {
        printf("Não foi possível alocar memória para o nó.\n");
        exit(1);
    }
    novo->valor = n;
    novo->prox = NULL;

    novo->prox = P->topo;
    P->topo = novo;
}

/* Função que devolve o elemento do topo da pilha após desempilha-lo.
 * Deve liberar a memória após de desempilhamento. Se a pilha estiver
 * vazia, deve devolver -1
 */
int desempilha (Pilha* P){
    if(P->topo == NULL) {
        return -1;
    }

    int valor_topo = P->topo->valor;

    No *aux = P->topo;
    P->topo = aux->prox;
    free(aux); // Libera a memória do nó que foi desempilhado.

    return valor_topo;
}

/* Função que retorna o elemento que está no topo da pilha, mas sem
 * desempilha-lo. Se a pilha estiver vazia, devolve -1.
 */
int topo (Pilha* P){
    if(P->topo == NULL) {
        return -1;
    }

    return P->topo->valor;
}

/* Função que mostra os elementos da pilha passada como parâmetro.
 * Imprime os elementos da pilha iniciando por seu topo, separados
 * por um espaço branco. Imprime uma quebra de linha no final.
 */
void imprime (Pilha* P){
    No *aux = P->topo;
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

    Pilha *P = cria_pilha();

    int i;

    printf("Testando se a Pilha está vazia...\n");
    if(pilha_vazia(P)) {
        printf("Pilha vazia!\n");
    } else {
        printf("Pilha não está vazia!\n");
    }

    printf("\n");
    for(i = 0; i < 10; i++) {
        printf("Empilhando %d.\n", i+1);
        empilha(P, i+1);
    }

    printf("\nTestando se a Pilha está vazia...\n");
    if(pilha_vazia(P)) {
        printf("Pilha vazia!\n");
    } else {
        printf("Pilha não está vazia!\n");
    }

    printf("\nTopo: %d\n", topo(P));

    printf("\n");
    imprime(P);
    printf("\n");

    for(i = 0; i < 10; i++) {
        printf("Desempilhando %d.\n", desempilha(P));
    }

    printf("\nTestando se a Pilha está vazia...\n");
    if(pilha_vazia(P)) {
        printf("Pilha vazia!\n");
    } else {
        printf("Pilha não está vazia!\n");
    }

    return 0;
}
*/
