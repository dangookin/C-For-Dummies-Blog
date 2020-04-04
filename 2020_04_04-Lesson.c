#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	char filename[] = "file_output.txt";
	char text[] = "What a lovely little file\n";
	int fdes,r;

	/* open the file for writing and creating */
	fdes = open(filename,O_WRONLY|O_CREAT);
	if( fdes==-1 )
	{
		fprintf(stderr,"Unable to create %s\n",filename);
		return(1);
	}

	/* write the buffer */
	r = write( fdes, text, sizeof(text)-1 );
	if( r != sizeof(text)-1 )
	{
		fprintf(stderr,"Some kind of file writing error\n");
	}
	/* confirm success */
	printf("Data written to %s\n",filename);

	/* close 'er up */
	close(fdes);

	return(0);
}
