#include <stdio.h>

int main(){

int i,j,m,k;
int ortogonal=1;

printf("-------Insira o valor de m--------\n");
scanf("%d",&m);

float A[m][m];
float At[m][m];
float resultante[m][m];
float I[m][m];
/*------------Seta os valores das matrizes como 0-----------------*/
for(i=0;i<m;i++){
    for(j=0;j<m;j++){
        A[i][j]=0;
        At[i][j]=0;
        I[i][j]=0;
        resultante[i][j]=0;
    }
}/*---------------------------------------------------------------*/

for(i=0;i<m;i++){//Recebe valores de A, passa valores de At e seta valores da identidade
    for(j=0;j<m;j++){
        printf("\n------Insira o valor de A[%d][%d]------\n",i,j);
        scanf("%f",&A[i][j]);
        At[j][i]=A[i][j];
        if(i==j)
            I[i][j]=1;
    }
}
/*-----------------Faz a multiplicação entre as matrizes A e At------------------*/
 for(i=0;i<m;i++){
        for(j=0;j<m;j++){
                for(k=0;k<m;k++){
                     resultante[i][j]+=(A[i][k]*At[k][j]);
                }
        }

    }/*------------------------------------------------------------------------*/

for(i=0;i<m;i++){
    for(j=0;j<m;j++){
        if(resultante[i][j]==-0){//evita que valores (-0) inutilizem a resposta desnecessáriamente.
           resultante[i][j]=0;
        }
    }
}

for(i=0;i<m;i++){
    for(j=0;j<m;j++){
        if(resultante[i][j]!=I[i][j]){//Verifica se a matriz resultante da multiplicação é igual a matriz identidade
            ortogonal=0;
            break;
        }
    }
}
//Imprime a conclusão da verificação.
if(ortogonal==1)
    printf("\n--------É ORTOGONAL!!!---------\n");
else
    printf("\n--------NÃO É ORTOGONAL!!!!!-------\n");

return 0;
}
