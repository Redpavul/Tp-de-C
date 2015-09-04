#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* StringDup(char* s)
{
	int i;
	char* temp=malloc(strlen(s)*sizeof(char)+1);
	for(i=0;i<strlen(s);i++)
	{
		temp[i]=s[i];
	}

	return *temp;
}

int main()

{

	char chaine[] = "exemple de chaine à copier";
	char *copie;


}
