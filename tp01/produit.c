#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i;
	int j;

	printf("Multiplication de deux nombre, nombre n°1"); 
	scanf("%d",&i);
	printf("Nombre n°2");
	scanf("%d",&j);
	printf("%d * %d = %d \n",i,j,i+j);
	return EXIT_SUCCESS;
}
