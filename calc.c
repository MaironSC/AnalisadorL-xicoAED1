#include "calc.h"

int simbolo (char letra){
	int flagaux;
	if(letra >=48 && letra<=57){
		flagaux = 1;
	}	
	if(letra == 40 || letra == 41){
		flagaux = 2;
	}
	if(letra == '*' || letra == '^' || letra == '/' || letra == '+' || letra == '-' || letra =='%'){
		flagaux = 3;
	}
	if(letra == 32){
		flagaux = 4;
	}
	return flagaux;
}

int *formular(char *palavra, int tamanho){
	int i = 0;;
	int *flagvetor;
	flagvetor = malloc(sizeof(int)*100);
		for(i = 0; i<=tamanho; i++){
			flagvetor[i] = simbolo(*(palavra+i));	
		}	
	return flagvetor;	
}

// 1 - NUMERO
// 2 - PARENTES
// 3 - OPERANDOS
// 4 - ESPAÇO

int formularpraanexar(int *flag, int tamanhodastring, char *palavra){
	int aux1;
	int aux2;
	int parenteses = 0;
	for(aux1=0; aux1<=tamanhodastring; aux1++){
		aux2 = 2 + aux1;
		
		if(aux1 == tamanhodastring){
			if(palavra[aux1] == 40){
				parenteses++;
			}
			if(palavra[aux1] == 41){
				parenteses --;
			}
		}
		if(flag[aux1 + 1] == '\0'){
			if(flag[aux1] == 40){
				parenteses++;
			}
			if(flag[aux1] == 41){
				parenteses--;
			}
			break;
		}

		if(flag[aux1] == 4 && flag[aux1+1] == 4){
			return 0;
		}
		if(flag[aux1] == 1 && flag[aux1+1] !=4){
			return 0;
		}
		if((flag[aux1] == 2 || flag[aux1] == 3) && (flag[aux1+1] != 4  )){
			return 0;
		}
		if(flag[aux1] == 1 && flag[aux1+1] != 1 && flag[aux1+1] != 4){
			return 0;
		}
		if(flag[aux1] == 1 && (flag[aux2] == 1 || flag[aux1] == 2)){
			return 0;
		}
		if((flag[aux1] == 3 && flag[aux2] == 3) || (flag[aux1] == 3 && flag[aux1+1] != 4)){
			return 0;
		}
		if(palavra[aux1] == 40){
			parenteses++;
		}
		if(palavra[aux1] == 41){
			parenteses--;
			if(parenteses < 0){
				return 0;
			}
		}
	}
	if(parenteses != 0){
		return 0;
	}
	return 1;
}

int *vetordeinteiros(char *palavra, int tamanho){
	int *flaginteiros;
	int i ;
	flaginteiros = malloc(sizeof(int)*tamanho);
	for(i=0; i<=tamanho; i++){
		flaginteiros[i]=palavra[i];
	}
	return flaginteiros;
}




struct fila *filainf(int *flr, int tam){
		struct fila *p;
		int i;
		p = createfila();
		for(i=0; i<=tam; i++){
			if(flr[i]!=32){
			queue_fim(p, flr[i]); 
			}
		}
		return p;
}

int funcaoqueretornavetor(int *vet, int n){
	return vet[n];
}

int *infixcomflag(int *vetor, int tamanho){
	int i;
	for(i=0; i<=tamanho; i++){
		if(vetor[i] == 40){
			vetor[i] = 98;
		}
		if(vetor[i] == 41){
			vetor[i] = 99;
		}
		if(vetor[i] == 94){
			vetor[i] = 97;
		}
		if(vetor[i] == 42){
			vetor[i] = 96;
		}
		if(vetor[i] == 47){
			vetor[i] = 95;
		}
		if(vetor[i] == 37){
			vetor[i] = 94;
		}
		if(vetor[i] == 43){
			vetor[i] = 93;
		}
		if(vetor[i] == 45){
			vetor[i] = 92;
		}
		if(vetor[i] == 48){
			vetor[i] = 0;
		}
		if(vetor[i] == 49){
			vetor[i] = 1;
		}
		if(vetor[i] == 50){
			vetor[i] = 2;
		}
		if(vetor[i] == 51){
			vetor[i] = 3;
		}
		if(vetor[i] == 52){
			vetor[i] = 4;
		}
		if(vetor[i] == 53){
			vetor[i] = 5;
		}
		if(vetor[i] == 54){
			vetor[i] = 6;
		}
		if(vetor[i] == 55){
			vetor[i] = 7;
		}
		if(vetor[i] == 56){
			vetor[i] = 8;
		}
		if(vetor[i] == 57){
			vetor[i] = 9;
		}
	}
	return vetor;
}

