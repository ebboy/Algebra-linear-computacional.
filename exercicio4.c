#include <stdio.h>

int main(){

int k,i,j,b;

printf("\n Digite o valor de k: \n");
scanf("%d",&k);//Recebe a ordem k da matriz.

float superior[k][k+1];// Cria um vetor de k linhas e k+1 colunas (Colunas da matriz + coluna B do a.x = b)
float x[k];// Raízes da matriz.
float valores;

for(i=0;i<k;i++){
    x[i]=0;// Garante que todos os valores das raízes são setados como 0.
}

for(i=0;i<k;i++){
    for(j=0;j<k+1;j++){
            printf("Digite o valor da matriz[%d][%d] \n",i,j);
        scanf("%f",&superior[i][j]);// Recebe todos os valores da matriz.
    }
}

x[k-1]=(superior[k-1][k-1+1]/superior[k-1][k-1]);//Calcula o valor do Xk.

for(i=k-2;i>=0;i--){
    valores=0;
    for(j=i+1;j<k+1;j++){
        valores+=(superior[i][j]*x[j]);//Faz o calculo da expressão da linha até todos os Xs obtidos e armazena esse valor
    }
    x[i]=((superior[i][k]-valores)/superior[i][i]);//Faz B menos o somatório dos valores que já temos e divide pelo indice do X em questão
}

printf("\n------Resultados------\n");

    for(i=0;i<k;i++){
        printf("x%d = %f \n",i+1,x[i]);// Imprime os valores encontrados
    }


return 0;
}
