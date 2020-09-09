/****************************************************/
/*                                                  */
/*           PILHA DE INTEIROS POSITIVOS            */
/*                                                  */
/****************************************************/

/* Estrutura usada para representar um elemento da Pilha */
typedef struct No {
    int valor;          /* valor armazenado */
    struct No* prox;    /* endereço do próximo elemento */
} No;

/* Estrutura usada para representar a Pilha */
typedef struct {
    No* topo;     /* endereço no elemento no topo da pilha */
} Pilha;


/*   Função que cria e devolve o endereço de uma pilha. 
     A pilha criada estará vazia, com o topo igual a NULL. */
Pilha* cria_pilha();

/* Verifica se a pilha enviada como parâmetro está vazia ou não.
   Devolve 1 se a pilha estiver vazia, ou 0, caso contrário */
int pilha_vazia(Pilha*);

/* Função que realiza a inclusão de um elemento na pilha. O
   elemento sempre é colocado no topo da pilha               */
void empilha (Pilha*, int);

/* Função que devolve o elemento do topo da pilha após desempilha-lo.
   Deve liberar a memória após de desempilhamento. Se a pilha estiver
   vazia, deve devolver -1                                   */
int desempilha (Pilha*);

/* Função que retorna o elemento que está no topo da pilha, mas sem
   desempilha-lo. Se a pilha estiver vazia, devolve -1.      */
int topo (Pilha*);

/* Função que mostra os elementos da pilha passada como parâmetro.
   Imprime os elementos da pilha iniciando por seu topo, separados
   por um espaço branco. Imprime uma quebra de linha no final.
                                                              */
void imprime (Pilha*);
