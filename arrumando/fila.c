//Imports
#include <stdio.h> 
#include <stdlib.h> 

//Criando a estrutura
typedef struct NO{
	int data;
	struct NO *proximo;
//alias da estrutura 
}no;

//Variaveis
int contador_tamanho;
int tamanho;
no *temporario;

//Confirma se a fila ta limpa
int limpar(no *fila){
	//Pergunta se o valor e null
	if(fila->proximo == NULL) { 
		return 1;
	} else {
		return 0;
	}	
}

//Mostrar o tamanho da fila
void mostrarFila(no *fila){
	//Confir,a se a fila ta vazia
	if(limpar(fila)){
		//result
		printf("\nFila vazia!\n\n");
	}else{
		//Printa atuais valores da fila
		//Cria valor temporario
		temporario = fila->proximo;
		printf("\n");
		//Confirma que o temporario nao e null, inicia o laco
		while(temporario != NULL){
			//rpt
			printf("%d ", temporario->data);
			//atribui valor ao proximo temporario
			temporario = temporario->proximo;
		}
		printf("\nTamanho da fila: %d\n\n", tamanho);
	}
}

void adicionarFila(no *fila){
	no *new = (no*) malloc(sizeof(no));
	new->proximo = NULL;
	contador_tamanho = contador_tamanho + 1;
	new->data = contador_tamanho;
	&new->data;
	printf("\nTamanho da fila: %d\n\n", tamanho + 1);
	if(limpar(fila)){
		fila->proximo = new;
		tamanho++;	
	}else{
		temporario = fila->proximo;
		while(temporario->proximo != NULL){
			temporario = temporario->proximo; 
		}
		temporario->proximo = new;
		tamanho++;
	}
}

no *deletarFila(no *fila){
	if(limpar(fila)){
		printf("\nApagando lista\n\n");
		return NULL;
	}else{
		temporario = fila->proximo;
		fila->proximo = temporario->proximo; 
		tamanho--;
		return temporario;
	}
}

void limparFila(no *fila){
	if(limpar(fila)){
		printf("\nApagando lista\n\n");
	}else{
		no *proximoNode, *atualNode;
		atualNode = fila->proximo;
		while(atualNode != NULL){
			proximoNode = atualNode->proximo;
			free(atualNode);
			atualNode = proximoNode;
		}
		printf("\nLista Limpa\n\n");
	}
}
   
int main(){
	no *fila = (no*) malloc(sizeof(no));
	if(!fila){
		printf("Sem memoria");
		exit(1);
	}else{
		fila->proximo = NULL;
		tamanho = 0;
		int opcao;
		do{   
			printf("0 -> Sair\n");
			printf("1 -> Mostrar fila\n");
			printf("2 -> Adicionar elemento a fila\n");
			printf("3 -> Remover elemento da fila\n");
			printf("4 -> Limpar a fila\n");
			printf("opcao: "); scanf("%d", &opcao);
			switch(opcao){
				case 1:
					mostrarFila(fila);
					break;
				case 2:
					adicionarFila(fila);
					break;
				case 3:
					temporario = deletarFila(fila);
					if(temporario != NULL) {
						printf("\nElemento removido: %d\n\n", temporario->data);
					}	
					break;
				case 4:
					limparFila(fila);
					fila->proximo = NULL;
					tamanho = 0;
					break;
				default:
					if(opcao != 0) { 
						printf("\nOpcao não é valida!\n\n"); 
					}
					break;
			}   
		} while(opcao != 0);
	}
	return 1;
}
