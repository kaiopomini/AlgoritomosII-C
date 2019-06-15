#include <stdio.h>
#include <stdlib.h>  // cls();
#include <cstdlib>  // system ("pause");
#include <locale.h>  // pt-br



#define maximoCad 5  // limite de cadastros e Tamanho do array

struct livro {
	int codigo;
	char titulo[50];
	char autor[50];
	char editora[50];
};


int gerarCodigo(int n, livro *cad){  // gera o proximo numero de cadastro (partindo de 1) que não esteja ocupado no array passado por parametro
	
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

int getCount(int n, livro *cad){  // descobre quantas posições estão vazias (0) retornando a quantidade
	int count0 = 0;
	int i;
	
	for (i=0; i < n; i++){ 
		if (cad[i].codigo == 0){
			count0 += 1;
		}
	}
	
	return count0;
}

int getNextPos(int n, livro *cad){  // Descobre qual é a proxima posição vazia(0) retornando sua posição
	int nextPos, i;
		
	for (i=0; i < n; i++){ 
		if (cad[i].codigo == 0){
			nextPos = i;
			break;
		}
	}
	
	return nextPos;
}


int main(){
	livro cadastro [maximoCad];
	int count, opc, i, pos;
	
	opc = -1;
			
	setlocale(LC_ALL, "Portuguese");
	
	for (i=0; i<maximoCad; i++){  // atribui 0 em todas as posições de cadastro.codigo para controle de informações, exemplo 0 = deletar
		cadastro[i].codigo = 0;
	}

	
	while (opc != 0){
				
		
		printf("-------------------------------\n");
		printf("--------- CADBOOK 1.1 ---------\n");
		printf("-------------------------------\n\n");		
		printf("\n1 - CADASTRAR LIVRO");
		printf("\n2 - LISTAR LIVROS");
		printf("\n0 - SAIR");
		printf("\n\n\nINFORME A OPÇÃO DESEJADA: ");
		scanf(" %d", &opc);
		fflush(stdin);
		system("cls");
		
		switch (opc){
			
			case 0:
				
				printf("OBRIGADO POR USAR O CADBOOK\n\n");
				system("pause");
				
				break;
				
			case 1:
				
				count = getCount(maximoCad, cadastro); // verifica a quantas posiçoes estão vazias
				
				if (count > 0){	 // o vetor precisa ter espaço vazio  -  LIMITE controlado pela constante.
					pos = getNextPos(maximoCad, cadastro);	// verifica qual a próxima posição vazia
					cadastro[pos].codigo = gerarCodigo(maximoCad, cadastro);  // gera novo codigo não repetido, passando como parametro o tamanho do Array e o Array
					fflush(stdin);
					printf("Digite o titulo do livro: ");
					gets(cadastro[pos].titulo);
					printf("\nDigite o nome do autor: ");
					gets(cadastro[pos].autor);
					printf("\nDigite o nome da editora: ");
					gets (cadastro[pos].editora);
					
					printf("\n\n\nCadastro realizado com sucesso!!\n\n");
					fflush(stdin);
					system("pause");
		
				} else {
					
					printf("Sistema de cadastro lotado. Não é possível armazenar mais informações!\n\n");
					system("pause");
					
				}
				
				break;
				
			case 2:
				
				count = getCount(maximoCad, cadastro);
					
				if (count < maximoCad){
					
					for (i=0; i<maximoCad; i++){
							
						if (cadastro[i].codigo != 0){
										
							printf("CODIGO: %d", cadastro[i].codigo );
							printf("\nTITULO: %s", cadastro[i].titulo);
							printf("\nAUTOR: %s", cadastro[i].autor);						
							printf("\nEDITORA: %s\n\n", cadastro[i].editora);
							
						}
					}
						
				} else {  // erro de lista vazia
						
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
		
	};
	
	return(0);
}
