#include <stdio.h>

int main(){

    int m,n,i,j,v; // Declaração de variaveis
    int flops;

    printf("Insira os valores de m n \n");
    scanf("%d %d",&m,&n); // Recebe as dimensões MxN da matriz.

    int matriz[m][n]; // Cria vetor de tamanho MxN.
    int vetor[n];
    int multiplicada[m];

    printf("Insira os valores da matriz \n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){

             scanf("%d",&matriz[i][j]); // Recebe os valores de todas as posiçõs da matriz.
             flops++; // Aumenta flop.
        }

    }

    printf("Insira os valores do vetor \n");
    for(v=0;v<n;v++){
        scanf("%d",&vetor[v]); // Recebe os valores das posições do vetor.
        flops++; // Aumenta flop.
    }



    // ----------Aqui garantimos que os valores da matriz final estão setados como 0------------
    for(v=0;v<m;v++){
        multiplicada[v]=0;
        flops++;
    }
    //--------------------------------------------------------------------------------------------

    v=0;

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            multiplicada[v]+=(matriz[i][j]*vetor[j]); // Calcula o valor da multiplicação da matriz.
            flops++;// Aumenta flop.

        }
        v++;

    }

    printf("O resultado e: \n");
    for(v=0;v<m;v++){
        printf(" %d \n",multiplicada[v]);
    }

    printf("O numero total de flops e: %d \n",flops);


    return 0;
}

