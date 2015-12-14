#include <stdio.h>

int main(){

float matrizA[2][2]; // Declaração de matriz 2x2.
float matrizB[3][3]; // Declaração de matriz 3x3.
int a,i,j;
float detA,detB,swap;


printf("----------Matriz A---------\n");

for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        printf("Insira o valor do índice [%d][%d]\n",i,j);
        scanf("%f",&matrizA[i][j]); // Recebe os valores de todas as posições da matriz A.
    }
}

printf("----------Matriz B---------\n");

for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        printf("Insira o valor do índice [%d][%d]\n",i,j); // Recebe os valores de todas posições da matriz B.
        scanf("%f",&matrizB[i][j]);
    }
}
// Cálculo dos tererminantes abaixo.
detA=(matrizA[0][0]*matrizA[1][1]);
detA+=(matrizA[0][1]*matrizA[1][0]*(-1));
detB=(matrizB[0][0]*matrizB[1][1]*matrizB[2][2]);
detB+=(matrizB[0][1]*matrizB[1][2]*matrizB[2][0]);
detB+=(matrizB[0][2]*matrizB[1][0]*matrizB[2][1]);
detB+=(matrizB[0][1]*matrizB[1][0]*matrizB[2][2]*(-1));
detB+=(matrizB[0][0]*matrizB[1][2]*matrizB[2][1]*(-1));
detB+=(matrizB[0][2]*matrizB[1][1]*matrizB[2][0]*(-1));

// Impressão dos resultados.
printf("\n O valor do determinante da matriz A é: %f \n",detA);
printf("\n O valor do determinante da matriz B é: %f \n",detB);


return 0;
}
