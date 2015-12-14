#include <stdio.h>
#include <math.h>


// Função para achar o w otimo
double achawOtimo(float matrizA[3][3]){
    double delta;
    double x, wotimo;
    
    // Como a matriz é 3x3, tridiagonal e positiva de definida, o calculo de A(Tj) utilizado na definição do w otimo tem a estrutura:
    // √((a12² + a23²)/a11²) / 2
    // onde a11, a12 e a23 são valores da matriz informada pelo usuário

    delta = 4 * ((pow(matrizA[0][1],2) + pow(matrizA[1][2],2)) / pow(matrizA[0][0],2)); // calcula (a12² + a23²)/a11²
    x = sqrt(delta)/2; calcula A(Tj)

    wotimo = 2/(1+sqrt(1-pow(x,2))); // Aplica a formula do teorema 3 da definição do w otimo

    return wotimo;
}

// Aplica o método SOR desenvolvido na questão 16, implementando o valor de w com o w ótimo achado com função acima
int main(void){

int i,j,k;
int n = 3;
int convergiu=0;
float antesGauss;

double w;

float A[n][n];
float X[n];
float B[n];
float multiplicada[n];

float diferencaObtida;
float valoresAtual;
float valoresAnterior;
float cparada=0.000001;

for(i=0;i<n;i++){
    for(j=0;j<n;j++){
            printf("--------Insira o valor de A[%d][%d]-----\n",i,j);
            scanf("%f",&A[i][j]);
    }
}

w = achawOtimo(A);

    for(i=0;i<n;i++){
    printf("-----Insira o valor de B[%d]-----\n",i);
    scanf("%f",&B[i]);
}

printf("\n-----A partir de agora, está sendo executado o método----\n");
for(i=0;i<n;i++){
    X[i]=0;
}

while(convergiu!=3){

    for(i=0;i<n;i++){
        multiplicada[i]=0;
    }

    for(i=0;i<n;i++){
            valoresAtual=0;
            valoresAnterior=0;
      		antesGauss = (1-w)*X[i];
            for(k=0;k<i;k++){
                valoresAtual+= A[i][k]*X[k];
            }
            for(k=i+1;k<n;k++){
                valoresAnterior+= A[i][k]*X[k];
            }
            X[i]=(B[i]-valoresAtual-valoresAnterior)*(w/A[i][i]) + antesGauss;
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            multiplicada[i]+=A[i][j]*X[j];
        }
    }

    for(i=0;i<n;i++){
        diferencaObtida=B[i]-multiplicada[i];
        if(sqrt(pow(diferencaObtida,2))<=cparada)
            convergiu=1;
        else{
            convergiu=0;
            break;
        }
    }
    if(convergiu==1)
        convergiu=3;

}

printf("\n------Matriz A------\n");
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        printf(" %f ",A[i][j]);
    }
    printf("\n");
}

printf("\n-------Vetor B------\n");
for(i=0;i<n;i++){
    printf(" %f \n",B[i]);
}

printf("\n-------Vetor X-------\n");
for(i=0;i<n;i++){
    printf(" %f \n",X[i]);
}

return 0;
}
