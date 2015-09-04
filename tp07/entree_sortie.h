#ifndef entree_sortie_h
#define entree_sortie_h 


t_image* LireImagePGM(const char* nomFichier);

int EcrireImagePGM(const char* nomFichier, t_image image);

t_image CreerImage(int largeur, int hauteur);


#endif
