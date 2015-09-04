#include<stdio.h>
#include<stdlib.h>
#include "images.h"
#include "entree_sortie.h"




#define SEUIL_PIXEL(valeur,seuil) (valeur > seuil) ? 0 : 255
#define AFFICHER_FONCTION 



void AfficherImage(char *nomFichier)
{

	char temp[200] = {0} ;
	sprintf(temp,"eog %s &", nomFichier);
	system(temp);

}



void Seuillage(t_image* image,  unsigned char seuil)
{

	int i,j,temp;
	temp=0;
	printf("%s",__func__);
	for(i=0;i<image->hauteur;i++)
	{
		for(j=0;j<image->largeur;j++)
		{
			image->pixels[temp]=SEUIL_PIXEL(image->pixels[temp],seuil);
			temp++;
			

		}
	}

}



void Degrade(t_image* image)
{
	int i,j;
	
	
	
	
		int temp = 0 ;

	for(i=0;i<image->hauteur;i++)
	{
		for(j=0;j<image->largeur;j++)
		{

			image->pixels[j*image->largeur+i]=temp;
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

void Negatif (t_image* image)
{

	int i,j,temp;
	temp=0;
	for(i=0;i<image->hauteur;i++)
	{
		for(j=0;j<image->largeur;j++)
		{

			image->pixels[temp]=255-image->pixels[temp];
			temp++;

		}
	}

}


void Miroir( t_image* image, char type)
{

	int i,a,f;
	unsigned char t;
	int j= 0;
	a=0;


	if(type==1)
	{
		for(i=0;i<image->largeur;i++)
		{
			f=(image->hauteur-1)*(image->largeur-1)+i;
			a=j;

			while(a<f)
			{
				t=image->pixels[a];
				image->pixels[a]=image->pixels[f];
				image->pixels[f]=t;
				f-=image->largeur;
				a+=image->largeur;
			}
			j++;
		}

	}
	else
	{
		for(i=0;i<image->hauteur;i++)
		{
			f=(j+1)* image->largeur -1 ;
			a=(j*image->largeur);
			while(a<f)	
			{
				t=image->pixels[a];
				image->pixels[a]=image->pixels[f];
				image->pixels[f]=t;
				a++;
				f--;
			}
			j++;
		}
	}

}


void LibererImage(t_image* image)
{
	free(image->pixels);
}






