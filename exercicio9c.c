#include <stdio.h>
#include <math.h>

#define PI 3.14159265
int main(){
	int i,j; // Tamanho de vetor e contador.
	float produtoIn=0,norma2=0,norma2b=0,arcocosen=0;
	double val;
	val = 180 / PI;
// Recebe o tamanho do vetor.
	printf("Insira o tamanho dos vetores : \n");
	scanf("%d",&i);
	float vetor[i],vetor2[i];
// Recebe os valores do vetor 1.
	printf("Insira os valores do vetor 1 : \n");
	for(j=0;j<i;j++){
		printf("Vetor 1 de posição [%d]",j+1);
		scanf("%f",&vetor[j]);
	}
// Recebe os valores do vetor 2.
	printf("Insira os valores do vetor 2 : \n");
	for(j=0;j<i;j++){
		printf("Vetor 2 de posição [%d]",j+1);
		scanf("%f",&vetor2[j]);
	}
// Calcula o produto interno entre os dois vetores.
	for(j=0;j<i;j++){
		produtoIn = produtoIn + (vetor[j] * vetor2[j]);
	}

	printf("Produto interno entre os vetores 1 e 2 : %f\n",produtoIn);

// Cálculo das normas dos dois vetores.

	for(j=0;j<i;j++){
		norma2 = norma2 + pow(vetor[j],2);
	}
	norma2 = sqrt(norma2);

	for(j=0;j<i;j++){
		norma2b = norma2b + pow(vetor2[j],2);
	}
	norma2b = sqrt(norma2b);
// Cálculo do arco coseno através da fórmula u.v/||u||.||v||.
	arcocosen = produtoIn/(norma2*norma2b);
	printf("Arco coseno : %f\n",arcocosen);
	arcocosen = acos(arcocosen)*val; // Transforma arco coseno em angulo.
		printf("Angulo: %f\n",arcocosen);



}