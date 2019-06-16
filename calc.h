#ifndef _CALC_H_
#define _CALC_H_

#define OK 1
#define MALFORMADA 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct elem{
  int val;
  struct elem *next;
}elem;

struct pilha{
   /* seu código aqui, pode até usar uma lista... */
   struct llist *l;
};

struct llist{
  elem *head;
  int tam;
};

struct fila {
   /* seu código aqui, pode até usar uma lista... */
   struct llist *l;
};

struct pilha * create();

/** Apaga todos elementos da pilha
 * @param p descritor da pilha
 * @return 1 se OK, 0 se erro
 */
int makenull(struct pilha * p);

/* Retorna o elemento no topo da pilha, ou zero se não existir
 * @param p descritor da pilha
 * @return o elemento ou 0
 */
int top(struct pilha * p);

/* Descarta o topo da pilha
 * @param p descritor de pilha
 * @return 1 se OK, 0 se erro
 */
int pop(struct pilha * p);

/* Insere um elemento no topo da pilha
 * @param p descritor de pilha
 * @param val elemento a ser inserido
 * @return 1 se OK, 0 se erro
 */
int push(struct pilha * p, int val);

/* Retorna se a pilha está vazia ou não
 * @param p descritor de pilha
 * @return 1 se vazia, 0 se não
 */
 int vazia(struct pilha *p);
/** Desaloca toda a pilha
  * @param p descritor da pilha
  */
void destroy(struct pilha * p);




/** Cria uma lista.
 * @return descritor de lista ou NULL
 */
struct llist *create_l();

/** Cria um nodo de lista inicializado.
 * @param val valor a ser armazenado
 * @return ponteiro para nodo criado ou NULL
 */
 elem *create_node(int val);


 /** Insere um elemento na lista após um elemento
  * @param desc descritor da lista
  * @param prev nodo anterior, NULL se início da lista
  * @param ponteiro para o item o que será inserido
  * @return 1 se OK, 0 se erro
  */
 int insert_l(struct llist *desc, elem * prev, elem * item);

/** Remove um elemento de uma posição
* @param desc descritor da lista
* @param prev nodo anterior, NULL se início da lista
* @return 1 se OK, 0 se erro
*/
int delete_l(struct llist *desc, elem * prev);

/** Retorna ponteiro para elemento.
 * @param desc descritor da lista
 * @param pos posição para elemento
 * @return ponteiro para elemento
 */
elem *get_l(struct llist *desc, int pos);

/** Muda o valor do elemento.
 * @param desc descritor da lista
 * @param pos posição para elemento
 * @param item novo valor para item
 * @return 1 se OK, 0 se erro
 */
int set_l(struct llist *desc, int pos, int val);

/** Encontra um elemento com um determinado valor
* @param desc descritor da lista
* @param prev ponteiro para posição em que começa a busca pelo elemento
* @param val  valor buscado
* @return ponteiro caso encontre, NULL se não encontrar
*/
elem *locate_l(struct llist *desc, elem * prev, int val);

/** Retorna o comprimento da lista
* @param desc descritor da lista
* @return comprimento da lista atual
*/
int length_l(struct llist *desc);

/** Destrói a lista, liberando a memória e eliminando todos os elementos.
 * @param desc descritor da lista
 */
void destroy_l(struct llist *desc);

struct fila  *createfila();
int deleteelemfila(struct fila  * f);
int primeiro(struct fila  * f);
int dequeue(struct fila  * f);
int queue_fim(struct fila  * f, int val);
int empty (struct fila  *f);
void destroyfila(struct fila  * f);

/** Função que recebe uma expressão infix e calcula seu resultado
  * @param expr string terminada por \0 contendo a expressão
  * @param err código de erro
  * @return valor da expressão
  */ 
int calculadora(char * expr, int * err);

enum operacao {abrepar, fechapar, expon, multip, divisao, resto, adicao, subtracao};

enum num_ou_op {num, op};

struct entrada{
    int numero;
    enum operacao oper;
    enum num_ou_op tipo;
};


#endif /* _CALC_H_ */