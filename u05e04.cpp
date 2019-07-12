#include <stdio.h>
#include <stdlib.h>

int somatorioPar(int n){
	int soma = 0;
	for (int i=1; i<=n; i++){
		soma+=i*2;
	}
	return soma;
}

int main(){
	int n;
	printf("informe quantos numeros PARES quer somar: ");
	scanf("%d", &n);
	printf("O somatorio dos %d primeiros numeros pares e %d", n, somatorioPar(n));
}
