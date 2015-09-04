#ifndef image_h
#define image_h 


t_image* LireImagePGM(const char* nomFichier);

int EcrireImagePGM(const char* nomFichier, t_image image);

_image CreerImage(int largeur, int hauteur);



