#include <stdio.h>
#include <stdlib.h>
int main() 

{
	int a;
	int i;
	printf("Quelle table de multiplication voulez vous?\n");
	scanf("%d",&a);
	
	for(i=0 ; i <= 10 ;i++)
	{
		printf("%d * %d = %d \n",i,a,i*a);
	}
	
	return EXIT_SUCCESS;
}	
