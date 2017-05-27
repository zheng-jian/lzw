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
	//	printf("%d\n",dico[code].longeur);
	longeur = &dico[code].longeur;
	//	printf("%d\n",*longeur );

	elem p=dico[code];
	//printf("%d\n",*longeur );
	uint8_t *val = malloc((*longeur)*sizeof(uint8_t));
	for(int i =*longeur;i>0;i--){
		val[i-1]=p.mot;
			p=dico[p.prefixe];
	}	
  return val;
}



Code SequenceVersCode (uint8_t *sequence, int longeur){
	int result = -1;

	if(longeur==1){
		return (int)sequence[0];
	}
	else{
	for(int i=0;i<ind_dico;i++){
		if(dico[i].longeur==longeur){
			elem p=dico[i];
			result=i;
			for(int j=longeur;j>0;j--){
				if(p.mot == sequence[j-1]){
					p=dico[p.prefixe];
				}
				else{
					result=-1;
					break;
				}

			}

			if(result==-1)
				continue;
			else
			{
				break;
			}
		}
	}
	return result;
}
}



/*int main()
{
	initialiser();
	int j=Inserer(97,98); //258 ab
		int k=Inserer(98,99);//259 bc
				int l=Inserer(99,97); //260 ca
								int m=Inserer(j,99); //261 abc



	printf("%d\n",m);
	int *taille;
	char * a=CodeVerChaine(261,taille);
	printf("%s\n",a );

	uint8_t *w="fabcd";
	int c = SequenceVersCode("abc",3);
	printf("%d\n",c );
}*/
