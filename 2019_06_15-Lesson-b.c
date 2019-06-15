#include <stdio.h>

int main()
{
	char filename[] = "declaration.txt";
	char buffer[2048];
	FILE *fh;
	int r;

	/* open the file */
	fh = fopen(filename,"r");
	if(!fh)
	{
		fprintf(stderr,"Unable to open %s\n",filename);
		return(1);
	}

	r = fread( buffer, 1, 2048, fh );
	printf("%d bytes read\n",r);

	fclose(fh);
	return(0);
}

