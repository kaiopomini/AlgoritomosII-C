#include <stdio.h>
#include <stdlib.h>


void checkNumber(float n){
	if (n<0){
		printf("O numero %.1f e NEGATIVO.", n);
	}
	else{
		if(n==0){
			printf("O numero %.1f e NEUTRO.", n);
		}
		else{
			printf("O numero %.1f e POSITIVO.", n);
		}
		
	}
} 

int main(){
	
	float n;
	printf("Informe um numero: ");
	scanf("%f", &n);
	checkNumber(n);
	
}
