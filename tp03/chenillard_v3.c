#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ON '*'
#define OFF '.'
#define len 14
#define t 100

typedef unsigned int interrupteurs_t;

int ValeurAmpoule(unsigned char inter, int i)
{
	return i & inter;
}

unsigned char Inversion(unsigned char inter)
{
	return ~inter;
}

unsigned char RotationGauche(unsigned char inter)
{
	int tmp;
	tmp=inter;
	inter<<= 1;
	if(inter<tmp)
		inter++;
	return inter;
}

unsigned char RotationDroite(unsigned char inter)
{
	if(inter%2==1)
	{
		inter>>=1;
		inter+=128;
	}
	else
		inter >>=1;
	return inter;
}

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
	int l=8;
	unsigned char inter=0x01;
	unsigned char r[8*sizeof(interrupteurs_t)+1]={0};

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
	
	int d = 1;

	while(1)
	{		
			d=1;
			//inter= RotationGauche(inter);
			inter= RotationDroite(inter);
			for(i=l-1;i>=0;i--)
			{
				if(ValeurAmpoule(inter,d))
					r[i]=o;
				else
					r[i]=f;

				d<<=1;
			}
			printf("%s\r",r);
			fflush(stdout);
			Temporisation(500);
			//inter=Inversion(inter);
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
