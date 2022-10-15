#include <stdio.h>

int main()
{
	const char filename[] = "/dev/random";
	FILE *dr;
	double r;

	dr = fopen(filename,"r");
	if( dr )
	{
		fread(&r,sizeof(double),1,dr);
		printf("Random value: %f\n",r);
		fclose(dr);
	}
	return(0);
}
