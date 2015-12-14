#include <stdio.h>
#include <math.h>

int main(){

int i,j,m,k,c;

printf("----------Insira o valor de m-------------\n");
scanf("%d",&m);

float A[m][m];
float R[m][m];
float Rt[m][m];
float B[m];
float X[m];
float Y[m];
float valores;

for(i=0;i<m;i++){
    for(j=0;j<m;j++){
        printf("-----Insira o valor de A[%d][%d]-----\n",i,j);
        scanf("%f",&A[i][j]);

    }
}

for(i=0;i<m;i++){
    printf("-----Insira o valor de B[%d]-----\n",i);
    scanf("%f",&B[i]);
}
//--------------Garante que os valores de R e R transposto estão setados como 0------------
for(i=0;i<m;i++){
    for(j=0;j<m;j++){
        R[i][j]=0;
    }
}
    for(i=0;i<m;i++){
    for(j=0;j<m;j++){
        Rt[i][j]=0;
    }
}
//-----------------------------------------------------------------------------------------

for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            valores=0;
            if(i<j)//Se o valor de j for maior que i,pula para o próximo ciclo do for.
                continue;
            else if(i==0 && j==0){
                Rt[i][j]=sqrt(A[0][0]);//Faz R11 igual a raiz de a11.
            }
            else if(i==j){
                    for(c=0;c<i;c++){
                        valores+=pow(Rt[i][c],2);
                    }

                Rt[i][j]=sqrt(A[i][i]-valores);//Se i e j forem iguais, faz Raiz de (aii-somatório de todos (Rtij ao quadrado)até j=i-1).
            }
            else if(j==0){
                Rt[i][j]=A[i][0]/Rt[0][0];//Se Ri1, faz ai1/Rt11
            }

            else if(i>j){
                    valores=0;
                for(k=0;k<j;k++){
                    valores+=Rt[i][k]*Rt[j][k];
                }
                Rt[i][j]=(1/Rt[j][j])*(A[i][j]-valores);//Se i>j faz: (1/ajj)*(aij- somatório de todos (Rtik*Rjk) com k de 1 até j-1).
            }

        }
    }

for(i=0;i<m;i++){//Passa os valores de R.
        for(j=0;j<m;j++){
            R[i][j]=Rt[j][i];
        }
    }
//-------------------Imprime os valores encontrados para R e R transposto----------------------
 printf("\n--------Matriz R------\n");

    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            printf(" %f ",R[i][j]);
        }
        printf("\n");
    }


    printf("\n--------Matriz Rt------\n");

    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            printf(" %f ",Rt[i][j]);
        }
        printf("\n");
    }
//--------------------------------------------------------------------------------------------


/*=========================Calculo de Y=====================================*/
//-----triangular inferior, substituição pra frente--------------------------
Y[0]=(B[0]/Rt[0][0]);//Calcula o valor de Y1

for(i=0;i<m;i++){
    valores=0;
    for(j=0;j<i;j++){
            valores+=(Rt[i][j]*Y[j]);//Faz o calculo da expressão da linha até todos os Xs obtidos e armazena esse valor
    }
    Y[i]=(B[i]-valores)/Rt[i][i];//Faz B menos o somatório dos valores que já temos e divide pelo indice do Y em questão
}
/*========================Calculo de X======================================*/
//------triangular superior,substituição pra trás---------------------------
X[m-1]=(Y[m-1]/R[m-1][m-1]);//Calcula o valor do Xk.

for(i=m-2;i>=0;i--){
    valores=0;
    for(j=i+1;j<m;j++){
        valores+=(R[i][j]*X[j]);//Faz o calculo da expressão da linha até todos os Xs obtidos e armazena esse valor
    }
    X[i]=((Y[i]-valores)/R[i][i]);//Faz Y menos o somatório dos valores que já temos e divide pelo indice do X em questão
}
/*==========================================================================*/
//--------------------Imprime os valores  encontrados para Y e X---------------
printf("\n------Vetor Y-------\n");

for(i=0;i<m;i++){
    printf(" %f \n",Y[i]);
}

printf("\n-----Vetor X-------\n");

for(i=0;i<m;i++){
    printf(" %f \n",X[i]);
}



return 0;
}
