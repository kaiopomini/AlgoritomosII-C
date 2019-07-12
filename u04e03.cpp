#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char palavra[30], aux;
	int tamanho;
	printf("Informe uma palavra: ");
	scanf("%s", palavra);
	tamanho = strlen(palavra);
	if (tamanho%2 == 1){
		for (int i=0; i<tamanho; i++){
			aux = palavra[i];
			if (!(aux=='a' || aux=='e' || aux=='i' || aux=='o' || aux=='u' || aux=='A' || aux=='E' || aux=='I' || aux=='O' || aux=='U')){
				printf("%c", aux);
			}
		}
	}

	
}
