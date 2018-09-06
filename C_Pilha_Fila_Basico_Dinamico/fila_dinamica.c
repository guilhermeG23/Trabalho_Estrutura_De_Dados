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

//Adicionando valor a fila de forma automatica
void adicionarFila(no *fila){
    //Criando a alocação de memoria para o novo valor
	no *new = (no*) malloc(sizeof(no));
    //Fim da fila
	new->proximo = NULL;
    //Incremento do contador da fila e adicionando o valor
	contador_tamanho++;
    //Adicionando o valor a fila
	new->data = contador_tamanho;
    //Criando a referencia de memoria
	&new->data;
    //mensagem	
    printf("\nTamanho da fila: %d\n\n", tamanho + 1);
    //Confirma se a fila esta limpa	
    if(limpar(fila)){
        //Fim da fila
		fila->proximo = new;
        //incrementendo do tamanho da fila
		tamanho++;	
	}else{
        //copiando valor para o temporario
		temporario = fila->proximo;
        //laço		
        while(temporario->proximo != NULL){
            //Confirmando se o valor não é null para armazenar no temporario
			temporario = temporario->proximo; 
		}
        //copiando o valor de proximo para a referencia temporaria
		temporario->proximo = new;
        //incremento   
		tamanho++;
	}
}

//deletar valor da fila
no *deletarFila(no *fila){
    //Decisão
    //Fila esta vazia   
	if(limpar(fila)){
        //mensagem
		printf("\nFila vazia\n\n");
        //retorno		
        return NULL;
	}else{
        //Cria variavel para armazenar temporariamente valor a ser apagado
        //Seguranca
		temporario = fila->proximo;
        //substitui o valor que o espaço ocupava
		fila->proximo = temporario->proximo;
        //Diminui a variavel que printa o tamanho da fila
		tamanho--;
        //Confirma se a fila não esta deletando um NULL(vazia)
        if(temporario != NULL) {
		    printf("\nElemento removido: %d\n\n", temporario->data);
		}
        //retorno
		return NULL;
	}
}

//limpar fila
void limparFila(no *fila){
    //Confirma se a fila esta vazia
    if(limpar(fila)){
        //Mensagem de alerta
    	printf("\nFila vazia!\n\n");
	}else{
        //criando o no		
        no *proximoNode, *atualNode;
        //no atual
		atualNode = fila->proximo;
        //laço para saber se é o fim da fila
		while(atualNode != NULL){
            //diferente de fim, você começa a limpar ela
			proximoNode = atualNode->proximo;
            //tirando a referencia de memoria 
			free(atualNode);
            //adicionando a referencia do atual da fila
			atualNode = proximoNode;
		}
        //mensagem
		printf("\nFila Limpa\n\n");
	}
}
  
//função principal
int main(){
    //Alocando memoria do no para criar a referencia fila
	no *fila = (no*) malloc(sizeof(no));
    //decisao
	if(!fila){
        //Caso de erro, falta de memoria na maquina
		printf("Sem memoria");
        //saia da aplicação
		exit(1);
	}else{
        //Ultimo da fila
		fila->proximo = NULL;
        //Zerando 		
        tamanho = 0;
        //variavel de opções 
		int opcao;
        //Do-while de repetição do menu 
		do{  
            //opcoes
			printf("0 -> Sair\n");
			printf("1 -> Mostrar fila\n");
			printf("2 -> Adicionar elemento a fila\n");
			printf("3 -> Remover elemento da fila\n");
			printf("4 -> Limpar a fila\n");
			printf("opcao: "); scanf("%d", &opcao);
            //Case de opções
			switch(opcao){
				case 1:
                    //mostrar a fila					
                    mostrarFila(fila);
					break;
				case 2:
                    //adicionando valor a fila
					adicionarFila(fila);
					break;
				case 3:
                    //Deleta valor da fila					
                    temporario = deletarFila(fila);	
					break;
				case 4:
                    //limpando a fila
					limparFila(fila);
					fila->proximo = NULL;
					tamanho = 0;
					break;
				default:
                    //valor incorreto
					if(opcao != 0) { 
						printf("\nOpcao não é valida!\n\n"); 
					}
					break;
			}
        //Laço para garantir a repetição
		} while(opcao != 0);
	}
    //retorno do principal
	return 1;
}
