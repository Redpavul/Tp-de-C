#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	char ch1[64] = "bonjour" ;
	char ch2[64] = "xxxxxxxxxxxxxxxxx" ; 

	int i= strlen(ch1)-1;
	int j= 0; 

	
	while(i>=0)
	{
		ch2[j]=ch1[i];
		j++;
		i--;
	}
	
	printf("%s\n",ch2);
	
	return EXIT_SUCCESS;
}
