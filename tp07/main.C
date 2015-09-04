#include<stdio.h>
#include<stdlib>





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
