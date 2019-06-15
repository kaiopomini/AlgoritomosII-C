#include <stdio.h>
#include <stdlib.h>  // cls();
#include <cstdlib>  // system ("pause");
#include <locale.h>  // pt-br

#define maximoCad 5  // limite de cadastros

struct livro {
	int codigo;
	char titulo[50];
	char autor[50];
	char editora[50];
};


int gerarCodigo(int n, livro *cad){  //gera o proximo numero de cadastro (partindo de 1) que não esteja ocupado no array passado por parametro
	int proxCad = 1;
	int i;
	bool igual = true;
	while(igual == true){
		igual = false;
		for(i=0; i<n; i++){
			if (cad[i].codigo == proxCad){
				igual = true;
			}
		}
		if (igual == true){
			proxCad += 1;
		}
	};
	return proxCad;
};


int main(){
	livro cadastro [maximoCad];
	int count, opc, i, tamanhoVetor;
	bool achou;
	count = 0;
	opc = -1;
	
	tamanhoVetor = sizeof(cadastro)/sizeof(cadastro[0]);
	
	setlocale(LC_ALL, "Portuguese");
	
	while (opc != 0){
		
		printf("-------------------------------\n");
		printf("--------- CADBOOK 1.0 ---------\n");
		printf("-------------------------------\n\n");		
		printf("\n1 - CADASTRAR LIVRO");
		printf("\n2 - LISTAR LIVROS");
		printf("\n0 - SAIR");
		printf("\n\n\nINFORME A OPÇÃO DESEJADA: ");
		scanf(" %d", &opc);
		fflush(stdin);
		system("cls");
		
		if (opc == 0){
			
			printf("OBRIGADO POR USAR O CADBOOK\n\n");
			system("pause");
			
		} else {
			
			if (opc == 1){  // cadastrar
				
				if (count < maximoCad){	 // Máximo de cadastros 
							
					cadastro[count].codigo = gerarCodigo(tamanhoVetor, cadastro);  // gerar novo codigo não repetido, passando como parametro o tamanho do Array e o Array
					fflush(stdin);
					printf("Digite o titulo do livro: ");
					gets(cadastro[count].titulo);
					printf("\nDigite o nome do autor: ");
					gets(cadastro[count].autor);
					printf("\nDigite o nome da editora: ");
					gets (cadastro[count].editora);
					count += 1;  // contador de cadastros realizados
					printf("\n\n\nCadastro realizado com sucesso!!\n\n");
					fflush(stdin);
					system("pause");
		
				} else {
					
					printf("Sistema de cadastro lotado. Não é possível armazenar mais informações!\n\n");
					system("pause");
					
				}
			
			} else {
				if (opc == 2){  // mostrar todos os cadastros
					if (count > 0){
					
						for (i=0; i<count; i++){
										
							printf("CODIGO: %d", cadastro[i].codigo );
							printf("\nTITULO: %s", cadastro[i].titulo);
							printf("\nAUTOR: %s", cadastro[i].autor);						
							printf("\nEDITORA: %s\n\n", cadastro[i].editora);
							
						}
						
					} else {  // erro de lista vazia
						
						printf("Lista vazia!\n\n");
					}
					
					system("pause");
						
				} else {  
				
					printf("ERRO! OPÇÃO INVÁLIDA!\n\n");
					system("pause");
					
				}
			}	
		}
		
		system("cls");
		
	};
	return(0);
}