struct fila *filapos(struct fila *na){
	struct pilha *p;
	struct fila *S;
	int i=0;
	int o;
	int x;
	int retorno;
	int tamanho=0;
	S = createfila();	
	p = create();
	while(na->l->tam != 0){
	x = primeiro(na);
	if(x>=0 && x<=9){
		queue_fim(S, x);
	}
	if(x == 98){ // abre
		push(p,x);
		tamanho--;
	}
	if(x == 99){ // fecha
		while(top(p)!= 98){
			if(top(p) <= 97 && top(p)>=92){ 
				o=top(p);
				pop(p);
				queue_fim(S, o);
			}
		}
		if(top(p) == 98){
				pop(p);
		}
	}
	if(x<98 && x>=92){
		while(1){
			if((x>=top(p) || top(p) == 98)){
				push(p, x);
				tamanho++;
				o=top(p);
				break;
			} 
		}
	}
	dequeue(na);
	}
	for(i=0; i<=tamanho; i++){
		retorno = top(p);
		pop(p);
		queue_fim(S,retorno);
	}
	return S;
}

int caulo (struct fila *E){
	int x;
	int A=0, B=0;
	int resultado;
	struct pilha *p;
	p = create();
	while(1){
		x = primeiro(E);
		if(x >=0 && x<=9){
			push(p, x);
			dequeue(E);
		}
		if(x>=92 && x<=98){
			if(x==96){
				dequeue(E);
				A=top(p);
				pop(p);
				B=top(p);
				pop(p);
				resultado = B * A;
				push(p, resultado);
			}
			if(x==93){
				dequeue(E);
				A=top(p);
				pop(p);
				B=top(p);
				pop(p);
				resultado = B + A;
				push(p, resultado);
			}
			if(x == 97){
				dequeue(E);
				A=top(p);
				pop(p);
				B=top(p);
				pop(p);
				resultado = pow(B, A);
				push(p, resultado);
			}
			if(x==92){
				dequeue(E);
				A=top(p);
				pop(p);
				B=top(p);
				pop(p);
				resultado = B - A;
				push(p, resultado);
			}
			if(x == 95){
				dequeue(E);
				A=top(p);
				pop(p);
				B=top(p);
				pop(p);
				resultado = B / A;
				push(p, resultado);
			}
			if(x == 94){
				dequeue(E);
				A=top(p);
				pop(p);
				B=top(p);
				pop(p);
				resultado = B % A;
				push(p, resultado);
			}
			if(E->l->tam == 1){
				break;
			}
		}
	}
	return resultado;
}

int calculadora(char * expr, int * err){
	struct fila *aux;
	struct fila *aux2;
	int i, tamanho;
	int *flagmainvetor;
	int bemformulado;
	int resultado=0;

	if(expr == NULL){
		*err = 0;
		return 0;
	} 
	tamanho = strlen(expr) - 1;
	flagmainvetor = formular(expr, tamanho);	
	for(i=0; i<=tamanho; i++){
		if(flagmainvetor[i] == 0){
			*err = 0;
			return 0;
		}
	}
	bemformulado = formularpraanexar(flagmainvetor, tamanho, expr);
	if(bemformulado == 0){
		*err = 0;
		return 0;
	}
	else{
		*err = 1;
		flagmainvetor = vetordeinteiros(expr, tamanho);
		flagmainvetor = infixcomflag(flagmainvetor, tamanho);
		aux=filainf(flagmainvetor, tamanho);		
		aux2 = filapos(aux);
		resultado = caulo(aux2);
		return resultado;
	}
}
