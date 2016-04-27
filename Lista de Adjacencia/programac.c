#include <stdio.h>
#include <stdlib.h>


#define TOTAL_NOS 6

struct no {
	int id;
	struct no* prox;
};
typedef struct no No;

No* cria(){
	return NULL;
}

No* inicializa(int id) {
	No* novo = (No*) malloc(sizeof(No));
	novo->id = id;
	novo->prox = NULL;
	return novo;
}

void insere(No* pai, int v){
	No* filho = (No*) malloc(sizeof(No));
	filho->id = v;
	filho->prox = NULL;
	if(pai->prox == NULL) {
		pai->prox = filho;
	} else {
		No* vertice = pai;
		No* temp;
		while(vertice != NULL){
			temp = vertice;
			vertice = vertice->prox;
		}
		temp->prox = filho;
	}
	printf("Inserindo no pai: %d o filho: %d\n", pai->id, v);
}

void printa(No* n){
	printf("%d\n", n->id);
}


void printa_filho(No* n) {

	if(n == NULL)
		return;	
	
	printf("%d ", n->id);
	printa_filho(n->prox);
}

void printa_pai(No* n) {
	if(n == NULL)
		return;
	
	printf("Pai: %d ", n->id);
	printf("Filho(s): ");
	printa_filho(n->prox);
	printf("\n");
}

int main() {
	No** lista = (No**) malloc(sizeof(No*));
	
	int i = 0;
	
	for (i = 0; i < TOTAL_NOS; i++ ){
		lista[i] = inicializa(i+1);		
	}
	
	for (i = 0; i < TOTAL_NOS; i++){
		printa(lista[i]);
	}
	
	insere(lista[0], 2);
	insere(lista[0], 4);
		
	insere(lista[1], 5);
	
	insere(lista[2], 6);
	insere(lista[2], 5);
	
	insere(lista[3], 2);
	
	insere(lista[4], 4);

	insere(lista[5], 6);

	for (i = 0; i < TOTAL_NOS; i++ ){
		printa_pai(lista[i]);
	}	
	return 0;
}











