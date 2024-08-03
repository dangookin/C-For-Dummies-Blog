#include <stdio.h>

int main( int argc, char *argv[] )
{
	FILE *fh;
	char buffer[BUFSIZ],*r,*filename;
	int line;

	/* check for the command line argument */
	if( argc<2 )
	{
		fprintf(stderr,"Please specify a file to examine\n");
		return 1;
	}

	/* open the file */
	filename = argv[1];		/* for readability */
	fh = fopen(filename,"r");
	if ( fh==NULL )
	{
		fprintf(stderr,"Unable to open file '%s'\n",filename);
		return 1;
	}

	/* read seven lines */
	for( line=0; line<7; line++ )
	{
		r = fgets(buffer,BUFSIZ,fh);
		if( r==NULL )
		{
			printf("File '%s' lacks a seventh line\n",filename);
			fclose(fh);
			return 1;
		}
	}

	/* output result */
	printf("The seventh line of file '%s' is:\n%s",
			filename,
			buffer
		  );

	/* clean-up */
	fclose(fh);
	return 0;
}
