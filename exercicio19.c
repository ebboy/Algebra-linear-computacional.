#include <stdio.h>

// Função para calcular a Raiz do polinomio caracteristico
float RaizPolCar(float matrizA[3][3], int iteracoes){
	// O polinomio apresentará a estrutura: -λ³ + aλ² + bλ + c
	float a, b, c;
	float lambda, funcx, derfuncx;
	int i;
	// Calculo de a, b e c tirado do calculo da determinante da matriz * λI
	a = matrizA[0][0]+matrizA[1][1]+matrizA[2][2];
	b = (matrizA[0][1]*matrizA[1][0]) + (matrizA[0][2]*matrizA[2][0]) + (matrizA[1][2]*matrizA[2][1]) - (matrizA[0][0]*matrizA[1][1]) - (matrizA[0][0]*matrizA[2][2]) - (matrizA[1][1]*matrizA[2][2]);
	c = (matrizA[0][0]*matrizA[1][1]*matrizA[2][2]) + (matrizA[0][1]*matrizA[1][2]*matrizA[2][0]) + (matrizA[0][2]*matrizA[1][0]*matrizA[2][1]) - (matrizA[0][0]*matrizA[1][2]*matrizA[2][1]) - (matrizA[0][1]*matrizA[1][0]*matrizA[2][2]) - (matrizA[0][2]*matrizA[1][1]*matrizA[2][0]);

	// Cria um valor qualquer para lamba 0 (primeiro valor da iteração)
	lambda = (a+b+c)/3;

	// Põe em pratica o método de Newton-Raphson
	for(i=0;i<iteracoes;i++){
		// Função do polinomio característico
		funcx = -(lambda*lambda*lambda) + (a*lambda*lambda) + (b*lambda) + c;
		// a sua derivada
		derfuncx = -(3*lambda*lambda) + (2*a*lambda) + b;
		// calculo de lambda utilizando o método de Newton-Raphson
		lambda = lambda - (funcx / derfuncx);
	}

	// retorna o valor o ultimo valor de lambda definido pela iteração
	return lambda;
}


int main(void){
	float matrizA[3][3];
	int i, j, iteracoes;

	// Lê a matriz em questão
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("Digite o valor em matrizA[%d][%d]:\n", i, j);
			scanf("%f", &matrizA[i][j]);
		}
	}
	//Lê o número de iterações desejado para o metodo de Newton-Raphson
	printf("Digite o numero de iteracoes:\n");
	scanf("%d", &iteracoes);

	// mostra o valor da raiz do polinomio característico usando a função criada no início do código
	printf("A raiz do polimonio caracteristico e: %f \n", RaizPolCar(matrizA, iteracoes));

	// Só para o arquivo .exe não fechar assim que acabar o programa
	scanf("%d", &i);

	return 0;
}