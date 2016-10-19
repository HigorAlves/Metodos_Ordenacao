#include <stdio.h>
#include <stdlib.h>
#include "ShellSort.h"

void shellSortP(Pequeno *vet, int size) {
    int i , j , value;
    int gap = 1;
    while(gap < size) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value = vet[i].chave;
            j = i - gap;
            while (j >= 0 && value < vet[j].chave) {
                vet [j + gap].chave = vet[j].chave;
                j -= gap;
            }
            vet [j + gap].chave = value;
        }
    }
}

void shellSortG(Grande *vet, int size) {
    int i , j , value;
    int gap = 1;
    while(gap < size) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value = vet[i].chave;
            j = i - gap;
            while (j >= 0 && value < vet[j].chave) {
                vet [j + gap].chave = vet[j].chave;
                j -= gap;
            }
            vet [j + gap].chave = value;
        }
    }
}
