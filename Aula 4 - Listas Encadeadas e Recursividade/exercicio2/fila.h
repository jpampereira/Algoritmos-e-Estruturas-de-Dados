/****************************************************/
/*                                                  */
/*           PILHA DE INTEIROS POSITIVOS            */
/*                                                  */
/****************************************************/

/* Estrutura usada para representar um elemento da Fila */
typedef struct No {
    int valor;          /* valor armazenado */
    struct No* prox;    /* endereço do próximo elemento */
} No;

/* Estrutura usada para representar a Fila */
typedef struct {
    No* inicio;     /* endereço no elemento no inicio da fila */
} Fila;


/*   Função que cria e devolve o endereço de uma pilha. 
     A fila criada estará vazia, com o inicio igual a NULL. */
Fila* cria_fila();

/* Verifica se a fila enviada como parâmetro está vazia ou não.
   Devolve 1 se a fila estiver vazia, ou 0, caso contrário */
int fila_vazia(Fila*);

/* Função que realiza a inclusão de um elemento no fim da fila. */
void enfileira (Fila*, int);

/* Função que devolve o elemento do inicio da fila após sua remoção.
   Deve liberar a memória após de desenfileiramento. Se a fila estiver
   vazia, deve devolver -1                                   */
int desenfileira (Fila*);

/* Função que retorna o elemento que está no inicio da fila, mas sem
   remove-lo. Se a pilha estiver vazia, devolve -1.      */
int inicio_fila (Fila*);

/* Função que mostra os elementos da fila passada como parâmetro.
   Imprime os elementos da fila iniciando por seu inicio, separados
   por um espaço branco. Imprime uma quebra de linha no final.
                                                                  */
void imprime (Fila*);
