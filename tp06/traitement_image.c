#include<stdio.h>
#include<stdlib.h>
//#include "entree_sortie.h"

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


t_image CreerImage(int largeur, int hauteur)
{
	t_image f;
	f.pixels=malloc((15+largeur*hauteur)*sizeof(unsigned char));
	f.hauteur=hauteur;
	f.largeur=largeur;
	return f;

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

int EcrireImagePGM(const char* nomFichier, t_image image)
{
	FILE* f;
	f=fopen(nomFichier,"w");
	if(f!=NULL)
	{

		fprintf(f,"P5\n%d %d\n255\n", image.largeur, image.hauteur);
		fwrite(image.pixels, (image.largeur*image.hauteur*sizeof(unsigned char)),1, f);
		
		
		fclose(f);
		return OK;

	}
	else
	{
		return ERREUR;
	}
}

t_image* LireImagePGM(const char* nomFichier)
{
	FILE* f= fopen(nomFichier,"r");
	int largeur = 0 ;
	int hauteur = 0 ;
	t_image image;
	
	
	if(f!=NULL)
	{
		fseek(f, 3 , SEEK_SET);
		fscanf(f,"%d %d",&largeur, &hauteur);
		image = CreerImage(largeur, hauteur);
		fread(image.pixels, (image.largeur*image.hauteur*sizeof(unsigned char)), 1, f);
		fclose(f);
		t_image* retour = &image;
		return retour;
	}	
	else
		return NULL;

}


int main()
{
	t_image* f ;
	//t_image image;
	//int i ;
	//image.hauteur=80;
	//image.largeur=100;
	//const char * nf = "guadalest.pgm";
	
	//f= CreerImage(f.largeur, f.hauteur);
	f = LireImagePGM("voiron.pgm");
	//for(i=0; i<f[0].largeur*f[0].hauteur-1; i++)
	//{
	//	f[0].pixels[i]=255;
	//}
	//Degrade(f, largeur, hauteur);
	//Seuillage(f, 127);
	//Negatif(f[0]);
	//Miroir(f,MIROIR_HORIZONTAL);
	EcrireImagePGM("test.pgm", f[0]);
	AfficherImage("test.pgm");
	
	LibererImage(f[0]);
	return EXIT_SUCCESS;
}
