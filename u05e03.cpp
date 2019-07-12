#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int charCheck(char c){
	c = toupper(c);
	if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
		return 0;
	} 
	else {
		return 1;
	}
}


int main(){
	char letra;
	int resposta;
	
	printf("informe uma letra do alfabeto: ");
	scanf("%c", &letra);
	printf("%d", charCheck(letra));
	
}
