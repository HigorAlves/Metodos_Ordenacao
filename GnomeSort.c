# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <stdbool.h>
#include "registro.h"
#include "GnomeSort.h"

void swap(int *A, int *B){
	int C = *A;
	* A = *B;
	* B = C;
}

void GnomeSortP(Pequeno VectorSort[], int size){
	int next = 0, previous = 0;
	int i = 0;

	for(i = 0; i < size ; i++) {
		if(VectorSort[i].chave > VectorSort[i + 1].chave) {
			previous = i;
			next = i + 1;
			while(VectorSort[previous].chave > VectorSort[next].chave)  {
				swap(&VectorSort[previous].chave,&VectorSort[next].chave);
				if(previous > 0)
					previous--;
				if(next > 0)
					next--;
			}
		}
	}

}

void GnomeSortG(Grande VectorSort[], int size){
	int next = 0, previous = 0;
	int i = 0;

	for(i = 0; i < size ; i++) {
		if(VectorSort[i].chave > VectorSort[i + 1].chave) {
			previous = i;
			next = i + 1;
			while(VectorSort[previous].chave > VectorSort[next].chave)  {
				swap(&VectorSort[previous].chave,&VectorSort[next].chave);
				if(previous > 0)
					previous--;
				if(next > 0)
					next--;
			}
		}
	}

}
