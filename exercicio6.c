#include <stdio.h>
#include <math.h>

int main(){

int m,n,i,j,k;
int c;

printf("------Insira os valores de m e n------\n");
scanf("%d %d",&m,&n);

float A[m][n];
float At[n][m];
float C[m][m];
float R[m][m];
float Rt[m][m];
float valores;


for(i=0;i<m;i++){
    for(j=0;j<n;j++){
        printf("-----Insira o valor de A[%d][%d]-----\n",i,j);
        scanf("%f",&A[i][j]);

    }
}
//------Passa os valores para a transposta da matriz A
for(i=0;i<n;i++){
    for(j=0;j<m;j++){
        At[i][j]=A[j][i];
    }
}

for(i=0;i<m;i++){
    for(j=0;j<m;j++){
        C[i][j]=0;//Garante que os valores da matriz C estão setados como 0.
    }
}


 for(i=0;i<m;i++){
        for(j=0;j<m;j++){
                for(k=0;k<n;k++){
                     C[i][j]+=(A[i][k]*At[k][j]);//Faz o calculo C= A * A transposta.
                }
        }

    }

     printf("-------O resultado é:-------\n");
    //-------Imprime a matriz C resultante-------
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            printf(" %f ",C[i][j]);
        }
        printf("\n");
    }//------------------------------------------

    //-----------------Garante que os valores de R e R transposto estão setados como 0-------
    for(i=0;i<m;i++){
    for(j=0;j<m;j++){
        R[i][j]=0;
    }
}
    for(i=0;i<m;i++){
    for(j=0;j<m;j++){
        Rt[i][j]=0;
    }
}//------------------------------------------------------------------------------------------

    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            valores=0;
            if(i<j)//Se o valor de j for maior que i,pula para o próximo ciclo do for.
                continue;
            else if(i==0 && j==0){
                R[i][j]=sqrt(C[0][0]);//Faz R11 igual a raiz de a11(no caso C11).
            }
            else if(i==j){
                    for(c=0;c<i;c++){
                        valores+=pow(R[i][c],2);
                    }

                R[i][j]=sqrt(C[i][i]-valores);//Se i e j forem iguais, faz Raiz de (aii-somatório de todos (Rij ao quadrado)até j=i-1).
            }
            else if(j==0){
                R[i][j]=C[i][0]/R[0][0];//Se Ri1, faz ai1/R11
            }

            else if(i>j){
                    valores=0;
                for(k=0;k<j;k++){
                    valores+=R[i][k]*R[j][k];
                }
                R[i][j]=(1/R[j][j])*(C[i][j]-valores);//Se i>j faz: (1/ajj)*(aij- somatório de todos (Rik*Rjk) com k de 1 até j-1).
            }

        }
    }

    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            Rt[i][j]=R[j][i];//Passa os valores de R transposto.
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
//----------------------------------------------------------------------------------------------



return 0;
}
