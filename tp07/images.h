#ifndef images_h
#define images_h

typedef struct Image 
{ 
  unsigned char* pixels ; 
  unsigned int largeur ; 
  unsigned int hauteur ; 
} t_image ;

#define ERREUR 1
#define OK 0
#define DEBUG 0

#endif
