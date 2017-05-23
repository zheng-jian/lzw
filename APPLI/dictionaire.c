#include "dictionaire.h"

void initialiser(){
	for(int i=0;i<258;i++){
		char c=(char) i;
		dico[i].mot= &c;
		dico[i].used= true;
		dico[i].longeur=1;
	}
	for(int i=258;i<=MAX;i++){
		dico[i].used=false;
		dico[i].longeur=0;
		dico[i].mot=NULL;
	}
	ind_dico=258;
}

Code Inserer(Code prefixe, Code mono){
	elem q = dico[prefixe];
	elem p = dico[mono];
	dico[ind_dico].used=true;
	dico[ind_dico].longeur=q.longeur+p.longeur;
	dico[ind_dico].mot=strcat(dico[ind_dico].mot,q.mot);
	dico[ind_dico].mot=strcat(dico[ind_dico].mot,p.mot);
	return ind_dico++;
}


uint8_t *CodeVerChaine(Code code, int *longeur){
  *longueur = dico[code].longueur;
  uint8_t val = malloc((*longueur)*sizeof(uint8_t));
  strcpy ((char *) val,dico[code].mot);
  return (uint8_t *)val;

}

Code SequenceVersCode (uint8_t *sequence, int longueur){
	int result = -1;
	

}
