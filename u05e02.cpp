#include <stdio.h>
#include <stdlib.h>

int somaEntre(int a, int b){
	int soma=0;
	for (int i=a; i<=b; i++){
		soma += i;
	}
	return soma;
}

int main(){
	int inicio, fim;
	
	printf("informe o valor de inicio: ");
	scanf("%d", &inicio);
	printf("informe o valor do fim: ");
	scanf("%d", &fim);
	printf("a soma entre os numeros inteiros entre %d e %d e: %d", inicio, fim, somaEntre(inicio,fim));
}
