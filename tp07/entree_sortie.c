#include<stdio.h>
#include<stdlib.h>
#include"images.h"

t_image *CreerImage(int largeur, int hauteur)
{
	t_image *f = malloc(sizeof(t_image));
	f->pixels=malloc((15+largeur*hauteur)*sizeof(unsigned char));
	f->hauteur=hauteur;
	f->largeur=largeur;
	return f;

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
	t_image *image;
	
	
	if(f!=NULL)
	{
		fseek(f, 3 , SEEK_SET);
		fscanf(f,"%d %d",&largeur, &hauteur);
		image = CreerImage(largeur, hauteur);
		fread(image->pixels-5, (image->largeur*image->hauteur*sizeof(unsigned char)), 1, f);
		fclose(f);
		return image;
	}	
	else
		return NULL;

}
