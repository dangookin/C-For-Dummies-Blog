#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	FILE *fp;
	int count,c;
	char *file;

	/* check for filename argument */
	if( argc<2 )
	{
		fprintf(stderr,"Specify a filename\n");
		exit(1);
	}
	/* open the file */
	file = argv[1];		/* shortcut */
	fp = fopen(file,"r");
	if( fp==NULL )
	{
		fprintf(stderr,"Can't open '%s'\n",file);
		exit(1);
	}
	printf("Examining '%s'...\n",file);

	/* scan for and count non-ASCII characters */
	count = 0;
	while(!feof(fp))
	{
		c = fgetc(fp);
		if( c==EOF )
			break;
		if((unsigned char)c > 127 )
			count++;
	}

	/* close file and output results */
	fclose(fp);
	printf("%d non-ASCII characters found\n",
			count,
		  );

	return(0);
}

