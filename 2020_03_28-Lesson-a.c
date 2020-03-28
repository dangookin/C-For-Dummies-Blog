#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define SIZE 2048

int main()
{
	const char filename[] = "gettysburg.txt";
	int fdes,x;
	char buffer[SIZE];
	size_t r;

	/* open the file for unformatted input */
	fdes = open(filename,O_RDONLY);
	if( fdes==-1 )
	{
		fprintf(stderr,"Unable to open %s\n",filename);
		return(1);
	}

	/* read raw data */
	r = read( fdes, buffer, SIZE );
	
	/* output the buffer */
	/* not null character terminated! */
	for( x=0; x<r; x++ )
		putchar( buffer[x] );

	/* close the file */
	close(fdes);

	return(0);
}
