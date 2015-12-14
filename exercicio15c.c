#include <stdio.h>
#include <math.h>
//Gauss-Seidel
int main(){

int i,j,n,k;
int convergiu=0;


printf("--------Insira o valor de n: ---------\n");
scanf("%d",&n);

float A[n][n];
float X[n];
float B[n];
float multiplicada[n];
float diferencaObtida;
float valoresAtual;
float valoresAnterior;
float cparada=0.000001;//Define a variável do critério de parada.

for(i=0;i<n;i++){//Recebe os valores da matriz A
    for(j=0;j<n;j++){
            printf("--------Insira o valor de A[%d][%d]-----\n",i,j);
            scanf("%f",&A[i][j]);
    }
}

    for(i=0;i<n;i++){//Recebe os valores do vetor B
    printf("-----Insira o valor de B[%d]-----\n",i);
    scanf("%f",&B[i]);
}

printf("\n-----A partir de agora, está sendo executado o método----\n");
for(i=0;i<n;i++){//Garante que os valores dos vetores X setados como 0.
    X[i]=0;
}

while(convergiu!=3){

    for(i=0;i<n;i++){//Zera os valores da matriz multiplicada.
        multiplicada[i]=0;
    }

    for(i=0;i<n;i++){
            valoresAtual=0;//Seta o somatório de j até i-1 como 0.
            valoresAnterior=0;//Seta o somatório de j até n- para j maior que i- como 0.
            for(k=0;k<i;k++){
                valoresAtual+= A[i][k]*X[k];//Somatório das multiplicações de Aij por Xj para j<i.
            }
            for(k=i+1;k<n;k++){
                valoresAnterior+= A[i][k]*X[k];//Somatório das multiplicações de Aij por Xj para j>i.
            }
            X[i]=(B[i]-valoresAtual-valoresAnterior)/A[i][i];//Faz X receber Bi menos os somatórios, dividido por Aii.
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            multiplicada[i]+=A[i][j]*X[j];//Faz a multiplicação entre os valores de A e os valores do X encontrado.
        }
    }

    for(i=0;i<n;i++){
        diferencaObtida=B[i]-multiplicada[i];//Calcula a diferença entre o valor do vetor B e o valor do vetor B obtido por meio do multiplicação de A pelo X encontrado.
        if(sqrt(pow(diferencaObtida,2))<=cparada)//Verifica se o módulo da diferença encontrada está dentro do aceitável(definido pela variável do critério de parada).
            convergiu=1;
        else{
            convergiu=0;
            break;
        }
    }
    if(convergiu==1)//Verifica se já foram encontrados os valores ideais de X.
        convergiu=3;
}
//--------Imprime  os valores da matriz A, do vetor B e do vetor X encontrado--------------
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
