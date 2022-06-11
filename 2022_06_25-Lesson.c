#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define FD_WRITE 1
#define FD_READ 0

int main()
{
	const int size = 32;
	int x,r;
	int fp[2];
	const char *text = "This is a test";
	char buffer[size];

	/* initialize the buffer */
	for( x=0; x<size; x++ )
		buffer[x] = 0;

	/* create the pipe */
	r = pipe(fp);
	if( r==-1 )
	{
		perror("Pipe");
		exit(1);
	}

	/* write to the pipe */
	r = write(fp[FD_WRITE], text, strlen(text) );
	printf("Wrote '%s', %d bytes\n",text,r);
	/* read from the pipe */
	r = read(fp[FD_READ], buffer, size );
	printf("Read '%s', %d bytes\n",buffer,r);

	return(0);
}
