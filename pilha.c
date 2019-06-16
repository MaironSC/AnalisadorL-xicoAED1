#include "calc.h"
/** Cria uma pilha
 * @return  um descritor ou NULL
 */
struct pilha *create(){
	struct pilha *novapilha;
	novapilha = malloc(sizeof(struct pilha));
	novapilha->l = malloc(sizeof(struct llist));
	novapilha->l->head = NULL; 
	novapilha->l->tam = 0;
	return novapilha; 

}
/** Apaga todos elementos da pilha
 * @param p descritor da pilha
 * @return 1 se OK, 0 se erro
 */
int makenull(struct pilha *p){
	elem *aux;
	aux = p->l->head;
	elem *item;
	if(p->l->head != NULL){
		if(aux->next == NULL){
			return 0;
		}
		else{
			item=aux->next;
			aux->next = item->next;
			free(item);
			p->l->tam--;
			return 1;
		}
	}else{
				//printf("erro tam\n");
			if(p->l->tam == 1){
				free(p->l->head);
				p->l->tam--;
				return 1;
			}
			return 0;
	}
}
/* Retorna o elemento no topo da pilha, ou zero se não existir
 * @param p descritor da pilha
 * @return o elemento ou 0
 */
int top(struct pilha * p){
	elem *aux;
	if(p == NULL){
		return 0;
	}
	else{
		if(p->l->head == NULL){
			return 0;
		}
		else{
				aux = p->l->head;
				return aux->val;
		}
	}
}
/* Descarta o topo da pilha
 * @param p descritor de pilha
 * @return 1 se OK, 0 se erro
 */
int pop(struct pilha * p){
	elem *aux;
	elem *item;
	aux = p->l->head;
	if(aux != NULL){
			item=p->l->head;
			p->l->head = item->next;
			//aux->next = item->next;
			free(item);
			p->l->tam--;
			return 1;
		}
		else{
			return 0;
		}
}
/* Insere um elemento no topo da pilha
 * @param p descritor de pilha
 * @param val elemento a ser inserido
 * @return 1 se OK, 0 se erro
 */
int push(struct pilha * p, int val){
	elem *item;
	 	if(p != NULL){
	 		item=create_node(val);
		 	item->next = p->l->head;
		 	p->l->head = item;
		 	p->l->tam++;
		 	return 1;
	 	}
	 		else{
	 			return 0;
	 		}
}
/* Retorna se a pilha está vazia ou não
 * @param p descritor de pilha
 * @return 1 se vazia, 0 se não
 */
 int vazia(struct pilha *p){
 	if(p->l->tam == 0){
 		return 1;
 	}
 	else{
 		return 0;
 	}
 }
/** Desaloca toda a pilha
  * @param p descritor da pilha
  */
void destroy(struct pilha * p){
	elem *aux;
	elem *item;
	int contador = 0;
	for(;p->l->head != NULL;){
		aux = p->l->head;
		item = aux;
		p->l->head = item->next;
		free(item);
		p->l->tam--;
		contador++;
		//printf("dfs%d\n", contador);
	}
	free(p->l);
//	printf("erro\n");
	free(p);
}
	

