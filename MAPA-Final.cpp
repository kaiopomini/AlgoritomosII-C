#include <stdio.h>
#include <stdlib.h>  // cls();
#include <cstdlib>  // system ("pause");
#include <locale.h>  // pt-br
#include <string.h>  // trabalhar com string


#define maximoCad 5  // limite de cadastros e Tamanho do array


struct livro {
	int codigo;
	char titulo[50];
	char autor[50];
	char editora[50];
};


int gerarCodigo(int n, livro *cad){  // gera o proximo numero de cadastro (partindo de 1) que não esteja ocupado no array passado por parametro, *funciona se o vetor já estiver preechido
	
	int proxCad = 1;
	int i;
	bool igual = true;
	while(igual){
		igual = false;
		for(i=0; i<n; i++){
			if (cad[i].codigo == proxCad){
				igual = true;
			}
		}
		if (igual){
			proxCad += 1;
		}
	};
	return proxCad;
};


int getCount(int n, livro *cad){  // conta quantas posições estão vazias (0) retornando a quantidade
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


char * getStringOk (char temp[50]){  // descobre se foi informado VAZIO e caso for retorna "Não informado"
	
	if (strcmp(temp, "") == 0) {
		
		strcpy(temp, "Não informado");
		
	}
	
	return temp;
}


int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	struct livro cadastro [maximoCad];
	int count, opc, i, pos;
	char temp[50];
	
	opc = -1;
			
	for (i=0; i<maximoCad; i++){  // atribui 0 em todas as posições de cadastro.codigo para controle de informações, sabendo que todos começam com 0 posso trabalhar para encontrar a posição vazia e a cheia
		cadastro[i].codigo = 0;
	}

	while (opc != 0){
				
		printf("-------------------------------\n");
		printf("--------- CADBOOK BETA --------\n");
		printf("-------------------------------\n\n");		
		printf("\n1 - CADASTRAR LIVRO");
		printf("\n2 - LISTAR LIVROS");
		printf("\n0 - SAIR");
		printf("\n\n\nINFORME A OPÇÃO DESEJADA: ");
		scanf(" %d", &opc);
		fflush(stdin);
		system("cls");
		
		switch (opc){
			
			case 0:  // Sair 
			
				printf("-------------------------------\n");
				printf("------ OBRIGADO POR USAR ------\n");
				printf("--------- CADBOOK BETA --------\n");
				printf("-------------------------------\n\n");
				system("pause");
				
				break;
				
			case 1:  // Cadastrar livro
				
				count = getCount(maximoCad, cadastro); // verifica a quantas posiçoes estão vazias
				
				if (count > 0){	 // o vetor precisa ter espaço vazio  -  LIMITE controlado pela constante.
				
					pos = getNextPos(maximoCad, cadastro);	// verifica qual a próxima posição vazia
					cadastro[pos].codigo = gerarCodigo(maximoCad, cadastro);  // gera novo codigo não repetido, passando como parametro o tamanho do Array e o Array
					fflush(stdin);	
					printf("Digite o titulo do livro: ");					
					gets(cadastro[pos].titulo);
					strcpy(cadastro[pos].titulo, getStringOk(cadastro[pos].titulo));  // chama a função getStringOk que caso seja informado "" (vazio - apenas apertar ENTER) ela retorna "Não Informado"
					printf("\nDigite o nome do autor: ");
					gets(cadastro[pos].autor);
					strcpy(cadastro[pos].autor, getStringOk(cadastro[pos].autor));
					printf("\nDigite o nome da editora: ");
					gets(cadastro[pos].editora);
					strcpy(cadastro[pos].editora, getStringOk(cadastro[pos].editora));
					printf("\n\n\nCadastro realizado com sucesso!!\n\n");
					fflush(stdin);
					system("pause");
		
				} else { // array cheio - limite controlado pela constante
					
					printf("Sistema de cadastro lotado. Não é possível armazenar mais informações!\n\n");
					system("pause");
					
				}
				
				break;
				
			case 2:  // listar livros
				
				count = getCount(maximoCad, cadastro);
					
				if (count < maximoCad){
					
					for (i=0; i<maximoCad; i++){
							
						if (cadastro[i].codigo != 0){  // Só mostra se Código não for 0
										
							printf("CODIGO:   %d", cadastro[i].codigo );
							printf("\nTITULO:   %s", cadastro[i].titulo);
							printf("\nAUTOR:    %s", cadastro[i].autor);						
							printf("\nEDITORA:  %s\n\n", cadastro[i].editora);
							
						}
					}
						
				} else {  // erro de lista vazia
						
					printf("Lista vazia!\n\n");
				}
					
				system("pause");
				
				break;
				
			default:  // erro opção inválida
				
				printf("ERRO! OPÇÃO INVÁLIDA!\n\n");
				system("pause");
					
				break;
		}	
		
		system("cls");
		
	};
	
	return(0);
}
