#ifndef _DICTIONAIRE_
#define _DICTIONAIRE_

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "string.h"

#define MAX 4096

typedef int Code;

typedef struct{
	char used;
	int longeur;
	char *mot;
}

int ind_dico;

elem dico[MAX];

void initialiser();

Code Inserer(Code prefixe, Code mono);

uint8_t *CodeVerChaine(Code code,int *longeur);

Code SéquenceVersCode (uint8_t *sequence, int longueur);

#endif