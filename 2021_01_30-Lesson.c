#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *filename;
	
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

	printf("Filename '%s' specified\n",filename);

	return(0);
}
