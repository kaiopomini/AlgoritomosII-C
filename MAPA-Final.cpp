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


int gerarCodigo(int n, livro *cad){  // gera o proximo numero de cadastro (partindo de 1) que n�o esteja ocupado no array passado por parametro, *funciona se o vetor j� estiver preechido
	
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


int getCount(int n, livro *cad){  // conta quantas posi��es est�o vazias (0) retornando a quantidade
	int count0 = 0;
	int i;
	
	for (i=0; i < n; i++){ 
		if (cad[i].codigo == 0){
			count0 += 1;
		}
	}
	
	return count0;
}


int getNextPos(int n, livro *cad){  // Descobre qual � a proxima posi��o vazia(0) retornando sua posi��o
	int nextPos, i;
		
	for (i=0; i < n; i++){ 
		if (cad[i].codigo == 0){
			nextPos = i;
			break;
		}
	}
	
	return nextPos;
}


char * getStringOk (char temp[50]){  // descobre se foi informado VAZIO e caso for retorna "N�o informado"
	
	if (strcmp(temp, "") == 0) {
		
		strcpy(temp, "N�o informado");
		
	}
	
	return temp;
}


int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	struct livro cadastro [maximoCad];
	int count, opc, i, pos;
	char temp[50];
	
	opc = -1;
			
	for (i=0; i<maximoCad; i++){  // atribui 0 em todas as posi��es de cadastro.codigo para controle de informa��es, sabendo que todos come�am com 0 posso trabalhar para encontrar a posi��o vazia e a cheia
		cadastro[i].codigo = 0;
	}

	while (opc != 0){
				
		printf("-------------------------------\n");
		printf("--------- CADBOOK BETA --------\n");
		printf("-------------------------------\n\n");		
		printf("\n1 - CADASTRAR LIVRO");
		printf("\n2 - LISTAR LIVROS");
		printf("\n0 - SAIR");
		printf("\n\n\nINFORME A OP��O DESEJADA: ");
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
				
				count = getCount(maximoCad, cadastro); // verifica a quantas posi�oes est�o vazias
				
				if (count > 0){	 // o vetor precisa ter espa�o vazio  -  LIMITE controlado pela constante.
				
					pos = getNextPos(maximoCad, cadastro);	// verifica qual a pr�xima posi��o vazia
					cadastro[pos].codigo = gerarCodigo(maximoCad, cadastro);  // gera novo codigo n�o repetido, passando como parametro o tamanho do Array e o Array
					fflush(stdin);	
					printf("Digite o titulo do livro: ");					
					gets(cadastro[pos].titulo);
					strcpy(cadastro[pos].titulo, getStringOk(cadastro[pos].titulo));  // chama a fun��o getStringOk que caso seja informado "" (vazio - apenas apertar ENTER) ela retorna "N�o Informado"
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
					
					printf("Sistema de cadastro lotado. N�o � poss�vel armazenar mais informa��es!\n\n");
					system("pause");
					
				}
				
				break;
				
			case 2:  // listar livros
				
				count = getCount(maximoCad, cadastro);
					
				if (count < maximoCad){
					
					for (i=0; i<maximoCad; i++){
							
						if (cadastro[i].codigo != 0){  // S� mostra se C�digo n�o for 0
										
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
				
			default:  // erro op��o inv�lida
				
				printf("ERRO! OP��O INV�LIDA!\n\n");
				system("pause");
					
				break;
		}	
		
		system("cls");
		
	};
	
	return(0);
}
