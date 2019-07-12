#include <stdio.h>
#include <stdlib.h>

#define T 20

struct livros{
	char titulo[50]; 
	char autor[50];
	char editora[50];
	char edicao[50];
	int ano; 
};

int main(){
	struct livros livro[T];
	for (int i=0; i<T; i++){
		printf("Titulo: ");
		gets(livro[i].titulo);
		printf("Autor: ");
		gets(livro[i].autor);
		printf("editora: ");
		gets(livro[i].editora);
		printf("edicao: ");
		gets(livro[i].edicao);
		printf("Ano: ");
		scanf("%d", &livro[i].ano);
		fflush(stdin);
		system("cls");
	}
	for (int i=0; i<T; i++){
		printf("%s - %s - %s - %s - %d\n", livro[i].titulo, livro[i].autor, livro[i].editora, livro[i].edicao, livro[i].ano);
	}
}
