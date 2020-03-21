#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	const char filename[] = "gettysburg.txt";
	int fdes;

	fdes = open(filename,O_RDONLY);
	if( fdes==-1 )
	{
		fprintf(stderr,"Unable to open %s\n",filename);
		return(1);
	}

	printf("'%s' opened for low-level, unformatted reading\n",filename);

	close(fdes);

	return(0);
}
