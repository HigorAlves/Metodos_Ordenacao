#ifndef TEMPO_H
#define TEMPO_H

#include <sys/time.h>
#include <sys/resource.h>

typedef struct tempo{
	double tempoU,tempoS;
	struct rusage resources;
	struct timeval inicioU, inicioS, fimU, fimS;
}Tempo;

void iniciaTempo(Tempo *t);
void finalizaTempo(Tempo *t,double *tempoU, double *tempoS);

#endif
