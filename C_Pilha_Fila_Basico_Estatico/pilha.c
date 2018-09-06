//imports
#include <stdio.h>
#include <stdlib.h>

//Pilha basica em C
//Segue o mesmo exemplo de fila

//Variaveis do ambiente
int Pilha[100]; 
int Contador = 0;
int Anterior;
int Topo;

//Funcoes em C
//Criar uma pilha
int Pilha_Criar() {
	//Setando os valores iniciais de uma pilha
	Topo = 1; //O topo 
	Pilha[Contador] = Topo; // colocação do topo na fila
	return 0;
}

//Confirmar se uma pilha possui um valor
int Pilha_Vazia() {
	//Confirma se o contador ainda esta zerado
	if(Contador == 0) {
		return 1;
	} else {
		return 0;
	}
}

//Printa o valor atual de uma pilha
void Pilha_Atual() {
	printf("Pilha[%d] = Valor: %d \n", Contador, Topo);
}

//Confirma se uma pilha ta cheia
int Pilha_Cheia() {
	//Confirma se o contador chegou no limite
	if(Contador == 99) {
		return 1;
	} else {
		return 0;
	}
}

//Adicionando valor em uma pilha
int Pilha_Registrando_valor() {
	//Confirma se nao ta cheia
	if(Pilha_Cheia() == 0) {
		//Valor antigo de BK caso delete
		Anterior = Topo;
		//Icrementa o valor do topo
		Topo++;
		//Incrementa o contador
		Contador++;
		//Atribui o valor da pilha
		Pilha[Contador] = Topo;
		//Tudo de certo
		return 0;
	} else {
		//Caso a pilha estiver cheia
		printf("Pilha lotada\n");
		return 1;
	}
}

//Encher a pilha rapidamente
int Pilha_Veloz() {
	//Confirma se nao ta cheia
	if(Pilha_Cheia() == 0) {
		for(;Contador < 99; Contador++) {
			Anterior = Topo;
			Pilha[Contador] = Topo;
			Topo++;
		}
		//Tudo de certo
		return 0;
	} else {
		//Caso a pilha estiver cheia
		printf("Pilha lotada\n");
		return 1;
	}
}

//Deletar valor da pilha
int Pilha_Deletar() {
	//Confirma se a pilha esta vazia
	if(Pilha_Vazia() == 0) {
		//Diminui o contador
		Contador--;
		//Retorna o antigo topo
		Topo = Anterior;
		//COntador diminuido = antigo topo
		Pilha[Contador] = Anterior;
		//Tudo deu certo
		return 0;
	} else {
		//Pilha esta vazia
		printf("Pilha esta vazia\n");
		return 1;
	}
}

//Funcao principal
//usando os metodos para criar o exemplo
int main() {
	Pilha_Criar();
	Pilha_Atual();
	Pilha_Registrando_valor();
	Pilha_Atual();
	Pilha_Registrando_valor();
	Pilha_Atual();
	Pilha_Registrando_valor();
	Pilha_Atual();
	Pilha_Registrando_valor();
	Pilha_Atual();
	Pilha_Deletar();
	Pilha_Atual();
	Pilha_Veloz();
	Pilha_Atual();
	Pilha_Deletar();
	Pilha_Atual();
	return 0;
}
