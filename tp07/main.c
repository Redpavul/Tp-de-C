#include<stdio.h>
#include<stdlib.h>
#include "images.h"
#include "entree_sortie.h"
#include "traitement_image.h"




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
