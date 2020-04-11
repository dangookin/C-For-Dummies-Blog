#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	const char filename[] = "gettysburg.txt";
	FILE *fp;
	int fdes,ch;

	/* open the file to get a file descriptor */
	fdes = open(filename,O_RDONLY);
	if( fdes==-1 )
	{
		fprintf(stderr,"Unable to open %s for unformatted input\n",filename);
		exit(1);
	}

	/* use the descriptor to open the file for streamed input */
	fp = fdopen(fdes,"r");
	if( fp==NULL )
	{
		fprintf(stderr,"Unable to open %s for streamed input\n",filename);
		exit(1);
	}

	/* read the file using formatted input */
	while( !feof(fp) )
	{
		ch = fgetc(fp);
		if( ch==EOF )
			break;
		putchar(ch);
	}

	/* close the open files */
	fclose(fp);
	close(fdes);

	return(0);
}
