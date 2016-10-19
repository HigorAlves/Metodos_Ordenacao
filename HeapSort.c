#include "HeapSort.h"

void heapsortP(Pequeno a[], int n) {
   int i = n / 2, mae, filha, t;
   for (;;) {
      if (i > 0) {
          i--;
          t = a[i].chave;
      } else {
          n--;
          if (n == 0) return;
          t = a[n].chave;
          a[n].chave = a[0].chave;
      }
      mae = i;
      filha = i * 2 + 1;
      while (filha < n) {
          if ((filha + 1 < n)  &&  (a[filha + 1].chave > a[filha].chave))
              filha++;
          if (a[filha].chave > t) {
             a[mae].chave = a[filha].chave;
             mae = filha;
             filha = mae * 2 + 1;
          } else {
            break;
          }
      }
      a[mae].chave = t;
   }
}

void heapsortG(Grande a[], int n) {
   int i = n / 2, mae, filha, t;
   for (;;) {
      if (i > 0) {
          i--;
          t = a[i].chave;
      } else {
          n--;
          if (n == 0) return;
          t = a[n].chave;
          a[n].chave = a[0].chave;
      }
      mae = i;
      filha = i * 2 + 1;
      while (filha < n) {
          if ((filha + 1 < n)  &&  (a[filha + 1].chave > a[filha].chave))
              filha++;
          if (a[filha].chave > t) {
             a[mae].chave = a[filha].chave;
             mae = filha;
             filha = mae * 2 + 1;
          } else {
            break;
          }
      }
      a[mae].chave = t;
   }
}
