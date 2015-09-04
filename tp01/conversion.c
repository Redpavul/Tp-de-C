#include <stdio.h>
#include <stdlib.h>

float celsius(float f);

int main()
{

	printf("----------------------\n");
	printf("Fahrenheit Celsius\n");
	printf("----------------------\n");
	float f ;

	for(f=0; f<=200 ; f+=20)
	{
		printf("%f	%f\n",f,celsius(f));
	}

	return EXIT_SUCCESS;
}


float celsius(float f)
{
	return (f-32)*(5.0/9.0);
}


