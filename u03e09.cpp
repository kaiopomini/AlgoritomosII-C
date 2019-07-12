#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char nome[30];
	float largura, comprimento, area;
	area = 0;
	do{
		printf("Informe o nome do comodo ou FIM para encerrar: ");
		gets(nome);
		if (strcmp(nome, "FIM")!=0){
			printf("largura: ");
			scanf("%f", &largura);
			printf("comprimento: ");
			scanf("%f", &comprimento);
			area+=comprimento*largura;
			fflush(stdin);
		}
		system("cls");
	}while (strcmp(nome, "FIM")!=0);
	printf("Sua casa tem %.2fm2 de area total", area);
	
}
