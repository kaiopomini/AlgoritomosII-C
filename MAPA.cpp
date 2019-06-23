#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 

#define MAX 5  


struct livro {
	int codigo;
	char titulo[50];
	char autor[50];
	char editora[50];
};


int main(){
	livro cadastro [MAX];
	int count, opc, i;
	bool achou;
	count = 0;
		
	setlocale(LC_ALL, "Portuguese");
	
	do{
		
		printf("1 - CADASTRAR LIVRO");
		printf("\n2 - LISTAR LIVROS");
		printf("\n0 - SAIR");
		printf("\n\n\nINFORME A OPÇÃO DESEJADA: ");
		scanf(" %d", &opc);
		fflush(stdin);
		system("cls");
		
		switch (opc){
			
			case 0:
				printf("TENHA UM BOM DIA!!\n\n");
				system("pause");
				break;
				
			case 1:  	
				if (count < MAX){	 				
					cadastro[count].codigo = count+1;
					fflush(stdin);
					printf("Digite o titulo do livro: ");
					gets(cadastro[count].titulo);
					printf("\nDigite o nome do autor: ");
					gets(cadastro[count].autor);
					printf("\nDigite o nome da editora: ");
					gets (cadastro[count].editora);
					count += 1;  
					printf("\n\n\nCadastro realizado com sucesso!!\n\n");
					fflush(stdin);
					system("pause");
			
				} else {	
					printf("Sistema de cadastro lotado. Não é possível armazenar mais informações!\n\n");
					system("pause");
						
				}

				break;
			
			case 2:
				if (count > 0){	
					for (i=0; i<count; i++){						
						printf("CODIGO: %d", cadastro[i].codigo );
						printf("\nTITULO: %s", cadastro[i].titulo);
						printf("\nAUTOR: %s", cadastro[i].autor);						
						printf("\nEDITORA: %s\n\n", cadastro[i].editora);
								
					}
							
				} else {  		
					printf("Lista vazia!\n\n");
					
				}
						
				system("pause");
				break;
				
			default:			
					printf("ERRO! OPÇÃO INVÁLIDA!\n\n");
					system("pause");
						
				break;					
			
		}
		
		system("cls");
		
	} while (opc != 0);
	
	return(0);
}
