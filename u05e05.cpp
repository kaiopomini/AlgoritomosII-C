#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 30

int countVogais(char nome[TAM]){
	int count = 0;
	char c[TAM];
	for (int i=0; i<TAM; i++){ // faz uma copia da string passando ela em UPPERCASE para nao modificar a original
		c[i] = toupper(nome[i]);
	} 
	
	for (int i=0; i<strlen(c); i++){
		if (c[i] == 'A' || c[i] == 'E' || c[i] == 'I' || c[i] == 'O' || c[i] == 'U' ){
			count++;
		}
	}
	return count;
}

int main(){
	
	char nome[TAM];
	printf("informe o um nome: ");
	scanf("%s", nome);
	printf("o nome %s tem %d vogais", nome, countVogais(nome));
	
}
