#include<stdio.h>
#include<stdlib.h>

#define DEBUG 0
#define OK 0
#define ERREUR 1

typedef struct Image 
{ 
  unsigned char* pixels ; 
  unsigned int largeur ; 
  unsigned int hauteur ; 
} t_image ;

t_image CreerImage(int largeur, int hauteur)
{
	t_image f;
	f.pixels=malloc((15+largeur*hauteur)*sizeof(unsigned char));
	f.hauteur=hauteur;
	f.largeur=largeur;
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
