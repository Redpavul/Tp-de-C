#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) 

{ 

	if(strlen(argv[2])==1)
		if(argv[2][0]=='x')
			printf("%d * %d = %d",atoi(argv[1]),atoi(argv[3]),atoi(argv[1])*atoi(argv[3])); 
		else if (argv[2][0]=='+')
                        printf("%d + %d = %d",atoi(argv[1]),atoi(argv[3]),atoi(argv[1])+atoi(argv[3]));
		else if (argv[2][0]=='/')
                        printf("%d / %d = %d",atoi(argv[1]),atoi(argv[3]),atoi(argv[1])/atoi(argv[3]));
		else if (argv[2][0]=='-')
                        printf("%d - %d = %d",atoi(argv[1]),atoi(argv[3]),atoi(argv[1])-atoi(argv[3]));
		else 
			printf("Mauvaise saisie de l'opérateur");
	else
		printf("Mauvaise saisie de l'opérateur");

	return EXIT_SUCCESS;
}
