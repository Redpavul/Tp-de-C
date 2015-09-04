#include<stdio.h>
#include<stdlib.h>
#include "entree_sortie.h"

#define MIROIR_HORIZONTAL 1
#define MIROIR_VERTICAL 0

void AfficherImage(char *nomFichier)
{

	char temp[200] = {0} ;
	sprintf(temp,"eog %s &", nomFichier);
	system(temp);

}


unsigned char* CreerImage(int largeur, int hauteur)
{

	return malloc((15+largeur*hauteur)*sizeof(unsigned char));

}

void Seuillage(unsigned char* image, int largeur, int hauteur, unsigned char seuil)
{

	int i,j,temp;
	temp=0;
	for(i=0;i<hauteur;i++)
	{
		for(j=0;j<largeur;j++)
		{

			if(image[temp]<seuil)
				image[temp]=0;
			else
				image[temp]=255;
			temp++;
			

		}
	}

}



void Degrade(unsigned char * image, int largeur, int hauteur)
{
	int i,j;
	
	
	
	
		int temp = 0 ;

	for(i=0;i<hauteur;i++)
	{
		for(j=0;j<largeur;j++)
		{

			image[j*largeur+i]=temp;
/*			if(t+1>div)
			{
				t=0;
*/				temp++;
//			}
//			else
//				t++;
		}
	}

}

void Negatif (unsigned char* image, int largeur, int hauteur)
{

	int i,j,temp;
	temp=0;
	for(i=0;i<hauteur;i++)
	{
		for(j=0;j<largeur;j++)
		{

			image[temp]=255-image[temp];
			temp++;

		}
	}

}


void Miroir( unsigned char* image, int largeur, int hauteur, char type)
{

	int i,a,f;
	unsigned char t;
	int j= 0;
	a=0;


	if(type==1)
	{
		for(i=0;i<largeur;i++)
		{
			f=(hauteur-1)*(largeur-1)+i;
			a=j;

			while(a<f)
			{
				t=image[a];
				image[a]=image[f];
				image[f]=t;
				f-=largeur;
				a+=largeur;
			}
			j++;
		}

	}
	else
	{
		for(i=0;i<hauteur;i++)
		{
			f=(j+1)* largeur -1 ;
			a=(j*largeur);
			while(a<f)	
			{
				t=image[a];
				image[a]=image[f];
				image[f]=t;
				a++;
				f--;
			}
			j++;
		}
	}

}

int main()
{

	unsigned char * f;
	//const char * nf = "guadalest.pgm";
	int hauteur=300;
	int largeur=256;
	
	//f= CreerImage(largeur, hauteur);
	f = LireImagePGM("guadalest.pgm",&largeur,&hauteur);
	//Degrade(f, largeur, hauteur);
	//Seuillage(f, largeur, hauteur, 127);
	Miroir(f,largeur,hauteur,MIROIR_HORIZONTAL);
	EcrireImagePGM("noir.pgm", f, largeur, hauteur);
	AfficherImage("noir.pgm");
	
	free(f);
	return EXIT_SUCCESS;
}
