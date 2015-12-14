#include <stdio.h>
#include <math.h>
//SOR- o algoritmo funciona com a mesma metodologia do método de Gauss-Seidel(exercicio15c.c), fazendo poucas alterações
int main(){

int i,j,n,k;
int convergiu=0;
float w, antesGauss;


printf("--------Insira o valor de n: ---------\n");
scanf("%d",&n);
printf("--------Insira o valor do w: ---------\n");
scanf("%f",&w);//Recebe o valor de W(calculado pelo matlab).

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
      		antesGauss = (1-w)*X[i];//Calcula a parte do método que difere do método de Gauss.
            for(k=0;k<i;k++){
                valoresAtual+= A[i][k]*X[k];
            }
            for(k=i+1;k<n;k++){
                valoresAnterior+= A[i][k]*X[k];
            }
            X[i]=(B[i]-valoresAtual-valoresAnterior)*(w/A[i][i]) + antesGauss;//Calcula a parte do método que difere do método de Gauss.
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
