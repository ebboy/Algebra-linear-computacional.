#include <stdio.h>
#include <math.h>

int main(void){
	int linhasA, colunasA, linhasB, colunasB;
	int i, j;

	//Lê quantas linhas a matriz A tem
	printf("Digite o numero de linhas da matriz A:\n");
	scanf("%d", &linhasA);
	//Lê quantas colunas a matriz A tem
	printf("Digite o numero de colunas da matriz A:\n");
	scanf("%d", &colunasA);
	//Lê quantas linhas a matriz B tem
	printf("Digite o numero de linhas da matriz B:\n");
	scanf("%d", &linhasB);
	//Lê quantas colunas a matriz B tem
	printf("Digite o numero de colunas da matriz B:\n");
	scanf("%d", &colunasB);

	float matrizA[linhasA][colunasA];
	float matrizB[linhasB][colunasB];
	float norma1A = 0, normainfA = 0, frobeniusA = 0;
	float norma1B = 0, normainfB = 0, frobeniusB = 0;
	float compnorma1, compnormainf;
	float distancia;

	// Lê a matriz A
	for(i=0;i<linhasA;i++){
		for(j=0;j<colunasA;j++){
			printf("Digite o valor em matrizA[%d][%d]:\n", i, j);
			scanf("%f", &matrizA[i][j]);
		}
	}
	// Lê a matriz B
	for(i=0;i<linhasB;i++){
		for(j=0;j<colunasB;j++){
			printf("Digite o valor em matrizB[%d][%d]:\n", i, j);
			scanf("%f", &matrizB[i][j]);
		}
	}

	// Calcula a norma 1 e de frobenius da matrizA
	// compnorma1 e compnormainf são variáveis usadas para passar valores
	for(j=0;j<colunasA;j++){ // contado todas as linhas de cada coluna
		compnorma1 = 0;
		for(i=0;i<linhasA;i++){
			compnorma1 = compnorma1 + sqrt(pow(matrizA[i][j],2)); // acrescenta ||Aij|| à compnorma1

			frobeniusA = frobeniusA + pow(matrizA[i][j],2); // acrescenta Aij² à frobeniusA
		}
		if(compnorma1 > norma1A){
			norma1A = compnorma1; // define norma1A como compnorma1(que é a soma dos modulos de valores de A) caso compnorma1 seja maior que norma1A
		}
	}
	frobeniusA = sqrt(frobeniusA); // define frobeniusA como a raiz quadrada da soma dos quadrados dos valores de Aij

	// Calcula a norma infinito da matrizA
	for(i=0;i<linhasA;i++){ // desta vez é contado todos as colunas de cada linha
		compnormainf = 0;
		for(j=0;j<colunasA;j++){
			compnormainf = compnormainf + sqrt(pow(matrizA[i][j],2)); // acrescenta ||Aij|| à compnormainf
		}
		if(compnormainf > normainfA){
			normainfA = compnormainf; // define normainfA como compnormainf(que é a soma dos modulos de valores de A) caso compnorma1inf seja maior que normainfA
		}
	}

	// Calcula a norma 1 e de frobenius da matrizB
	// compnorma1 e compnormainf são variáveis para passar valores
	// Repete todos os processos do calculo das normas de A, mas agora para a matriz B
	for(j=0;j<colunasB;j++){
		compnorma1 = 0;
		for(i=0;i<linhasB;i++){
			compnorma1 = compnorma1 + sqrt(pow(matrizB[i][j],2));

			frobeniusB = frobeniusB + pow(matrizB[i][j],2);
		}
		if(compnorma1 > norma1B){
			norma1B = compnorma1;
		}
	}
	frobeniusB = sqrt(frobeniusB);
	// Calcula a norma infinito da matrizA
	for(i=0;i<linhasB;i++){
		compnormainf = 0;
		for(j=0;j<colunasB;j++){
			compnormainf = compnormainf + sqrt(pow(matrizB[i][j],2));
		}
		if(compnormainf > normainfB){
			normainfB = compnormainf;
		}
	}


	printf("Norma 1 da matrizA: %f\nNorma infinito da matrizA: %f\nNorma de frobenius da matrizA: %f\n\n", norma1A, normainfA, frobeniusA);
	printf("Norma 1 da matrizB: %f\nNorma infinito da matrizB: %f\nNorma de frobenius da matrizB: %f\n\n", norma1B, normainfB, frobeniusB);
	distancia = sqrt(pow(norma1A - norma1B,2));
	printf("Distancia utilizando norma 1: %f\n", distancia);
	distancia = sqrt(pow(frobeniusA - frobeniusB,2));
	printf("Distancia utilizando norma de frobenius: %f\n", distancia);
	distancia = sqrt(pow(normainfA - normainfB,2));
	printf("Distancia utilizando norma infinito: %f\n", distancia);
	
	// para o programa não fechar imediatamente após o processamento
	scanf("%d", &i);

	return 0;
}