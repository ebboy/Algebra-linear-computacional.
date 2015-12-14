#include <stdio.h>

int main(){

int i,j,m,k;
// Recebe a ordem M da matriz.
printf("-----Insira o valor de m:-----\n");
scanf("%d",&m);
// Cria matrizes de ordem M.
float A[m][m];
float L[m][m];
float U[m][m];
float B[m];
float X[m];
float Y[m];
float valores;

// Recebe os valores da matriz A.
for(i=0;i<m;i++){
    for(j=0;j<m;j++){
        printf("-----Insira o valor de A[%d][%d]-----\n",i,j);
        scanf("%f",&A[i][j]);

    }
}
// Recebe os valores do vetor B.
for(i=0;i<m;i++){
    printf("-----Insira o valor de B[%d]-----\n",i);
    scanf("%f",&B[i]);
}
// Zera todos os valores das matrizes L e U.
for(i=0;i<m;i++){
    for(j=0;j<m;j++){
        L[i][j]=0;
        U[i][j]=0;
    }
}
// Cria a diagonal de 1.
for(i=0;i<m;i++){
    for(j=0;j<m;j++){
        if(i==j)
            L[i][j]=1;
    }
}
// Calcula LU através da fórmula.
for(i=0;i<m;i++){
    for(j=0;j<m;j++){
        valores=0; // zera variável valores.
        // Para quando i = 0;
        if(i==0)
            U[0][j]=A[0][j];
        // Para quando I maior ou igual a 1 e j igual a 1.
        if(i>=1 && j==1)
           L[i][0]=A[i][0]/U[0][0];
       	// Para quando I maior ou igual a 1 e J maior ou igual a 1.
        if(i>=1 && j>=i){
           for(k=0;k<i;k++){
                valores+=L[i][k]*U[k][j];
            }
            U[i][j]=A[i][j]-valores;
        }
        // Quando I maior ou igual a I+1 e J maior ou igual a 1.
        if(i>=j+1 && j>=1){
            valores=0;// Zera valores.
            for(k=0;k<j;k++){
                valores+=L[i][k]*U[k][j];// Incrementa a variavel valores.
            }
            L[i][j]=(1/U[j][j])*(A[i][j]-valores);
        }


    }
}
// ---- Impressão dos resultados.
printf("\n---------Matriz L-------\n");
for(i=0;i<m;i++){
    for(j=0;j<m;j++){
        printf(" %f ",L[i][j]);
    }
    printf("\n");
}

printf("\n---------Matriz U-------\n");
for(i=0;i<m;i++){
    for(j=0;j<m;j++){
        printf(" %f ",U[i][j]);
    }
    printf("\n");
}

/*=====Calculo de Y============*/
//-----triangular inferior------
Y[0]=(B[0]/L[0][0]);//Calcula o valor de Y1

for(i=0;i<m;i++){
    valores=0;
    for(j=0;j<i;j++){
            valores+=(L[i][j]*Y[j]);//Faz o calculo da expressão da linha até todos os Ys obtidos e armazena esse valor
    }
    Y[i]=(B[i]-valores)/L[i][i];//Faz B menos o somatório dos valores que já temos e divide pelo indice do Y em questão
}
/*======Calculo de X============*/
//------triangular superior------
X[m-1]=(Y[m-1]/U[m-1][m-1]);//Calcula o valor do Xk.

for(i=m-2;i>=0;i--){
    valores=0;
    for(j=i+1;j<m;j++){
        valores+=(U[i][j]*X[j]);//Faz o calculo da expressão da linha até todos os Xs obtidos e armazena esse valor
    }
    X[i]=((Y[i]-valores)/U[i][i]);//Faz Y menos o somatório dos valores que já temos e divide pelo indice do X em questão
}
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
