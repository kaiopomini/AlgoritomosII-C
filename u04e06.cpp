#include <stdio.h>
#include <stdlib.h>

#define T 5

struct aluno{
	char nome[50];
	float nota[4];
	float media;
};

int main(){
	struct aluno alunos[T];
	struct aluno alunoAux;
	float mediaAux;
	for (int i=0; i<T; i++){
		mediaAux=0;
		printf("Informe o nome do aluno %d: ", i+1);
		gets(alunos[i].nome);
		fflush(stdin);
		for(int j=0; j<4; j++){
			printf("Informe a nota do aluno %s do %d bimestre: ", alunos[i].nome, j+1);
			scanf("%f", &alunos[i].nota[j]);
			mediaAux+=alunos[i].nota[j];
			fflush(stdin);
		}
		alunos[i].media = mediaAux/4;
		system("cls");
	}
	
	for (int i=0; i<T-1; i++){
		for (int j=0; j<T-i-1; j++){
			if (alunos[j].media > alunos[j+1].media){
				alunoAux = alunos[j+1];
				alunos[j+1]= alunos[j];
				alunos[j]=alunoAux;
			}
		}
	}
	
	
	for (int i=0; i<T; i++){
		printf("Aluno: %s\nNotas\n", alunos[i].nome);
		for(int j=0; j<4; j++){
			printf("\t%d Bimestre: %.1f\n", j+1, alunos[i].nota[j]);
		}
		printf("Media: %.1f\n", alunos[i].media);
		printf("\n");
	}
}
