#include "SelectionSort.h"

void selectionsortP(Pequeno num[], int tam)
{
  int i, j, min, aux;
  for (i = 0; i < (tam-1); i++)
   {
    min = i;
    for (j = (i+1); j < tam; j++) {
      if(num[j].chave < num[min].chave)
        min = j;
    }
    if (i != min) {
      aux = num[i].chave;
      num[i].chave = num[min].chave;
      num[min].chave = aux;
    }
  }
}

void selectionsortG(Grande num[], int tam)
{
  int i, j, min, aux;
  for (i = 0; i < (tam-1); i++)
   {
    min = i;
    for (j = (i+1); j < tam; j++) {
      if(num[j].chave < num[min].chave)
        min = j;
    }
    if (i != min) {
      aux = num[i].chave;
      num[i].chave = num[min].chave;
      num[min].chave = aux;
    }
  }
}
