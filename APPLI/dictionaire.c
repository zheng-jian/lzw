#include "dictionaire.h"

void initialiser(){
	for(int i=0;i<256;i++){
		char c=(char) i;
		dico[i].mot= c;
		dico[i].prefixe=-1;
		dico[i].longeur=1;
	}
	for(int i=256;i<=MAX;i++){
		dico[i].prefixe=-1;
		dico[i].longeur=0;
		
	}
	ind_dico=258;

	for(int i=0;i<256;i++)
		printf("%c ",dico[i].mot);
}

Code Inserer(Code prefixe, Code mono){
	elem q = dico[prefixe];
	elem p = dico[mono];
	dico[ind_dico].prefixe=prefixe;
	dico[ind_dico].longeur=q.longeur+p.longeur;
	dico[ind_dico].mot=dico[mono].mot;

	return ind_dico++;
}

uint8_t *CodeVerChaine(Code code, int *longeur){
	*longeur = dico[code].longeur;
	elem p=dico[code];
	uint8_t *val = malloc((*longeur)*sizeof(uint8_t));
	for(int i =*longeur;i>0;i--){
		val[i-1]=p.mot;
		if(p.prefixe != -1){
		p=dico[p.prefixe];
	}
	}	
  return (uint8_t *)val;
}


Code SequenceVersCode (uint8_t *sequence, int longeur){
	int result = -1;
	for(int i=0;i<ind_dico;i++){
		if(dico[i].longeur==longeur){
			elem p=dico[i];
			for(int j=longeur;j>0;j--){
				if(p.mot == sequence[j-1]){
					p=dico[p.prefixe];
				}
				else
					break;

			}
			result = i;
		}
	}
	
	return result;
}

int main()
{
	initialiser();
	int j=Inserer(98,97);
	printf("%d\n",j);
	int *taille;
	uint8_t *a=CodeVerChaine(258,taille);
	printf("%s\n",a );
	char *wa="ba";
	int c = SequenceVersCode(wa,2);
	printf("%d\n",c );
}
