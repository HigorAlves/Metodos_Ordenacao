#include "QuickSort.h"

void quicksortP(Pequeno *vet, int esq, int dir) {
	    int i, j, x, y;
	    i = esq;
	    j = dir;
	    x = vet[(esq + dir) / 2].chave;

    while(i <= j){
        while(vet[i].chave < x && i < dir){
            i++;
        }
        while(vet[j].chave > x && j > esq){
            j--;
        }
        if(i <= j){
            y = vet[i].chave;
            vet[i].chave = vet[j].chave;
            vet[j].chave = y;
            i++;
            j--;
        }
    }
    if(j > esq){
        quicksortP(vet, esq, j);
    }
    if(i < dir){
        quicksortP(vet,  i, dir);
    }
}

 void quicksortG(Grande *vet, int esq, int dir) {
 	int i, j, x, y;
    	i = esq;
    	j = dir;
    	x = vet[(esq + dir) / 2].chave;

    while(i <= j){
        while(vet[i].chave < x && i < dir){
            i++;
        }
        while(vet[j].chave > x && j > esq){
            j--;
        }
        if(i <= j){
            y = vet[i].chave;
            vet[i].chave = vet[j].chave;
            vet[j].chave = y;
            i++;
            j--;
        }
    }
    if(j > esq){
        quicksortG(vet, esq, j);
    }
    if(i < dir){
        quicksortG(vet,  i, dir);
    }
}
