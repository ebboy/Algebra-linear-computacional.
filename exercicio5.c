#include <stdio.h>

int main(){

int k,i,j;

printf("\n Digite o valor de k: \n");
scanf("%d",&k);//Recebe a ordem k da matriz.

float inferior[k][k+1];// Cria um vetor de k linhas e k+1 colunas (Colunas da matriz + coluna B do a.x = b)
float x[k];// Ra�zes da matriz.
float valores;

for(i=0;i<k;i++){
    x[i]=0;// Garante que todos os valores das ra�zes s�o setados como 0.
}

for(i=0;i<k;i++){
    for(j=0;j<k+1;j++){
            printf("Digite o valor da matriz[%d][%d] \n",i,j);
        scanf("%f",&inferior[i][j]);// Recebe todos os valores da matriz.
    }
}

x[0]=(inferior[0][k]/inferior[0][0]);//Calcula o valor do X1.

for(i=0;i<k;i++){
    valores=0;
    for(j=0;j<i;j++){
            valores+=(inferior[i][j]*x[j]);//Faz o calculo da express�o da linha at� todos os Xs obtidos e armazena esse valor
    }
    x[i]=(inferior[i][k]-valores)/inferior[i][i];//Faz B menos o somat�rio dos valores que j� temos e divide pelo indice do X em quest�o
}

printf("\n------Resultados------\n");

    for(i=0;i<k;i++){
        printf("x%d = %f \n",i+1,x[i]);// Imprime os valores encontrados
    }



return 0;
}
