#include "InsertionSort.h"

void insertionSortP(Pequeno array[], int tamanho) {
      int i, j, tmp;
      for (i = 1; i < tamanho; i++) {
            j = i;
            while (j > 0 && array[j - 1].chave > array[j].chave) {
                  tmp = array[j].chave;
                  array[j].chave = array[j - 1].chave;
                  array[j - 1].chave = tmp;
                  j--;
            }
      }
}

void insertionSortG(Grande array[], int tamanho) {
      int i, j, tmp;
      for (i = 1; i < tamanho; i++) {
            j = i;
            while (j > 0 && array[j - 1].chave > array[j].chave) {
                  tmp = array[j].chave;
                  array[j].chave = array[j - 1].chave;
                  array[j - 1].chave = tmp;
                  j--;
            }
      }
}
