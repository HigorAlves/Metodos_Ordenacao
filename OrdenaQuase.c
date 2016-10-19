#include "OrdenaQuase.h"
#include <stdlib.h>
#include <time.h>

void ordenaQuaseP(Pequeno *vet, int tam, int prcnt){
	int i, j, sorte,semente;
	Pequeno troca;
	srand(semente);
	for(i=0;i<tam;i++){
		sorte = rand()%101;
		if(sorte<=prcnt){
			j = rand()%tam;
			troca.chave = vet[i].chave;
			vet[i].chave = vet[j].chave;
			vet[j].chave = troca.chave;
		}
	}
}
void ordenaQuaseG(Grande *vet, int tam, int prcnt){
	int i, j, sorte,semente;
	Grande troca;
	srand( semente );
	for(i=0;i<tam;i++){
		sorte = rand()%101;
		if(sorte<=prcnt){
			j = rand()%tam;
			troca.chave = vet[i].chave;
			vet[i].chave = vet[j].chave;
			vet[j].chave = troca.chave;
		}
	}
}
