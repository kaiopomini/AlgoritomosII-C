#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int main(){
	int a[TAM], aux;
	
	for (int i=0; i<TAM; i++){
		printf("Informe o numero da posicao %d: ", i+1);
		scanf("%d", &a[i]);
		fflush(stdin);
		system("cls");
	}
	for (int i=0; i<TAM-1; i++){
		for (int j=0; j<TAM-i-1; j++){
			if(a[j]<a[j+1]){
				aux = a[j+1];
				a[j+1] = a[j];
				a[j]=aux;
			}
		}
	}
	
	printf("Vetor Organizado:\n\n");
	for (int i=0; i<TAM; i++){
		printf("%d", a[i]);
		if (i<TAM-1){
			printf(" - ");
		}
	}
	
}
	

