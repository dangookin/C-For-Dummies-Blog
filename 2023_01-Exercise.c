#include <stdio.h>

int main(int argc, char *argv[])
{
	char *filename;
	FILE *fh;
	long size;
	
	/* check for filename argument */
	if( argc<2 )
	{
		puts("Specify a filename");
		return(1);
	}

	/* operate from the first argument */
	filename = argv[1];

	fh = fopen(filename,"r");
	if( fh==NULL )
	{
		fprintf(stderr,"Unable to open %s\n",filename);
		return(1);
	}

	fseek( fh, 0, SEEK_END );
	size = ftell(fh);
	fclose(fh);

	printf("%s is %ld bytes long\n",filename,size);

	return(0);
}
