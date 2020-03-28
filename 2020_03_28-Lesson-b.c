#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	const char filename[] = "gettysburg.txt";
	int fdes;
	char buffer[1];
	size_t r;

	/* open the file for unformatted input */
	fdes = open(filename,O_RDONLY);
	if( fdes==-1 )
	{
		fprintf(stderr,"Unable to open %s\n",filename);
		return(1);
	}

	/* output the buffer */
	while(1)
	{
		/* read raw data one byte at a time */
		r = read( fdes, buffer, 1 );
		if( r==0 )	/* end of file */
			break;
		if( r==-1 )	/* file read error */
		{
			fprintf(stderr,"File read error\n");
			break;
		}
		putchar( buffer[0] );
	}

	/* close the file */
	close(fdes);

	return(0);
}
