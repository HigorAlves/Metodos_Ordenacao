#ifndef REGISTRO_H
#define REGISTRO_H
#include <math.h>

typedef struct pequeno{
	int chave;
}Pequeno;

typedef struct grande{
	int chave;
	char nome[60];
	char telefone[11];
	char cpf[11];
	char endereco[100];
	char outraString1[60];
	char outraString2[70];
	char outraString3[50];
	char outraString4[90];
}Grande;
#endif
