
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
double sqrt(double x);
int main(void)
{
	int i, j,k;
	float normal1 = 0, normal2 = 0, divisor, dividendo, divisao;
	
    float vetorx[2];
    float vetorb[2];
	float matrizA[2][2];
    float matrizQ[2][2];
    float matrizR[2][2];
    float vetorQtb[2];
    
    for(i=0 ; i<2 ; i++){
        for(j=0 ; j<2 ; j++){
            printf("Informe o valor da matriz A na posição [%d] [%d]: \n", i+1,j+1);
            scanf("%f", &matrizA[i][j]);
        }
    }

    for(i=0 ; i<2 ; i++){
        printf("Informe o valor de b na posição [%d]: \n", i+1);
        scanf("%f", &vetorb[i]);
    }

    // zera a matriz R (para futuros calculos)
    for(i=0 ; i<2 ; i++){
        for(j=0 ; j<2 ; j++){
            matrizR[i][j] = 0;
        }
    }
    // zera o vetor Q transposto * b (para futuros calculos)
    for(i=0 ; i<2 ; i++){
         vetorQtb[i] = 0;
    }

    // calcula a normal da primeira coluna de Q
    for(i=0 ; i<2 ; i++){
    	normal1 += matrizA[i][0] * matrizA[i][0];
    }
    normal1 = sqrt(normal1);

    // calcula o vetor da primeira coluna de Q
    for(i=0 ; i<2 ; i++){
    	matrizQ[i][0]= matrizA[i][0] / normal1;
    }

    // calcula o valor que será usado para achar o vetor da segunda coluna de Q
    for(i=0 ; i<2 ; i++){
    	dividendo += matrizA[i][1] * matrizA[i][0];
    	divisor += matrizA[i][0] * matrizA[i][0];
    }
    divisao = dividendo/divisor;
    printf("%f\n", divisao );

    // calcula o vetor da segunda coluna de Q(antes de ser dividido pela normal)

    for(i=0 ; i<2 ; i++){
    	matrizQ[i][1]= matrizA[i][1] - (divisao * matrizA[i][0]);
    }

    // calcula a normal do vetor

    for(i=0 ; i<2 ; i++){
    	normal2 += matrizQ[i][1] * matrizQ[i][1];
    }
    normal2 = sqrt(normal2);
	
    // calcula o vetor da segunda coluna de Q (definitivo)

	for(i=0 ; i<2 ; i++){
    	matrizQ[i][1]= matrizQ[i][1] / normal2;
    }

    // calcula a matriz R
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            for(k=0;k<2;k++){
                matrizR[i][j] += matrizA[k][j] * matrizQ[k][i];
            }
        }
    }

    // calcula Q transposto * b
    for(i=0;i<2;i++){
        for(k=0;k<2;k++){
            vetorQtb[i] += matrizQ[k][i] * vetorb[k];
        }
    }

    // calcula o vetor x (resultado de A*b)
    for(i=0 ; i<2 ; i++){
        vetorx[i] = vetorQtb[i];
    }
    for(i=1 ; i>=0 ; i--){
        for(j=1 ; j>=i ; j--){
            if(i != j){
                vetorx[j] = vetorx[j]/matrizR[j][j];
                vetorx[i] -= matrizR[i][j] * vetorx[j];
            }
        }
    }
    vetorx[0] = vetorx[0]/matrizR[0][0];


    printf("\n\n ------\\/ Vetor x \\/------ \n");
    for(i=0 ; i<2 ; i++){
        printf("%f ", vetorx[i]);
        printf("\n");
    }
    printf("\n\n ------\\/ Matriz Q \\/------ \n");
    for(i=0 ; i<2 ; i++){
        for(j=0 ; j<2 ; j++){
            printf("%f ", matrizQ[i][j]);
        }
        printf("\n");
    }
    printf("\n\n ------\\/ Matriz R \\/------ \n");
    for(i=0 ; i<2 ; i++){
        for(j=0 ; j<2 ; j++){
            printf("%f ", matrizR[i][j]);
        }
        printf("\n");
    }
    printf("\n\n ------\\/ Vetor Qtb \\/------ \n");
    for(i=0 ; i<2 ; i++){
        printf("%f ", vetorQtb[i]);
        printf("\n");
    }
    scanf("%f", &k);

    return 0;
}