#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	char filename[] = "test.txt";
	int fd;
	mode_t filemode = O_CREAT | O_WRONLY | O_TRUNC;

	/* open/create the file */
	fd = open(filename,filemode);
	if( fd==-1 )
	{
		fprintf(stderr,"Unable to create %s\n",filename);
		perror("ERROR: ");
		exit(1);
	}

	/* write data to the file */
	write(fd,"Hello!\n",8);

	/* clean-up */
	close(fd);
	return 0;
}
