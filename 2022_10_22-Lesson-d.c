#include <stdio.h>

int main()
{
	const char filename[] = "/dev/random";
	FILE *dr;
	unsigned long r;

	dr = fopen(filename,"r");
	if( dr )
	{
		fread(&r,sizeof(unsigned long),1,dr);
		printf("Random value: %lu\n",r);
		fclose(dr);
	}
	return(0);
}
