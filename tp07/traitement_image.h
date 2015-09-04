#ifndef image_h		// habituellement, on utilise le nom du module suivi de _h
#define image_h 





void AfficherImage(char *nomFichier);

void Seuillage(t_image image,  unsigned char seuil);

void Degrade(t_image image);

void Negatif (t_image image);

void Miroir( t_image  image, char type);

void LibererImage(t_image image);

#endif
