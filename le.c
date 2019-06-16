#include "calc.h"

struct llist *create_l(){
	struct llist *cabeca;
	cabeca = malloc(sizeof(struct llist));
	cabeca->tam = 0;
	cabeca->head = NULL;
	return cabeca;
}

 elem *create_node(int val){
 	elem *NovoElemento;
 	NovoElemento = malloc(sizeof(struct elem));
 	NovoElemento->next = NULL;
 	NovoElemento->val = val;
 	return NovoElemento; 
 }

int length_l(struct llist *desc){
	if(desc == NULL){
		return 0;
	}
	return desc->tam;
}
//
 int insert_l(struct llist *desc, elem *prev, elem *item){
 	struct llist *cabeca;
 	cabeca = desc;
 	if(item != NULL){
 		if(prev == NULL){
	 		item->next = cabeca->head;
	 		cabeca->head = item;
	 		}
	 	else{
	 		item->next = prev->next;
	 		prev->next = item;
	 	}
	 	cabeca->tam++;
	 	return 1;
 	}
 		else{
 			return 0;
 		}
 }

/** Remove um elemento de uma posição
* @param desc descritor da lista
* @param prev nodo anterior, NULL se início da lista
* @return 1 se OK, 0 se erro
*/
int delete_l(struct llist *desc, elem * prev){
	elem *aux;
	elem *item;
	aux = prev;
	if(aux != NULL){
		if(aux->next == NULL){
			return 0;
		}
		else{
			item=aux->next;
			aux->next = item->next;
			free(item);
			desc->tam--;
			return 1;
		}
	}else{
			//printf("erro tam\n");
			if(desc->tam == 1){
				free(desc->head);
				desc->tam--;
				return 1;
			}
			return 0;
		}
	}	
	
	

/** Retorna ponteiro para elemento.
 * @param desc descritor d) lista
 * @param pos posição para elemento
 * @return ponteiro para elemento
 */
//
elem *get_l(struct llist *desc, int pos){
	elem *aux;
	int i;
	if(desc == NULL){
		return NULL;
	}
	else{
		if(desc->head == NULL){
			return NULL;
		}
		else{
			if(pos>desc->tam || pos<1 ){
				return NULL;
			}
			else{
				aux = desc->head;
				for(i=1; i<pos; i++){
					aux = aux->next;
				}
				if(i == pos){
					return aux;
				}
			}
		}
	}
	return aux;
}
/** Muda o valor do elemento.
 * @param desc descritor da lista
 * @param pos posição para elemento
 * @param item novo valor para item
 * @return 1 se OK, 0 se erro
 */
int set_l(struct llist *desc, int pos, int val){
	elem *aux;
	int i = 1;
	if(desc->tam>=pos){
	if(desc->head == NULL){
		return 0;
	}
	else{
		aux = desc->head;
		if(pos<1){
			return 0;
		}
		else{
			while(i!=pos && aux != NULL){
				aux = aux->next;
				i++;
			}
			if(i == pos){
				aux->val = val;
				return 1;
			}
			if(aux == NULL){
				return 0;
			}
		}
	}
}else{
	return 0;
}
return 0;
}


/** Encontra um elemento com um determinado valor
* @param desc descritor da lista
* @param prev ponteiro para posição em que começa a busca pelo elemento
* @param val  valor buscado
* @return ponteiro caso encontre, NULL se não encontrar
*/
elem * locate_l(struct llist *desc, elem * prev, int val){
	if(desc->head == NULL){
		return NULL;
	}else{
		while(prev!=NULL){
			if(prev->val == val){
				return prev;
			}else{
				prev=prev->next;
			}
		}	
	}
	return prev;
}
/** Destrói a lista, liberando a memória e eliminando todos os elementos.
 * @param desc descritor da lista
 */
void destroy_l(struct llist *desc){
	struct llist *cabeca;
	elem *aux;
	cabeca = desc;
	for(aux = cabeca->head; cabeca->head != NULL; aux = aux->next){
		cabeca->head = aux->next;
		free(aux);
	}
	free(cabeca);
}