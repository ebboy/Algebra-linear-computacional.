#include <stdio.h>

int main(){

    int m,n,i,j,m2,n2,i2,j2,mf,nf,k;
    int flops=0;

    printf("Insira os valores de m e n \n");
    scanf("%d %d",&m,&n);

    printf("Insira os valores de m2 n2 \n");
    scanf("%d %d",&m2,&n2);

    float matriz[m][n];
    float matriz2[m2][n2];
    float multiplicada[m][n2];

    printf("Insira os valores da matriz 1 \n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){

             scanf("%f",&matriz[i][j]);
        }

    }

    printf("Insira os valores da matriz 2 \n");
    for(i=0;i<m2;i++){
        for(j=0;j<n2;j++){

             scanf("%f",&matriz2[i][j]);
        }

    }

//-----Neste "for" garantimos que todos os valores da matriz multiplicada estão "setados" como 0-------
    for(i=0;i<m;i++){
        for(j=0;j<n2;j++){
             multiplicada[i][j]=0;
             flops++;
        }
    }

//------Neste "for" o j é mantido apenas para que as coordenadas da matriz multiplicada sejam corretos.
    for(i=0;i<m;i++){
        for(j=0;j<n2;j++){
                for(k=0;k<n;k++){//O k faz o papel do j, ou seja percorre as colunas da matriz1 e as linhas da matriz2
                     multiplicada[i][j]+=(matriz[i][k]*matriz2[k][j]);//adiciona a matriz multiplicada[i][j] o resultado da multiplicação entre os termos das matrizes 1 e 2.
                     flops+=2;//Adiciona 2 à contagem de flops, pois é efetuada uma soma e uma multiplicação.
                }
        }

    }

    printf("O resultado é: \n");

    for(i=0;i<m;i++){
        for(j=0;j<n2;j++){
            printf(" %f ",multiplicada[i][j]);
        }
        printf("\n");
    }


    return 0;
}


