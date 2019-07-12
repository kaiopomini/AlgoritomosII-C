#include <stdio.h>
#include <stdlib.h>

float converteDolar(float cotacao, float valorReais){
	return valorReais/cotacao;
}


int main(){
	float cotacao, valorReais;
	printf("informe o valor da cotacao do dolar: ");
	scanf("%f", &cotacao);
	printf("informe a quantidade de reais a ser convertida: ");
	scanf("%f", &valorReais);
	printf("R$%.2f sao equivalentes a U$%.2f", valorReais, converteDolar(cotacao, valorReais));
}
