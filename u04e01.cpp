#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int main(){
	int a[TAM], b[TAM], c[TAM];
	char letra = 'a';
	
	for (int i = 0; i<TAM; i++){
		printf("Informe o valor da posicao %d do vetor A: ", (i+1));
		scanf("%d", &a[i]);
		fflush(stdin);
		system("cls");
	}
	for (int i = 0; i<TAM; i++){
		printf("Informe o valor da posicao %d do vetor B: ", (i+1));
		scanf("%d", &b[i]);
		fflush(stdin);
		system("cls");
	}
	for (int i = 0; i<TAM; i++){
	c[i] = a[i] - b[i];	
	} 
	printf("VETOR A:\n\n");
	
	for (int i = 0; i<TAM; i++){
		printf("%d", a[i]);
		if (i<TAM-1){
			printf(" - ");
		}
	}
	printf("\n\nVETOR B:\n\n");
	for (int i = 0; i<TAM; i++){
		printf("%d", b[i]);
		if (i<TAM-1){
			printf(" - ");
		}
	} 
	printf("\n\nDiferenca (vetor A-B):\n\n");
	for (int i = 0; i<TAM; i++){
		printf("%d", c[i]);
		if (i<TAM-1){
			printf(" - ");
		}
	}


	
}
