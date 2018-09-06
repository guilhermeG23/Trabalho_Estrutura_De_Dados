//imports
#include <stdio.h>
#include <stdlib.h>

//Criando uma fila basica

//Variaveis
int Fila[100]; //Array
int Contador = 0; //Contador
int Contador_Do_Primeiro = 0; //Contador do valor a frente da fila
int Atual; //Atual valor e o ultimo da fila 

//Criar a fila
int Fila_Criar() {
	Atual++; //Incrementa o atual, faz a fila ficar mais longa
	Contador_Do_Primeiro = Contador; //O mesmo vale pro contador
	Fila[Contador] = Atual; //Aqui adicionamos o valor do array que e o ultimo da fila
}

//Fila vazia
int Fila_Vazia() {
	//Confirma se a fila esta vazia
	if(Contador == 0) {
		return 0;
	} else {
		return 1;
	}
}

//Fila Cheia
int Fila_Cheia() {
	//Confirma se a fila esta cheia
	if(Contador == 99) {
		return 1;
	} else {
		return 0;
	}
}

//Inserir na fila
int Fila_Adicionar() {
	//Se nao esta cheio, continua a aumentar a fila
	if(Fila_Cheia() == 0) {
		Contador++; //Incremento do contador
		Atual++; //Incremento do valor atual
		Fila[Contador] = Atual; //Atribuindo valor do ultimo da fila
		return 0;
	//Se esta cheio, ele manda a mensagem
	} else {
		printf("Fila Cheia!\n");
		return 1;
	}	
}

//Enchendo a fila
//preenche todos os valores restantes da fila
int Fila_Veloz() {
    //confirma se a fila ta cheia
	if(Fila_Cheia() == 0) {
        //contador para saber como ta fila ta e preenchendo os valores
		for(;Contador < 99; Contador++) {
			Atual++; //incrementado
			Fila[Contador] = Atual; //array para armazenar o valor
		}
    //mensagem de que a fila ta cheia
	} else {
		printf("Fila Cheia!\n");
		return 1;
	}
}

//Deletar Fila
int Fila_Deletar() {
	//Confirma se a fila esta vazia antes
	//Se tem valor na fila, manda a mensagem
	if(Fila_Vazia() == 0) {
		printf("Fila esta vazia!\n");
		return 1;
	//Caso tenha valor
	//Ele incrementa o valor da fila, assim sabe o valor do primeiro lugar
	} else {
		Contador_Do_Primeiro++;
		return 0;
	}
}

//Print
//imprimi o estado atual sa fila, o primeiro e o ultimo valor
void Fila_Status() {
	printf("\n");
	printf("Primeiro da fila: Fila[%d], Valor[%d]\n", Contador_Do_Primeiro, Fila[Contador_Do_Primeiro]);
	printf("Ultimo da fila: Fila[%d], Valor[%d]\n", Contador, Atual);
	printf("\n");
}

//Funcao principal
//usando os metodos para criar um exemplo
int main() {
	Fila_Criar();
	Fila_Status();
	Fila_Adicionar();
	Fila_Status();
	Fila_Adicionar();
	Fila_Status();
	Fila_Adicionar();
	Fila_Status();
	Fila_Deletar();
	Fila_Status();
	Fila_Veloz();
	Fila_Status();
}
