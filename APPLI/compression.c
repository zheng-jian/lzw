#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "compression.h"
#include "dictionnaire.h"

void codage(char *input, int taille){
	char *w=input;
	char *wa=NULL;
	int longeur=0;

	initialiser();

	if(*w==NULL)
		printf("le contenu est NULL");
	else{
		for(int i=0;i<taille;i++){
			char *temporaire=malloc(strlen(wa)+strlen(w[i])+1);
			if(temporaire==NULL) exit(1);

			strcpy(temporaire,wa);
			strcat(temporaire,w[i]);

			longeur=strlen(wa)+1;

			int result=SequenceVersCode(temporaire,longeur);

			if(result==-1){
				printf("%s ",&temporaire);          //1er version
				int code_pre=SequenceVersCode(wa,longeur-1);
				printf("%d\n",code_pre);
				Inserer(code_pre,SequenceVersCode(w[i],1));
				*wa==NULL;
			}
			else{
				*wa=*temporaire;
			}


		}
	}
}

int main(){
	codage("Bonjour, bo bo",14);
}