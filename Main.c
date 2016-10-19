//-----------------------------------------//
// Trabalho feito por Higor Henrique Alves //
//               Data 29/05/2016           //
//-----------------------------------------//
#include <stdio.h>
#include <stdlib.h>
#include "registro.h"
#include "HeapSort.h"
#include "QuickSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "ShellSort.h"
#include "OrdenaQuase.h"
#include "GnomeSort.h"
#include "tempo.h"
#include <sys/time.h>
#include <sys/resource.h>

		int main(int argc, char *argv[]){
			FILE *saida = fopen("saida.txt","w");
			int i,TAM,q,p,vn[6]={20,500,1000,50000,200000,1000000},k,o,h;
			Tempo t;

			//variáveis responsáveis pela contagem de tempo de usuário e sistema.
			double tempoU,tempoS;
			struct rusage resources;
			struct timeval inicioU, inicioS, fimU, fimS;

			/*Variavel TAM se iguala ao vetor vn para modificar o número de chaves
			a serem geradas e ordenadas, no caso, 6 diferentes*/
			for (p = 0; p < 10; p++){
				for(q = 0; q < 6; q++){

						TAM=vn[q];
						fprintf(saida, "\nROUND: %d\t TAM: %d \n",p,TAM);

				Pequeno *vPHeapA = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGHeapA = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPHeapC = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGHeapC = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPHeapD = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGHeapD = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPHeapCT = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGHeapCT = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPHeapDT = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGHeapDT = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPQuickA = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGQuickA = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPQuickC = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGQuickC = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPQuickD = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGQuickD = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPQuickCT = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGQuickCT = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPQuickDT = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGQuickDT = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPSelectA = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGSelectA = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPSelectC = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGSelectC = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPSelectD = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGSelectD = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPSelectCT= (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGSelectCT = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPSelectDT = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGSelectDT = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPInsertA = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGInsertA = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPInsertC = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGInsertC = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPInsertD = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGInsertD = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPInsertCT = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGInsertCT = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPInsertDT = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGInsertDT = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPShellA = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGShellA = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPShellC = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGShellC = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPShellD = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGShellD = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPShellCT = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGShellCT = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPShellDT = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGShellDT = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPGnomeA = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGGnomeA = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPGnomeC = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGGnomeC = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPGnomeD = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGGnomeD = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPGnomeCT = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGGnomeCT = (Grande *) malloc(sizeof(Grande) * TAM);

				Pequeno *vPGnomeDT = (Pequeno *) malloc(sizeof(Pequeno) * TAM);
				Grande *vGGnomeDT = (Grande *) malloc(sizeof(Grande) * TAM);

			//Gerador de chaves.
			for (i = 0; i < TAM; i++) {
				vPHeapA[i].chave = rand() % TAM;
				vGHeapA[i].chave = rand() % TAM;
				//Itens Pequenos
				vPQuickA[i].chave = vPHeapA[i].chave;
				vPSelectA[i].chave = vPHeapA[i].chave;
				vPInsertA[i].chave = vPHeapA[i].chave;
				vPShellA[i].chave = vPHeapA[i].chave;
				vPGnomeA[i].chave = vPHeapA[i].chave;

				//Itens Grandes
				vGQuickA[i].chave = vGHeapA[i].chave;
				vGSelectA[i].chave = vGHeapA[i].chave;
				vGInsertA[i].chave = vGHeapA[i].chave;
				vGShellA[i].chave = vGHeapA[i].chave;
				vGGnomeA[i].chave = vGHeapA[i].chave;
			}
			//Chaves quase totalmente ordenadas e ordenadas DECRESCENTES.
			for (o = TAM; o > 0; o--){
				vPQuickDT[o].chave = o;
				vGQuickDT[o].chave = o;
				vPQuickD[o].chave = o;
				vGQuickD[o].chave = o;
				h++;
			}
			ordenaQuaseP(vPQuickDT,TAM,5);
			ordenaQuaseG(vGQuickDT,TAM,5);
			//Chaves quase totalmente ordenadas e ordenadas CRESCENTES.
			for ( k = 0; k < TAM; k++) {
				vPQuickCT[k].chave=k;
				vGQuickCT[k].chave=k;
				vPQuickC[k].chave=k;
				vGQuickC[k].chave=k;
			}
			ordenaQuaseP(vPQuickCT,TAM,5);
			ordenaQuaseG(vGQuickCT,TAM,5);

		for(k = 0; k < TAM; k++){
			//Chaves Pequenas CRESCENTES QTO
			vPHeapCT[k].chave = vPQuickCT[k].chave;
			vPShellCT[k].chave = vPQuickCT[k].chave;
			vPSelectCT[k].chave = vPQuickCT[k].chave;
			vPInsertCT[k].chave = vPQuickCT[k].chave;
			vPGnomeCT[k].chave = vPQuickCT[k].chave;
			//Chaves Grandes CRESCENTES QTO
			vGHeapCT[k].chave = vGQuickCT[k].chave;
			vGShellCT[k].chave = vGQuickCT[k].chave;
			vGSelectCT[k].chave = vGQuickCT[k].chave;
			vGInsertCT[k].chave = vGQuickCT[k].chave;
			vGGnomeCT[k].chave = vGQuickCT[k].chave;
			//Chaves Pequenas DECRESCENTES QTO
			vPHeapDT[k].chave = vPQuickDT[k].chave;
			vPShellDT[k].chave = vPQuickDT[k].chave;
			vPSelectDT[k].chave = vPQuickDT[k].chave;
			vPInsertDT[k].chave = vPQuickDT[k].chave;
			vPGnomeDT[k].chave = vPQuickDT[k].chave;
			//Chaves Grandes DECRESCENTES QTO
			vGQuickDT[k].chave = vGHeapDT[k].chave;
			vGShellDT[k].chave = vGQuickDT[k].chave;
			vGSelectDT[k].chave = vGQuickDT[k].chave;
			vGInsertDT[k].chave = vGQuickDT[k].chave;
			vGGnomeDT[k].chave = vGQuickDT[k].chave;
			//Chaves Pequenas	CRESCENTES
			vPHeapC[k].chave = vPQuickC[k].chave;
			vPShellC[k].chave = vPQuickC[k].chave;
			vPSelectC[k].chave = vPQuickC[k].chave;
			vPInsertC[k].chave = vPQuickC[k].chave;
			vPGnomeC[k].chave = vPQuickC[k].chave;
			//Chaves Grandes CRESCENTES
			vGHeapC[k].chave = vGQuickC[k].chave;
			vGShellC[k].chave = vGQuickC[k].chave;
			vGSelectC[k].chave = vGQuickC[k].chave;
			vGInsertC[k].chave = vGQuickC[k].chave;
			vGGnomeC[k].chave = vGQuickC[k].chave;
			//Chaves Pequenas DECRESCENTES
			vPHeapD[k].chave = vPQuickD[k].chave;
			vPShellD[k].chave = vPQuickD[k].chave;
			vPSelectD[k].chave = vPQuickD[k].chave;
			vPInsertD[k].chave = vPQuickD[k].chave;
			vPGnomeD[k].chave = vPQuickD[k].chave;
			//Chaves Grandes DECRESCENTES
			vGQuickD[k].chave = vGHeapD[k].chave;
			vGShellD[k].chave = vGQuickD[k].chave;
			vGSelectD[k].chave = vGQuickD[k].chave;
			vGInsertD[k].chave = vGQuickD[k].chave;
			vGGnomeD[k].chave = vGQuickD[k].chave;
		}
			fprintf(saida,"\n");
			//Fim chaves QTO
			//Chama o HEAP
			iniciaTempo(&t);
			heapsortP(vPHeapA,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário HEAP Pequeno Aleatorio %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema HEAP Pequeno Aleatorio %d: %.9f\n",TAM,tempoS);

			//Contagem tempo chave grande crescente HEAP;
			iniciaTempo(&t);
			heapsortG(vGHeapA,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário HEAP Grande Aleatorio %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema HEAP Grande Aleatorio %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");

			//Crescente
			//Contagem de tempo Chave Decrescente.
			iniciaTempo(&t);
		 	heapsortP(vPHeapC,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário HEAP Pequeno Crescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema HEAP Pequeno Crescente %d: %.9f\n",TAM,tempoS);

			//Contagem de tempo Chave Grande Decrescente HEAP
			iniciaTempo(&t);
			heapsortG(vGHeapC,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário HEAP Grande Crescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema HEAP Grande Crescente %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");

			//Decrescente
		 	//Contagem de tempo Chave Decrescente.
			iniciaTempo(&t);
		 	heapsortP(vPHeapD,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário HEAP Pequeno Decrescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema HEAP Pequeno Decrescente %d: %.9f\n",TAM,tempoS);

			//Contagem de tempo Chave Grande Decrescente HEAP
			iniciaTempo(&t);
			heapsortG(vGHeapD,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário HEAP Grande Decrescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema HEAP Grande Decrescente %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");

			//QUASE TOTALMENTE ORDENADO HEAP
			//Contagem de tempo Chave Pequena Crescente.
		 	iniciaTempo(&t);
			heapsortP(vPHeapCT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
		 	//imprime os tempos de usuário e sistema.
		 	fprintf(saida,"Tempo de usuário HEAP Pequeno QTO Crescente %d: %.9f\n",TAM,tempoU);
		 	fprintf(saida,"Tempo de sistema HEAP Pequeno QTO Crescente %d: %.9f\n",TAM,tempoS);
			//Contagem de tempo Chave Grande Crescente.
			iniciaTempo(&t);
			heapsortG(vGHeapCT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
		 	//imprime os tempos de usuário e sistema.
		 	fprintf(saida,"Tempo de usuário HEAP Grande QTO Crescente %d: %.9f\n",TAM,tempoU);
		 	fprintf(saida,"Tempo de sistema HEAP Grande QTO Crescente %d: %.9f\n",TAM,tempoS);
		 	fprintf(saida,"\n");

		 	//Decrescente
			//Contagem de tempo Chave pequena Decrescente QTO.
			iniciaTempo(&t);
			heapsortP(vPHeapDT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
		 	//imprime os tempos de usuário e sistema.
		 	fprintf(saida,"Tempo de usuário HEAP Pequeno Decrescente QTO %d: %.9f\n",TAM,tempoU);
		 	fprintf(saida,"Tempo de sistema HEAP Pequeno Decrescente QTO %d: %.9f\n",TAM,tempoS);

			//Contagem de tempo Chave Grande Decrescente.
		 	//Inicia a contagem de tempo do usuario e sistema.
			iniciaTempo(&t);
			heapsortG(vGHeapDT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
		 	//imprime os tempos de usuário e sistema.
		 	fprintf(saida,"Tempo de usuário HEAP Grande Decrescente QTO %d: %.9f\n",TAM,tempoU);
		 	fprintf(saida,"Tempo de sistema HEAP Grande Decrescente QTO %d: %.9f\n",TAM,tempoS);
		 	fprintf(saida,"\n");
			//FIM HEAP

			//CHAMA QUICK

			//Aleatorio
			//Contagem chave Pequena Crescente Aleatorio
			iniciaTempo(&t);
			quicksortP(vPQuickA, 0, (TAM - 1));
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário QUICK Pequeno Aleatorio %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema QUICK Pequeno Aleatorio %d: %.9f\n",TAM,tempoS);

			//Chave Grande Crescente Aleatorio
			iniciaTempo(&t);
			quicksortG(vGQuickA, 0, (TAM - 1));
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário QUICK Grande Aleatorio %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema QUICK Grande Aleatorio %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");

			//Crescente
			//Contagem chave Pequena Crescente
			iniciaTempo(&t);
			quicksortP(vPQuickC, 0, (TAM - 1));
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário QUICK Pequeno Crescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema QUICK Pequeno Crescente %d: %.9f\n",TAM,tempoS);

			//Chave Grande Crescente
			iniciaTempo(&t);
			quicksortG(vGQuickC, 0, (TAM - 1));
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário QUICK Grande Crescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema QUICK Grande Crescente %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");

			//Decrescente
			//Chave Pequena Decrescente
			iniciaTempo(&t);
			quicksortP(vPQuickD, 0, (TAM - 1));
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário QUICK Pequeno Decrescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema QUICK Pequeno Decrescente %d: %.9f\n",TAM,tempoS);
			//Chave Grande Decrescente
			iniciaTempo(&t);
			quicksortG(vGQuickD, 0, (TAM - 1));
			finalizaTempo(&t, &tempoU, &tempoS);
			//Contagem chave grande Decrescente
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário QUICK Grande Decrescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema QUICK Grande Decrescente %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");

			//Chave Pequena Crescente QTO
			iniciaTempo(&t);
			quicksortP(vPQuickCT, 0, (TAM - 1));
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário QUICK Pequeno QTO Crescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema QUICK Pequeno QTO Crescente %d: %.9f\n",TAM,tempoS);

			//Chave Grande Crescente QTO
			iniciaTempo(&t);
			quicksortG(vGQuickCT, 0, (TAM - 1));
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário QUICK Grande QTO Crescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema QUICK Grande QTO Crescente %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");

			//Decrescente QUICK Decrescente QTO
			//Chave Pequena Decrescente
			iniciaTempo(&t);
			quicksortP(vPQuickDT, 0, (TAM - 1));
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário QUICK Pequeno Decrescente QTO %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema QUICK Pequeno Decrescente QTO %d: %.9f\n",TAM,tempoS);

			//Chave Grande Decrescente
			iniciaTempo(&t);
			quicksortG(vGQuickDT, 0, (TAM - 1));
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário QUICK Grande Decrescente QTO %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema QUICK Grande Decrescente QTO %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");
			//FIM QUICK QTO

		 	//CHAMA SELECTIONSORT
			//Chave Pequena Aleatorio
			iniciaTempo(&t);
			selectionsortP(vPSelectA,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário SELECT Pequeno Aleatorio %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema SELECT Pequeno Aleatorio %d: %.9f\n",TAM,tempoS);

			//Chave Grande Aleatorio
			iniciaTempo(&t);
			selectionsortG(vGSelectA,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário SELECT Grande Aleatorio %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema SELECT Grande Aleatorio %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");

			//Crescente
			//Chave Pequena Crescente
			iniciaTempo(&t);
			selectionsortP(vPSelectC,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário SELECT Pequeno Crescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema SELECT Pequeno Crescente %d: %.9f\n",TAM,tempoS);

			//Chave Grande Aleatorio
			iniciaTempo(&t);
			selectionsortG(vGSelectC,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário SELECT Grande Crescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema SELECT Grande Crescente %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");

			//Decrescente SELECT
			//Inicia contagem de tempo chave pequena Decrescente
			iniciaTempo(&t);
			selectionsortP(vPSelectD,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário SELECT Pequeno Decrescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema SELECT Pequeno Decrescente %d: %.9f\n",TAM,tempoS);

			//Inicia contagem de tempo chave grande Decrescente
			iniciaTempo(&t);
			selectionsortG(vGSelectD,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
		 	//imprime os tempos de usuário e sistema.
		 	fprintf(saida,"Tempo de usuário SELECT Grande Decrescente %d: %.9f\n",TAM,tempoU);
		 	fprintf(saida,"Tempo de sistema SELECT Grande Decrescente %d: %.9f\n",TAM,tempoS);
		 	fprintf(saida,"\n");

			//QUASE TOTALMENTE ORDENADO SELECT QTO
			//Chave Pequeno Crescente QTO
			iniciaTempo(&t);
			selectionsortP(vPSelectCT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário SELECT Pequeno QTO Crescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema SELECT Pequeno QTO Crescente%d: %.9f\n",TAM,tempoS);

			//Chave Grande Crescente QTO
			iniciaTempo(&t);
			selectionsortG(vGSelectCT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário SELECT Grande QTO Crescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema SELECT Grande QTO Crescente %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");

			//Chave Pequena Decrescente QTO
			iniciaTempo(&t);
			selectionsortP(vPSelectDT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário SELECT Pequeno Decrescente QTO %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema SELECT Pequeno Decrescente QTO %d: %.9f\n",TAM,tempoS);

			//Chave Grande Decrescente QTO
			iniciaTempo(&t);
			selectionsortG(vGSelectDT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
		 	//imprime os tempos de usuário e sistema.
		 	fprintf(saida,"Tempo de usuário SELECT Grande Decrescente QTO %d: %.9f\n",TAM,tempoU);
		 	fprintf(saida,"Tempo de sistema SELECT Grande Decrescente QTO %d: %.9f\n",TAM,tempoS);
		 	fprintf(saida,"\n");
			//FIM SELECT

			//CHAMA SHELLSORT
			//Chave Pequeno  Aleatorio
			iniciaTempo(&t);
			shellSortP(vPShellA,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);

			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário SHELL Pequeno Aleatorio %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema SHELL Pequeno Aleatorio %d: %.9f\n",TAM,tempoS);

			//Chave Grande  Aleatorio
			iniciaTempo(&t);
 		 	shellSortG(vGShellA,TAM);
 		 	finalizaTempo(&t, &tempoU, &tempoS);
		 	//imprime os tempos de usuário e sistema.
		 	fprintf(saida,"Tempo de usuário SHELL Grande Aleatorio %d: %.9f\n",TAM,tempoU);
		 	fprintf(saida,"Tempo de sistema SHELL Grande Aleatorio %d: %.9f\n",TAM,tempoS);
		 	fprintf(saida,"\n");

			//Crescente
			//Chave Pequeno Crescente
			iniciaTempo(&t);
			shellSortP(vPShellC,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);

			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário SHELL Pequeno Crescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema SHELL Pequeno Crescente %d: %.9f\n",TAM,tempoS);

			//Chave Grande Crescente
			iniciaTempo(&t);
			shellSortG(vGShellC,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário SHELL Grande Crescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema SHELL Grande Crescente %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");

		 	//Decrescente SHELL
		 	//Chave Pequeno Decrescente
			iniciaTempo(&t);
			shellSortP(vPShellD,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário SHELL Pequeno Decrescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema SHELL Pequeno Decrescente %d: %.9f\n",TAM,tempoS);

			//Chave Grande Decrescente
			iniciaTempo(&t);
			shellSortG(vGShellD,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
	 		//imprime os tempos de usuário e sistema.
	 		fprintf(saida,"Tempo de usuário SHELL Grande Decrescente %d: %.9f\n",TAM,tempoU);
	 		fprintf(saida,"Tempo de sistema SHELL Grande Decrescente %d: %.9f\n",TAM,tempoS);
	 		fprintf(saida,"\n");

			//Chave Pequeno QTO Crescente
			iniciaTempo(&t);
			shellSortP(vPShellCT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário SHELL Pequeno QTO Crescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema SHELL Pequeno QTO Crescente %d: %.9f\n",TAM,tempoS);

			//Chave Grande QTO Crescente
			iniciaTempo(&t);
			shellSortG(vGShellCT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);

			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário SHELL Grande QTO Crescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema SHELL Grande QTO Crescente %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");

			//Decrescente SHELL
			//Chave Pequeno Decrescente QTO
			iniciaTempo(&t);
			shellSortP(vPShellDT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário SHELL Pequeno Decrescente QTO %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema SHELL Pequeno Decrescente QTO %d: %.9f\n",TAM,tempoS);

			//Chave Grande Decrescente QTO
			iniciaTempo(&t);
			shellSortG(vGShellDT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário SHELL Grande Decrescente QTO %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema SHELL Grande Decrescente QTO %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");
			//FIM SHELL QTO

		 	//CHAMA INSERTIONSORT
		 	//Chave Pequeno Aleatorio
			iniciaTempo(&t);
			insertionSortP(vPInsertA,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário INSERT Pequeno Aleatorio %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema INSERT Pequeno Aleatorio %d: %.9f\n",TAM,tempoS);

			//Chave Grande Aleatorio
			iniciaTempo(&t);
			insertionSortG(vGInsertA,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
	 		//imprime os tempos de usuário e sistema.
	 		fprintf(saida,"Tempo de usuário INSERT Grande Aleatorio %d: %.9f\n",TAM,tempoU);
	 		fprintf(saida,"Tempo de sistema INSERT Grande Aleatorio %d: %.9f\n",TAM,tempoS);
	 		fprintf(saida,"\n");

			//Crescente
			//Chave Pequeno Crescente
			iniciaTempo(&t);
			insertionSortP(vPInsertC,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário INSERT Pequeno Crescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema INSERT Pequeno Crescente %d: %.9f\n",TAM,tempoS);

			//Chave Grande Aleatorio
			iniciaTempo(&t);
			insertionSortG(vGInsertC,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário INSERT Grande Crescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema INSERT Grande Crescente %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");

			//Decrescente
	 		//Chave Pequeno Decrescente
			iniciaTempo(&t);
			insertionSortP(vPInsertD,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário INSERT Pequeno Decrescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema INSERT Pequeno Decrescente %d: %.9f\n",TAM,tempoS);

			//Chave Grande Decrescente
			iniciaTempo(&t);
			insertionSortG(vGInsertD,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário INSERT Grande Decrescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema INSERT Grande Decrescente %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");

			//INSERT QTO
			//Chave Pequeno Crescente QTO
			iniciaTempo(&t);
			insertionSortP(vPInsertCT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário INSERT Pequeno QTO Crescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema INSERT Pequeno QTO Crescente %d: %.9f\n",TAM,tempoS);

			//Chave Grande Crescente QTO
			iniciaTempo(&t);
			insertionSortG(vGInsertCT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário INSERT Grande QTO Crescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema INSERT Grande QTO Crescente %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");

			//Decrescente
			//Chave Pequeno Decrescente QTO
			iniciaTempo(&t);
			insertionSortP(vPInsertDT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário INSERT Pequeno Decrescente QTO %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema INSERT Pequeno Decrescente QTO %d: %.9f\n",TAM,tempoS);

			//Chave Grande Decrescente QTO
			iniciaTempo(&t);
			insertionSortG(vGInsertDT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário INSERT Grande Decrescente QTO %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema INSERT Grande Decrescente QTO %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");


			//CHAMA Gnome
			//Chave Pequeno Aleatorio
			iniciaTempo(&t);
			GnomeSortP(vPGnomeA,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário Gnome Pequeno Aleatorio %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema Gnome Pequeno Aleatorio %d: %.9f\n",TAM,tempoS);

			//Chave Grande Aleatorio
			iniciaTempo(&t);
			GnomeSortG(vGGnomeA,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário Gnome Grande Aleatorio %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema Gnome Grande Aleatorio %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");

			//Crescente
			//Chave Pequeno Crescente
			iniciaTempo(&t);
			GnomeSortP(vPGnomeC,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário Gnome Pequeno Crescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema Gnome Pequeno Crescente %d: %.9f\n",TAM,tempoS);

			//Chave Grande Aleatorio
			iniciaTempo(&t);
			GnomeSortG(vGGnomeC,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário Gnome Grande Crescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema Gnome Grande Crescente %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");

			//Decrescente
			//Chave Pequeno Decrescente
			iniciaTempo(&t);
			GnomeSortP(vPGnomeD,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário Gnome Pequeno Decrescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema Gnome Pequeno Decrescente %d: %.9f\n",TAM,tempoS);

			//Chave Grande Decrescente
			iniciaTempo(&t);
			GnomeSortG(vGGnomeD,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário Gnome Grande Decrescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema Gnome Grande Decrescente %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");

			//Gnome QTO
			//Chave Pequeno Crescente QTO
			iniciaTempo(&t);
			GnomeSortP(vPGnomeCT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário Gnome Pequeno QTO Crescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema Gnome Pequeno QTO Crescente %d: %.9f\n",TAM,tempoS);

			//Chave Grande Crescente QTO
			iniciaTempo(&t);
			GnomeSortG(vGGnomeCT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário Gnome Grande QTO Crescente %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema Gnome Grande QTO Crescente %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");

			//Decrescente QTO
			//Chave Pequeno Decrescente QTO
			iniciaTempo(&t);
			GnomeSortP(vPGnomeDT,TAM);
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário Gnome Pequeno Decrescente QTO %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema Gnome Pequeno Decrescente QTO %d: %.9f\n",TAM,tempoS);

			//Chave Grande Decrescente QTO
			iniciaTempo(&t);
			GnomeSortG(vGGnomeDT,TAM);;
			finalizaTempo(&t, &tempoU, &tempoS);
			//imprime os tempos de usuário e sistema.
			fprintf(saida,"Tempo de usuário GNOME Grande Decrescente QTO %d: %.9f\n",TAM,tempoU);
			fprintf(saida,"Tempo de sistema GNOME Grande Decrescente QTO %d: %.9f\n",TAM,tempoS);
			fprintf(saida,"\n");
				//FIM GNOME

			free(vPSelectA);
			free(vGSelectA);

			free(vPSelectC);
			free(vGSelectC);

			free(vPSelectD);
			free(vGSelectD);

			free(vPSelectCT);
			free(vGSelectCT);

			free(vPSelectDT);
			free(vGSelectDT);

			free(vPInsertA);
			free(vGInsertA);

			free(vPInsertC);
			free(vGInsertC);

			free(vPInsertD);
			free(vGInsertD);

			free(vPInsertCT);
			free(vGInsertCT);

			free(vPInsertDT);
			free(vGInsertDT);

			free(vPShellA);
			free(vGShellA);

			free(vPShellC);
			free(vGShellC);

			free(vPShellD);
			free(vGShellD);

			free(vPShellCT);
			free(vGShellCT);

			free(vPShellDT);
			free(vGShellDT);

			free(vPHeapA);
			free(vGHeapA);

			free(vPHeapC);
			free(vGHeapC);

			free(vPHeapD);
			free(vGHeapD);

			free(vPHeapCT);
			free(vGHeapCT);

			free(vPHeapDT);
			free(vGHeapDT);

			free(vPQuickA);
			free(vGQuickA);

			free(vPQuickC);
			free(vGQuickC);

			free(vPQuickD);
			free(vGQuickD);

			free(vPQuickCT);
			free(vGQuickCT);

			free(vPQuickDT);
			free(vGQuickDT);

			free(vPGnomeA);
			free(vGGnomeA);

			free(vPGnomeC);
			free(vGGnomeC);

			free(vPGnomeD);
			free(vGGnomeD);

			free(vPGnomeCT);
			free(vGGnomeCT);

			free(vPGnomeDT);
			free(vGGnomeDT);
		}
	}
			fclose(saida);
	return 0;
}
