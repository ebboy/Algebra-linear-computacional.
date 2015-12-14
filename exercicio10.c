#include <stdio.h>
#include <math.h>

int main(void){
	float ncond[3];
	int linhas, colunas;
	int i, j;

	//Lê o número condição da matriz para norma 1
	printf("Digite o numero condição para norma 1:\n");
	scanf("%f", &ncond[1]);
	//Lê o número condição da matriz para norma de frobenius
	printf("Digite o numero condição para norma de frobenius:\n");
	scanf("%f", &ncond[2]);
	//Lê o número condição da matriz para norma infinito
	printf("Digite o numero condição para norma infinito:\n");
	scanf("%f", &ncond[0]);

	//Lê quantas linhas a matriz tem
	printf("Digite o numero de linhas da matriz:\n");
	scanf("%d", &linhas);
	//Lê quantas colunas a matriz tem
	printf("Digite o numero de colunas da matriz:\n");
	scanf("%d", &colunas);

	float matrizA[linhas][colunas];
	float norma1 = 0, normainf = 0, frobenius = 0;
	float compnorma1, compnormainf;
	float norma1inv, normainfinv, frobeniusinv;

	// Lê a matriz em questão
	for(i=0;i<linhas;i++){
		for(j=0;j<colunas;j++){
			printf("Digite o valor em matrizA[%d][%d]:\n", i, j);
			scanf("%f", &matrizA[i][j]);
		}
	}

	// Calcula a norma 1 e de frobenius da matriz para futuramente achar as normas de sua inversa
	// compnorma1 e compnormainf são variáveis para passar valores
	for(j=0;j<colunas;j++){ // contado todas as linhas de cada coluna
		compnorma1 = 0;
		for(i=0;i<linhas;i++){
			compnorma1 = compnorma1 + sqrt(pow(matrizA[i][j],2)); // acrescenta ||Aij|| à compnorma1

			frobenius = frobenius + pow(matrizA[i][j],2); // acrescenta Aij² à frobeniusA
		}
		if(compnorma1 > norma1){
			norma1 = compnorma1; // define norma1A como compnorma1(que é a soma dos modulos de valores de A) caso compnorma1 seja maior que norma1A
		}
	}
	frobenius = sqrt(frobenius); // define frobeniusA como a raiz quadrada da soma dos quadrados dos valores de Aij
	// Calcula a norma infinito da matriz para futuramente achar as normas de sua inversa
	for(i=0;i<linhas;i++){ // desta vez é contado todos as colunas de cada linha
		compnormainf = 0;
		for(j=0;j<colunas;j++){
			compnormainf = compnormainf + sqrt(pow(matrizA[i][j],2)); // acrescenta ||Aij|| à compnormainf
		}
		if(compnormainf > normainf){
			normainf = compnormainf; // define normainfA como compnormainf(que é a soma dos modulos de valores de A) caso compnorma1inf seja maior que normainfA
		}
	}


	// calcula as normas da inversa
	normainfinv = ncond[0] / normainf;
	norma1inv = ncond[1] / norma1;
	frobeniusinv = ncond[2] / frobenius;

	printf("Norma 1: %f\nNorma infinito: %f\nNorma de frobenius: %f\n", norma1inv, normainfinv, frobeniusinv);
	
	// para o programa não fechar imediatamente após o processamento
	scanf("%d", &i);

	return 0;
}