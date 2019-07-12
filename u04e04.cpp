#include <stdio.h>
#include <stdlib.h>

int main(){
	char palavra[30];
	int tamanho;
	printf("Informe uma palavra: ");
	scanf("%s", palavra);
	printf("Informa a quantidade de vezes a repetir: ");
	scanf("%d", &tamanho);
	
	printf("\n\n");
	
	for (int i=0; i<tamanho; i++){
		printf(palavra);
		if (i<tamanho-1){
			printf(", ");
		}
		else{
			printf(".");
		}
	}
}
