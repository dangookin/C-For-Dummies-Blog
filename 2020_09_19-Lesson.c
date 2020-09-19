#include <stdio.h>
#include <stdlib.h>

/* a simple file dumper */
int main(int argc, char *argv[])
{
	FILE *dumpme;
	int c;

	/* check for filename */
	if( argc < 2 )
	{
		puts("Format: dumper filename");
		exit(1);
	}

	/* open and process file */
	dumpme = fopen(argv[1],"r");
	if( dumpme==NULL )
	{
		printf("Unable to read %s\n",argv[1]);
		exit(2);
	}

	while((c=fgetc(dumpme)) != EOF)
		printf("%02X ",c);
	putchar('\n');

	fclose(dumpme);

	return(0);
}
