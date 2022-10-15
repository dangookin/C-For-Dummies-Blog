#include <stdio.h>

int main()
{
	const char filename[] = "/dev/random";
	const int size = 10;
	FILE *dr;
	int c,x;

	dr = fopen(filename,"r");
	if( dr )
	{
		for( x=0; x<size; x++ )
		{
			c = fgetc(dr);
			printf("Random value: %d\n",c);
		}
		fclose(dr);
	}
	return(0);
}
