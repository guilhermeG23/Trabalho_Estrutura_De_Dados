#include <stdio.h>
#include <stdlib.h>

struct estrutura {
	struct estrutura *valor;
}

void criar_pilha() {
	for(int i = 0; i < 100; i++) {
		estrutura *valor = malloc(sizeof(i));
		*valor = %i;
		printf("%d = %i\n", i, *valor);
	}
}

int main(void) {
	criar_pilha();
	return 0;
}