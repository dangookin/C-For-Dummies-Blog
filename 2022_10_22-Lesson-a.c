#include <stdio.h>

int main()
{
	const char filename[] = "/dev/random";
	FILE *dr;
	int c;

	dr = fopen(filename,"r");
	if( dr )
	{
		c = fgetc(dr);
		printf("Random value: %d\n",c);
		fclose(dr);
	}
	return(0);
}
