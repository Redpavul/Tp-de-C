#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ON '*'
#define OFF '.'
#define len 14
#define t 100

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

int main(int argc, char ** argv)

{
	int i;
	int a = 0;
	int j,k,m;
	char o = ON;
	char f = OFF;
	int tps = t;
	int l=len;

	for(j=1 ; j<=argc-1 ; j+=2)
	{
		if(argv[j][0]=='-')
		{
			if(argv[j][1]=='a')
				o=argv[j+1][0];
			else if(argv[j][1]=='e')
				f=argv[j+1][0];
			else if(argv[j][1]=='t')
			{
				for(k=0; k<strlen(argv[j+1])-1;k++)
				{
					if(argv[j+1][k]>='0' && argv[j+1][k]<='9')
						m=1;
					else
						m=0;
				}
				if(m)
					tps= atoi(argv[j+1]);
				else
					printf("Argument -t non correct\n Usage : chenillard_v2 [-a <car_ampoule_allumee>] [-e <car_ampoule_eteinte>][-t <temporisation>] [-n <nombre_d_ampoules>]\n");
			}
			else if(argv[j][1]=='n')
			{
				for(k=0; k<strlen(argv[j+1])-1;k++)
				{
					if(argv[j+1][k]>='0' && argv[j+1][k]<='9')
						m=1;
					else
						m=0;
				}
				if(m)
					l=atoi(argv[j+1]);
				else
					printf("Argument -t non correct\n Usage : chenillard_v2 [-a <car_ampoule_allumee>] [-e <car_ampoule_eteinte>][-t <temporisation>] [-n <nombre_d_ampoules>]\n");

			}
			else
				printf("Argument -t non correct\n Usage : chenillard_v2 [-a <car_ampoule_allumee>] [-e <car_ampoule_eteinte>][-t <temporisation>] [-n <nombre_d_ampoules>]\n");

		}
		else
			printf("Argument -t non correct\n Usage : chenillard_v2 [-a <car_ampoule_allumee>] [-e <car_ampoule_eteinte>][-t <temporisation>] [-n <nombre_d_ampoules>]\n");
	}
	
	char r[l];

	while(1)
	{		
			
			for(i=0;i<l;i++)
			{
				r[i]=f;
			}
			r[a]=o;
			printf("%s\r",r);
			fflush(stdout);
			Temporisation(tps);

			if(a==l-1)
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
