#include <stdio.h>
#include <stdlib.h>

#define T 30

struct cadastro {
	char nome[50];
	char telefone[20];
	char email[30];
};

int main(){
	struct cadastro cad[T];
	for (int i=0; i<T; i++){
		printf("Nome: ");
		gets(cad[i].nome);
		printf("Telefone: ");
		gets(cad[i].telefone);
		printf("Email: ");
		gets(cad[i].email);
		fflush(stdin);
		system("cls");
	}
	for (int i=0; i<T; i++){
		printf("%s - %s - %s\n", cad[i].nome, cad[i].telefone, cad[i].email);
	}
}
