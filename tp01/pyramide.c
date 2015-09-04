#include <stdio.h>
#include <stdlib.h>


void AfficheCar(int n, char c)
{
	int i;
	for(i=1; i<=n ; i++) 
	putchar(c);

}


int main(int argc, char * argv[]) 

{

	int i ;
	int j=1 ;
	for(i=1 ; i<=atoi(argv[1]) ; i++)
	{
		AfficheCar(atoi(argv[1])-i,' ');
		AfficheCar(j,argv[2][0]);
		printf("\n");
		j+=2;
	}

	return EXIT_SUCCESS;
}
 
