#include <stdio.h>

int main(){

int m,i,j;
int diagonal=1,tridiagonal=1;

printf("-----Digite o valor de m: ------\n ");
scanf("%d",&m);

float matriz[m][m];

for(i=0;i<m;i++){
    for(j=0;j<m;j++){
            printf("Digite o valor da matriz[%d][%d] \n",i,j);
        scanf("%f",&matriz[i][j]);
    }
}

while(diagonal!=0 || tridiagonal!=0){
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
                /*Verifica se as posi��es acima e abaixo da diagonal principal s�o 0, e se as posi��es da diagonal principal s�o diferentes de 0*/
                if(i+1==j+1 && matriz[i][j]==0){
                    diagonal=0;
                    tridiagonal=0;
                    break;
                }
                if((i+1-j+1)>0 && matriz[i][j]==0)
                    diagonal=1;
                else if((i+1-j+1)<0 && matriz[i][j]!=0){
                    diagonal=0;
                    tridiagonal=0;
                    break;
                }
                else if((i+1-j+1)>0 && matriz[i][j]!=0){
                   diagonal=0;
                   tridiagonal=0;
                   break;
                }
/*----------------------Verifica se as posi��es acima e abaixo da tridiagonal s�o 0--------------------------------------------*/


                else if((i+1-j+1)>1 && matriz[i][j]==0)
                    tridiagonal=1;
                else if((i+1-j+1)>1 && matriz[i][j]!=0){
                    tridiagonal=0;
                    break;
                }
                else if((i+1-j+1)<1 && matriz[i][j]!=0){// 4/12
                    tridiagonal=0;
                    break;
                }



        }
    }
    break;
}
//--------Classifica corretamente a matriz--------------------
if(diagonal==1)
    printf("\n------� diagonal!!!--------\n");
else if(tridiagonal==1 && diagonal==0)
    printf("\n------� tridiagonal!!!-------\n");
else
    printf("\n-------N�o � nem diagonal, nem tridiagonal!!!-----\n");



return 0;
}
