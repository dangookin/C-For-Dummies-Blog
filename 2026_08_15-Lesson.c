#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	char filename[] = "test.txt";
	int fd1,fd2;

	/* open/create the file */
	fd1 = creat(filename,0);
	if( fd1==-1 )
	{
		fprintf(stderr,"Unable to create %s\n",filename);
		perror("ERROR: ");
		exit(1);
	}

	/* duplicate the file descriptor */
	fd2 = dup(fd1);
	if( fd2==-1 )
	{
		fprintf(stderr,"Unable to duplicate the file handle\n");
		perror("ERROR: ");
		close(fd1);
		exit(1);
	}


	/* write data to the file */
	write(fd1,"Hello, ",7);
	write(fd2,"world!\n",8);

	/* clean-up */
	close(fd2);
	close(fd1);
	return 0;
}
