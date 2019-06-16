#include "calc.h"

/** Cria uma pilha
 * @return  um descritor ou NULL
 */
struct fila  *createfila(){
	struct fila *p; 
	struct llist *aux;
	p=malloc(sizeof(struct fila));
	aux=create_l();
	p->l = aux;
	return p;
}

/** Apaga todos elementos da pilha
 * @param p descritor da pilha
 * @return 1 se OK, 0 se erro
 */
int deleteelemfila(struct fila  *p){
	elem* nodo;
	if(p == NULL){
		return 0;
	}
	if(p->l == NULL){
		return 0;
	}
	while(p->l->head->next!=NULL){
		nodo=p->l->head->next;
		p->l->head->next=p->l->head->next->next;
		free(nodo);
	}
	return 1;	
	}


/* Retorna o elemento no topo da pilha, ou zero se não existir
 * @param p descritor da pilha
 * @return o elemento ou 0
 */
int primeiro(struct fila  *p){
	elem *aux;
	aux = p->l->head;
	if(p->l == NULL){
		return 0 ;
	}
	else{
		return aux->val;
	}
}

/* Descarta o topo da pilha
 * @param p descritor de pilha
 * @return 1 se OK, 0 se erro
 */
int dequeue(struct fila  *p){
	struct elem *aux;
	aux = p->l->head;
	p->l->head = aux->next;
	free(aux);
	p->l->tam--;
	return 1;
}


/* insere no final pilha
 * @param p descritor de pilha
 * @param val elemento a ser inserido
 * @return 1 se OK, 0 se erro
 */
int queue_fim(struct fila  *p, int val){
	elem *aux;
	elem *item;
	aux = create_node(val);
	if(p->l->head == NULL){
		p->l->head = aux;
		aux->next = NULL;
		p->l->tam++;
	}
	else{
		item=p->l->head;
		while(item->next != NULL){
			item = item->next;
		}
		item->next = aux;
		aux->next = NULL;
		p->l->tam++;
		return 0;
	}
return 0;
}


/* Retorna se a pilha está vazia ou não
 * @param p descritor de pilha
 * @return 1 se vazia, 0 se não
 */
 int empty (struct fila  *p){
	 if(p->l->head->next==NULL){
		 return 1;
	 }
	 else{
		 return 0;
	 }
 }
	 
/** Desaloca toda a pilha
  * @param p descritor da pilha
  */
void destroyfila(struct fila  *p){
	if(deleteelemfila(p) == 1){
		free(p->l->head);
		free(p->l);
		free(p);
	}		
}
