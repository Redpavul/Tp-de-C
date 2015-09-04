#include<stdio.h>
#include<stdlib.h>
#include "entree_sortie.h"

#define MIROIR_HORIZONTAL 1
#define MIROIR_VERTICAL 0
#define DEBUG 0
#define OK 0
#define ERREUR 1

typedef struct Image 
{ 
  unsigned char* pixels ; 
  unsigned int largeur ; 
  unsigned int hauteur ; 
} t_image ;


void AfficherImage(char *nomFichier)
{

	char temp[200] = {0} ;
	sprintf(temp,"eog %s &", nomFichier);
	system(temp);

}


t_image* CreerImage(int largeur, int hauteur)
{
	t_image f;
	f.pixels=malloc((15+largeur*hauteur)*sizeof(unsigned char));
	f.hauteur=hauteur;
	f.largeur=largeur;
	return &f;

}

void Seuillage(t_image image,  unsigned char seuil)
{

	int i,j,temp;
	temp=0;
	for(i=0;i<image.hauteur;i++)
	{
		for(j=0;j<image.largeur;j++)
		{

			if(image.pixels[temp]<seuil)
				image.pixels[temp]=0;
			else
				image.pixels[temp]=255;
			temp++;
			

		}
	}

}



void Degrade(t_image image)
{
	int i,j;
	
	
	
	
		int temp = 0 ;

	for(i=0;i<image.hauteur;i++)
	{
		for(j=0;j<image.largeur;j++)
		{

			image.pixels[j*image.largeur+i]=temp;
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

void Negatif (t_image image)
{

	int i,j,temp;
	temp=0;
	for(i=0;i<image.hauteur;i++)
	{
		for(j=0;j<image.largeur;j++)
		{

			image.pixels[temp]=255-image.pixels[temp];
			temp++;

		}
	}

}


void Miroir( t_image  image, char type)
{

	int i,a,f;
	unsigned char t;
	int j= 0;
	a=0;


	if(type==1)
	{
		for(i=0;i<image.largeur;i++)
		{
			f=(image.hauteur-1)*(image.largeur-1)+i;
			a=j;

			while(a<f)
			{
				t=image.pixels[a];
				image.pixels[a]=image.pixels[f];
				image.pixels[f]=t;
				f-=image.largeur;
				a+=image.largeur;
			}
			j++;
		}

	}
	else
	{
		for(i=0;i<image.hauteur;i++)
		{
			f=(j+1)* image.largeur -1 ;
			a=(j*image.largeur);
			while(a<f)	
			{
				t=image.pixels[a];
				image.pixels[a]=image.pixels[f];
				image.pixels[f]=t;
				a++;
				f--;
			}
			j++;
		}
	}

}


void LibererImage(t_image image)
{
	free(image.pixels);
}

int main()
{
	int largeur, hauteur;
	t_image f ;
	f.hauteur=500;
	f.largeur=400;
	//const char * nf = "guadalest.pgm";
	
	//f= CreerImage(largeur, hauteur);
	f.pixels = LireImagePGM("guadalest.pgm",&largeur,&hauteur);
	//Degrade(f, largeur, hauteur);
	//Seuillage(f, 127);
	Negatif(f);
	Miroir(f,MIROIR_HORIZONTAL);
	EcrireImagePGM("noir.pgm", f.pixels, f.largeur, f.hauteur);
	AfficherImage("noir.pgm");
	
	LibererImage(f);
	return EXIT_SUCCESS;
}
