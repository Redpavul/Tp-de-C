#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char ** argv) 

{ 
	
	int i,j,b;
	int s = 0;
	int p = 0 ;
	
	for(i=strlen(argv[1])-1;i>=0;i--)
	{
		
		b=1;
		if(argv[1][i]=='1')
		{
			if(p>0)
			{
				for(j=0;j<=p;j++)
				{	
					b *= 2;
				}
			}
			s += b;
		}
		p++;
	}
	printf("<%s>2 = <%d>10",argv[1],s);

	return EXIT_SUCCESS;
}
