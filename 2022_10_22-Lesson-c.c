#include <stdio.h>

int main()
{
	const char filename[] = "/dev/random";
	const int size = 10;
	FILE *dr;
	int r[size];
	int x;

	dr = fopen(filename,"r");
	if( dr )
	{
		fread(&r,sizeof(int),size,dr);
		for( x=0; x<size; x++ )
		{
			printf("Random value: %d\n",r[x]);
		}
		fclose(dr);
	}
	return(0);
}
