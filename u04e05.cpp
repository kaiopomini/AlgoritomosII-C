#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define T 5

int main(){
	int mat1[T][T], mat2[T][T];
	
	srand(time(NULL));
	
	for (int i=0; i<T; i++){
		for (int j=0; j<T; j++){
			mat1[i][j] = rand() % 10;
			mat2[i][j] = rand() % 10;
		}
	}
	printf("Matriz A\n");
	for (int i=0; i<T; i++){
		for (int j=0; j<T; j++){
			printf("%d ", mat1[i][j]);
		}
		printf("\n");
	}
	printf("\nMatriz B\n");
	
	for (int i=0; i<T; i++){
		for (int j=0; j<T; j++){
			printf("%d ", mat2[i][j]);
		}
		printf("\n");
	}
	
	printf("\nMatriz (A-B)\n");
	
	for (int i=0; i<T; i++){
		for (int j=0; j<T; j++){
			printf("%d ", mat1[i][j] - mat2[i][j]);
		}
		printf("\n");
	}
	
		printf("\nMatriz (A+B)\n");
	
	for (int i=0; i<T; i++){
		for (int j=0; j<T; j++){
			printf("%d ", mat1[i][j] + mat2[i][j]);
		}
		printf("\n");
	}
	
}
