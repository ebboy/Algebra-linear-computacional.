#include <stdio.h>
#include <math.h>

int main(){
	float matriz[2][2],raiz[2];
	int i,j;
	for(i=0;i<2;i++){ // for zerando os vetores criados.
		raiz[i] = 0;
		for(j=0;j<2;j++){
			matriz[i][j] = 0;
		}
	}
	
	for(i=0;i<2;i++){ // for recebendo as entradas da matriz.
		for(j=0;j<2;j++){
			printf("Insira o valor da posição [%d][%d]",i+1,j+1);
			scanf("%f",&matriz[i][j]);
		}
	
	}
	// POLINÔMIO CARACTERÍSTICO abaixo
	// lambda² -(a11 + a22).lambda +(a11.a22-a12.a21)
	// Resolução:
	 raiz[0] = ((matriz[0][0] + matriz[1][1]) + sqrt(pow(matriz[0][0] + matriz[1][1],2) - 4*(1*(matriz[0][0]*matriz[1][1] - matriz[0][1]*matriz[1][0]))))/2;
	 raiz[1] = ((matriz[0][0] + matriz[1][1]) - sqrt(pow(matriz[0][0] + matriz[1][1],2) - 4*(1*(matriz[0][0]*matriz[1][1] - matriz[0][1]*matriz[1][0]))))/2;

	printf("Raiz 1 = %f \n", raiz[0]); // Imprime a primeira raíz.
	printf("Raiz 2 = %f \n", raiz[1]); // Imprime a segunda raíz.
}
