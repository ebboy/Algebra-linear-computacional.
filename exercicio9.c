#include <stdio.h>
#include <math.h>
#include <stdlib.h>



int main(){
	int i,j;
	float norma1=0,norma1b=0,norma2=0,norma2b=0,normai=0,normaib=0,maior=0,soma=0,distancia=0;
// Recebe o tamanho do vetor 1.
	printf("Insira o tamanho do vetor: \n");
	scanf("%d",&i);
	float vetor[i];
// Zera todos os valores do vetor 1.
	for(j=0;j<i;j++){
		vetor[j] = 0;
	}
// Recebe todos os valores do vetor 1.
	for(j=0;j<i;j++){
		scanf("%f",&vetor[j]);
	}
// Calcula a norma 2 do vetor 1.
	for(j=0;j<i;j++){
		norma2 = norma2 + pow(vetor[j],2);
	}
	norma2 = sqrt(norma2);

	printf("A norma 2 é : %f \n",norma2);
// Calcula a norma 1 do vetor 1.
	for(j=0;j<i;j++){
		if(vetor[j]<0)
			vetor[j] = vetor[j]*-1;
		soma = soma + vetor[j];
	}
	norma1 = soma;
	printf("A norma 1 é : %f \n",norma1);
// Calcula norma infinita do vetor 1.
	for(j=0;j<i;j++){
		if(vetor[j]<0)
			vetor[j] = vetor[j]*-1;
		if(maior<vetor[j])
			maior = vetor[j];
	}
	normai = maior;
	printf("A norma infinita é : %f\n",normai);
// Recebe o tamanho do vetor 2.
	printf("Insira o tamanho do vetor 2 : \n");
	scanf("%d",&i);
	float vetor2[i];
// Zera os valores do vetor 2.
	for(j=0;j<i;j++){
		vetor2[j] = 0;
	}
// Recebe os valores do vetor 2.
	for(j=0;j<i;j++){
		scanf("%f",&vetor2[j]);
	}
// Calcula a norma 2 do vetor 2.
	for(j=0;j<i;j++){
		norma2b = norma2b + pow(vetor2[j],2);
	}
	norma2b = sqrt(norma2b);

	printf("A norma 2 é : %f \n",norma2b);	
	soma = 0; // Zera a soma, pois a variável ja foi usada no vetor 1.
	// Calcula a norma 1 do vetor 2.
	for(j=0;j<i;j++){
		if(vetor2[j]<0)
			vetor2[j] = vetor2[j]*-1;
		soma = soma + vetor2[j];
	}
	norma1b = soma;
	printf("A norma 1 é : %f \n",norma1b);
	maior = 0; // Zera a maior, pois a variavel ja foi usada no vetor 1.
// Calcula a norma infinita do vetor 2.
	for(j=0;j<i;j++){
		if(vetor2[j]<0)
			vetor2[j] = vetor2[j]*-1;
		if(maior<vetor2[j])
			maior = vetor2[j];
	}
	normaib = maior;
	printf("A norma infinita é : %f\n",normaib);
// Calcula as distancias entre os vetores em todas as normas.
	distancia = sqrt(pow(norma1 - norma1b,2));
	printf("Distancia de norma 1 : %f\n",distancia);
	distancia = sqrt(pow(norma2 - norma2b,2));
	printf("Distancia de norma 2 : %f\n",distancia);
	distancia = sqrt(pow(normai - normaib,2));
	printf("Distancia de norma infinita : %f\n",distancia);



	
}

