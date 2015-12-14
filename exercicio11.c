#include <stdio.h>
#include <math.h>

// função para calcular a norma 1 de uma matriz
float norma1(int ordem, float matrizA[ordem][ordem]){
	int i, j;
	float compnorma1, norma1 = 0;

	// compnorma1 e compnormainf são variáveis usadas para passar valores
	for(j=0;j<ordem;j++){
		compnorma1 = 0;
		for(i=0;i<ordem;i++){
			compnorma1 = compnorma1 + sqrt(pow(matrizA[i][j],2)); // acrescenta ||Aij|| à compnorma1
		}
		if(compnorma1 > norma1){
			norma1 = compnorma1; // define norma1 como compnorma1(que é a soma dos modulos de valores de A) caso compnorma1 seja maior que norma1A
		}
	}

	return norma1;
}

// função para calcular a norma 1 de um vetor
float norma1vetor(int linhas, float vetorA[linhas]){
	int i;
	float norma1 = 0;

	for(i=0;i<linhas;i++){ 
		norma1 = norma1 + sqrt(pow(vetorA[i],2)); // define norma1 como a soma dos modulos dos valores do vetor
	}

	return norma1;
}
// função para realizar a decomposicao LU de uma matriz
// mesmo metodo utilizado no desenvolvimento da questão 8
void decomposicaoLU(int m, float A[m][m], float B[m], float vetorX[m]){
	int i,j,k;

	float L[m][m];
	float U[m][m];
	float X[m];
	float Y[m];
	float valores;
	// Zera as matrizes L e U
	for(i=0;i<m;i++){
	    for(j=0;j<m;j++){
	        L[i][j]=0;
	        U[i][j]=0;
	    }
	}
	// Define as diagonais da matriz L como 1
	for(i=0;i<m;i++){
	    for(j=0;j<m;j++){
	        if(i==j)
	            L[i][j]=1;
	    }
	}
	for(i=0;i<m;i++){
	    for(j=0;j<m;j++){
	        valores=0;
	        if(i==0)
	            U[0][j]=A[0][j];

	         if(i>=1 && j==1)
	            L[i][0]=A[i][0]/U[0][0];

	             if(i>=1 && j>=i){
	            for(k=0;k<i;k++){
	                valores+=L[i][k]*U[k][j];
	            }
	            U[i][j]=A[i][j]-valores;
	        }
	         if(i>=j+1 && j>=1){
	                valores=0;
	            for(k=0;k<j;k++){
	                valores+=L[i][k]*U[k][j];
	            }
	            L[i][j]=(1/U[j][j])*(A[i][j]-valores);
	        }
	    }
	}
	//-----triangular inferior------
	Y[0]=(B[0]/L[0][0]);

	for(i=0;i<m;i++){
	    valores = 0;
	    for(j=0;j<i;j++){
	        valores += (L[i][j]*Y[j]);
	    }
	    Y[i] = (B[i]-valores)/L[i][i];
	}
	//------triangular superior------
	X[m-1]=(Y[m-1]/U[m-1][m-1]);

	for(i=m-2;i>=0;i--){
	    valores = 0;
	    for(j=i+1;j<m;j++){
	        valores += (U[i][j]*X[j]);
	    }
	    X[i] = ((Y[i]-valores)/U[i][i]);
	}
	for(i=0;i<m;i++){
	    vetorX[i] = X[i];
	}
}



int main(void){
	int ordem;
	int i, j;

	float matrizHilbert[2][2] = {{ 1 , 0.5 },{ 0.5 , 0.333333 }};
	float vetorH[2];
	float wH[2] = { 3.0 , 8.0 };
	float k1H;

/* Problemas com variaveis atrapalharam a definição automatica da matriz de Hilbert
	for(i=1; i<=2; i++){
		for(j=1; j<=2; j++){
			matrizHilbert[i-1][j-1] = 1/(i+j-1);
		}
	}
*/

	// Mostra na tela a matriz de Hilbert
	for(i=0; i<2; i++){
		for(j=0; j<2; j++){
			printf(" %f", matrizHilbert[i][j]);
		}
		printf("\n");
	}

	decomposicaoLU(2, matrizHilbert, wH, vetorH ); // realiza a decomposição LU da matriz de Hilbert
	k1H = (norma1(2, matrizHilbert)*norma1vetor(2, vetorH))/norma1vetor(2, wH); // Calcula k1(H) de acordo com a formula (||H||1 * ||H^-1 * w||1) / ||w||
	printf("O valor do limitante inferior do numero condicao de uma matriz de Hilbert de ordem 2: %f\n", k1H);


	printf("Digite a ordem da matriz:\n");
	scanf("%d", &ordem);

	float matrizA[ordem][ordem];
	float vetorX[ordem];
	float w[ordem];
	float dividendo, divisor, k1A;


	for(i=0; i<ordem; i++){
		for(j=0; j<ordem; j++){
			printf("Digite o valor de matrizA[%d][%d]:\n", i, j);
			scanf("%f", &matrizA[i][j]);
		}
	}
	for(i=0; i<ordem; i++){
		printf("Digite o valor de w[%d]:\n", i);
		scanf("%f", &w[i]);
	}

	decomposicaoLU(ordem, matrizA, w, vetorX ); // realiza a decomposição LU da matriz inserida

	k1A = (norma1(ordem, matrizA)*norma1vetor(ordem, vetorX))/norma1vetor(ordem, w); // Calcula k1(A) de acordo com a formula (||A||1 * ||A^-1 * w||1) / ||w||
	printf("O valor de k1(A): %f\n", k1A);

	return 0;
}