#include <stdio.h>

int main(){

int i,j,m,k;
int clinhas=1;
int ccolunas=1;


printf("----------Insira o valor de m:-----------\n");
scanf("%d",&m);

float A[m][m];
float beta[m];
float valores=0;
float temp;
float betamaximo=0;
//---------Recebe os valores da matriz A-------------------
for(i=0;i<m;i++){
    for(j=0;j<m;j++){
            printf("--------Insira o valor de A[%d][%d]-----\n",i,j);
            scanf("%f",&A[i][j]);
    }
}

//------CRITÉRIO DAS LINHAS-------
for(i=0;i<m;i++){
    for(j=0;j<m;j++){
        if(j!=i){
            if(A[i][i]<=A[i][j]){
                clinhas=0;
                break;
            }
        }
    }
}

if(clinhas==1)
    printf("Satisfaz o critério das linhas.Logo, converge!!!\n");
else
    printf("Não satisfaz o critério das linhas.Logo, não há garantia de que vá convergir!!!\n");

//-----CRITÉRIO DAS COLUNAS-------
for(j=0;j<m;j++){
    for(i=0;i<m;i++){
        if(j!=i){
            if(A[j][j]<=A[i][j]){
                ccolunas=0;
                break;
            }
        }
    }
}

if(ccolunas==1)
    printf("Satisfaz o critério das colunas.Logo, CONVERGE!!!\n");
else
    printf("Não satisfaz o critério das colunas.Logo, não há garantia de que vá convergir!!!\n");

//------CRITÉRIO DE SASSENFELD------
for(j=0;j<m;j++){
    if(A[0][j]<0)
        temp=A[0][j]*(-1);
    else
        temp=A[0][j];
    valores+=temp;
}
if(A[0][0]<0)
   beta[0]=valores/(A[0][0]*(-1));
else
    beta[0]=valores/A[0][0];

valores=0;
temp=0;

for(i=0;i<m;i++){
    for(j=0;j<m;j++){
        for(k=0;k<i-1;k++){
            if(A[i][k]<0)
                valores+=A[i][k]*(-1)*beta[k];
            else
                valores+=A[i][k]*beta[k];
        }

        for(k=i+1;k<m;k++){
            if(A[i][k]<0)
                temp+=A[i][k]*(-1);
            else
                temp+=A[i][k];
        }
        if(A[i][i]<0)
            beta[i]=(valores+temp)/(A[i][i]*(-1));
        else
            beta[i]=(valores+temp)/A[i][i];
        valores=0;
        temp=0;
    }
}

for(i=0;i<m;i++){
    if(beta[i]>betamaximo)
        betamaximo=beta[i];
}

if(betamaximo<1)
    printf("Satisfaz o critério de Sassenfeld.Logo, CONVERGE!!!\n");
else
    printf("Não satisfaz o critério de Sassenfeld.Logo, não há garantia de que vá convergir!!!\n");

printf("Betamaximo: %f\n",betamaximo);




return 0;
}
