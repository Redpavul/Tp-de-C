#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SIZE 10
#define OK 0
#define FIN 1

//----------------------------------------------------
int LireUneLigne(char*buf, int size, FILE* f)
// Pascal Bertolino 2005
// lit une ligne du fichier f
// met dans buf les size-1 premiers caracteres maxi
// jette les suivants s'ils existent
// enleve le '\n' de la fin s'il y est
// marche aussi avec les chaines vides
// retourne FIN si rien à lire, OK sinon
//----------------------------------------------------
{
	char trash[64] ;  // chaine poubelle
	char* res ;       // retour de la fonction fgets
		
	res = fgets(buf, size, f) ; // recupere le debut dans buf
	if (!res)
		return FIN ;

	if (strchr(buf, '\n') == NULL) 
	{      // on n'a pas lu le RC donc on n'a pas tout lu
		do // on jette la suite
		{
			res = fgets(trash, 64, f) ;
			if (res == NULL)
				return FIN ;
			//printf("*jette:%s*\n", trash) ;		
		}
		while (strchr(trash, '\n') == NULL) ;
	}
	else
	{
		*strchr(buf, '\n') = '\0' ; // remplace '\n' par '\0'
	}
		
	return OK ;			
}


int main() 

{
	char i[64];
	printf("Entrez une chaine de caractère quelconque : ");
	LireUneLigne(i,64,stdin);
	
	int j ;
	int t[256]= {0};
	for(j=0 ; j<strlen(i) ; j++)
	{
		t[i[j]]++;			
	}

	int f;
	for(f=0 ; f<256 ; f++)
	{
		if(t[f]>=1)
			printf("%c : %d \n",f,t[f]);
	}
 

	return EXIT_SUCCESS;
}
