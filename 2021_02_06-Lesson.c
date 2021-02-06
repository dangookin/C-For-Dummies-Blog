#include <stdio.h>
#include <stdlib.h>

/* copy and convert the digits */
char *convert( char *s, int size )
{
	int x;
	static char buffer[5];
	char c;

	/* avoid buffer overflow */
	if( size > 4 )
	{
		fprintf(stderr,"Buffer overflow: %d\n",size);
		exit(1);
	}

	/* process the given number of characters */
	for( x=0; x<size; x++ )
	{
		c = *(s+x);
		if( c=='.' || c=='\0' )
		{
			fprintf(stderr,"Malformed filename\n");
			exit(2);
		}
		buffer[x] = c;
	}
	buffer[x] = '\0';

	return(buffer);
}

int main(int argc, char *argv[])
{
	char *filename;
	int year, month, day;
	
	/* check for filename argument */
	if( argc<2 )
	{
		/* output error message to standard error */
		fprintf(stderr,"Filename option required\n\n");
		/* leave with exit code 1*/
		exit(1);
	}
	/* assign to pointer for convenience */
	filename = argv[1];

	/* code to confirm that the file exists goes here */
	/* ... */
	
	/* extract integers. */
	year = strtol(convert(filename+0,4),NULL,10);
	month = strtol(convert(filename+4,2),NULL,10);
	day = strtol(convert(filename+6,2),NULL,10);

	/* output results */
	printf("%4d %2d %2d\n",year,month,day);

	return(0);
}
