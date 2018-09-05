#include <stdio.h>
#include <stdlib.h>
//Definir o limite de uma contante
//0 a 99 posições
#define MAXTAM 100
//Caracteristica da pilha
//Inserção, leitura e delete é feita no topo

//Limitado a valores inteiros
typedef struct  {
	int Item[MAXTAM];
	int Topo;
} TPilha;

//Iniciar a pilha
//Mesma logica do setter e getter
//Insert não precisa retornar nada
//*p ponteiro P
void TPilha_Inicia(TPilha *p) {
	//Nivel de acesso aos dados
	//Iniciar a pilha
	p->Topo = -1;
}

//Verificar se a pilha esta vazia, usando o ponteiro
int TPilha_Vazia(TPilha *p) {
	//Verifica se o topo ta vazio
	if(p->Topo == -1) {
		//Pilha vazia
		return 1;
	} else {
		//Pilha não está vazia
		return 0;
	}
}

//Verificar se a pilha esta cheia
int TPilha_Lotada(TPilha *p) {
	//Indice inicia = 0
	//MAX = indice 99
	if(p->Topo == MAXTAM -1) {
		//Caso tiver cheio ele da o return
		return 1;
	} else {
		//Não está cheia
		return 0;
	}
}

//Ponteiros começão do zero a contagem e inserção
// 1 2 3 4 5
// 0 1 2 3 4

//Inserir valores
void TPilha_Inserir(TPilha *p, int x) {
	//Antes de inserir verifica se existe valor no espaço do vetor
	//Verifica se tem espaço para inserir valores
	if(TPilha_Lotada(p) == 1) {
		printf("ERRO: Pilha cheia!\n");
	} else {
		//Inserir na posição a frente
		//Inserir na proxima posição vaga e está se torna o topo do vetor
		p->Topo++;
		//Insere o valor na posição do topo
		p->Item[p->Topo] = x;

		//EX:
		// 1 2 x Valores
 		// 0 1 2 Posicoes
	}
} 

//Remover valores de uma pilha
int TPilha_Remover(TPilha *p) {
	//Variavel auxiliar que so existe neste trecho de code
	int aux;
	if(TPilha_Vazia(p) == 1) {
		printf("ERRO: Pilha vazia\n"); 
	} else {
		//Referenciando e armazenando o valor
		aux = p->Item[p->Topo];
		//Como removemos o topo, a posição antes dele se torna o novo topo
		p->Topo--;
		return aux;
	}
}

//Função principal
int main() {
	//Referencia a posição de memoria
	//Ponteiro
	TPilha *p = (TPilha*)malloc(sizeof(TPilha));

	//Iniciando a pilha
	TPilha_Inicia(p);

	//Inserindo o valor
	TPilha_Inserir(p, 1);
	TPilha_Inserir(p, 2);
	TPilha_Inserir(p, 3);

	//Printando os atuais valores
	printf("==========================================================================\n");
	printf("Topo da operação\n");
	printf("Valor do topo atual: %d sua posição: %d\n", p->Item[p->Topo], p->Topo);
	printf("==========================================================================\n");
	//Criando uma variavel auxiliar
	int aux;

	//Remover valores
	aux = TPilha_Remover(p);

	printf("Deletando valores\n");

	//printado o valor deletado
	printf("Valor deletado: %d, posição: %d\n", aux, p->Topo+1);

	//Remover valores
	aux = TPilha_Remover(p);
	//printado o valor deletado
	printf("Valor deletado: %d, posição: %d\n", aux, p->Topo+1);

	//Remover valores
	aux = TPilha_Remover(p);
	//printado o valor deletado
	printf("Valor deletado: %d, posição: %d\n", aux, p->Topo+1);


	printf("==========================================================================\n");
	//Simulando o erro de pilha vazia por se esgotar os valores

	//Remover valores
	//aux = TPilha_Remover(p);
	//printado o valor deletado
	//printf("Valor deletado: %d, posição: %d\n", aux, p->Topo+1);

	//Printando o atual topo
	printf("Vetor zerado\n");
	printf("Valor do topo atual: %d sua posição: %d\n", p->Item[p->Topo], p->Topo);
	printf("==========================================================================\n");
	//Finaliza a estrutura
	return 0;
}
