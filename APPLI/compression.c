#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "compression.h"
#include "dictionaire.h"

void codage(char *input, int taille){
	char *w=input;
	char *wa=NULL;
	char *temporaire=NULL;
	int longeur=0;

	initialiser();


		for(int i=0;i<taille;i++){
			if(NULL==wa){
				wa=malloc(2*sizeof(char));
				wa[0]=w[i];
				wa[1]='\0';
				//printf("chushihua wa =%s\n",wa );

				//printf("wa=%s ,di %d ci xun huan \n", wa,i);

				if(taille-i>1){
					temporaire=malloc(3*sizeof(char));
					temporaire[0]=w[i];
					temporaire[1]=w[i+1];
					longeur=2;

					//printf("chushihuade temporaire=%s\n",temporaire );
				}
				else{
					temporaire=malloc(2*sizeof(char));
					temporaire[0]=w[i];
					longeur=1;
				}

			}
				else{
				temporaire=malloc((strlen(wa)+2)*sizeof(char));
				strcpy(temporaire,wa);
			    strcat(temporaire,&w[i]);
			    longeur=strlen(temporaire);


				}


			int result=SequenceVersCode(temporaire,longeur);

			if(result==-1 && longeur!=1 ){
				int code=SequenceVersCode(wa,strlen(wa));
				printf("%d  ",code);
				//printf("%s\n",wa );
				int q=Inserer(code,SequenceVersCode(&w[i+1],1));
				//printf("%d\n",q );
				free(wa);
				wa=NULL;
				//printf("jieshushi de wa=%s\n\n", wa);

				free(temporaire);
				temporaire=NULL;


			}
			else if(result!=-1 && taille-1==i){
				int code=SequenceVersCode(temporaire,1);
				printf("%d\n",code);
				free(wa);
				wa=NULL;
				free(temporaire);
				temporaire=NULL;
				break;
			}
			else if(result==-1 && longeur==1){
				printf("%d\n",result);
			}
			else{
				free(wa);
				wa=NULL;
				wa=malloc(longeur*sizeof(char));
				strcpy(wa,temporaire);
				if(taille-2==i){
					printf("%d",result);
					break;
				}
				free(temporaire);
				temporaire=NULL;

			}


		}
	
}

int main(){
	codage("abcabcabc",9);
	int *taille;
	printf("\n\n");
/*	char *a=CodeVerChaine(258,taille);
	char *b=CodeVerChaine(259,taille);

	printf("%s\n",a);
	printf("%s\n",b);
*/
	return 0;
}