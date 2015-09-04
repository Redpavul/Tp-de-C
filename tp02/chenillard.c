#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ON '*'
#define OFF '.'
#define len 14

void Temporisation(int n)
//------------------------------------------------------------------------------
// Fonction qui met n milli-secondes a s'executer
// C'est donc une temporisation de n ms
// necessite <stdio.h>
{
	clock_t start, stop ;

	n = n*CLOCKS_PER_SEC/1000 ; // clock() ne fonctionne pas forcement en milli-secondes
	start = clock() ;           // Top depart. start = l'heure de depart
	stop = start + n ;          // stop = l'heure de fin

	while(clock() < stop)       // On scrute l'heure tant qu'on n'a pas atteint la fin
	{
	} 
}

int main() 

{ 
	char r[len];
	int i;
	int a = 0;

	while(1)
	{
		for(i=0;i<len;i++)
		{
			r[i]=OFF;
		}
		r[a]=ON;
		printf("%s\r",r);
		fflush(stdout);
		Temporisation(200);

		if(a==len-1)
		{
			a=0;
		}
		else
		{
			a++;
		}
	}
	

	return EXIT_SUCCESS;
}

