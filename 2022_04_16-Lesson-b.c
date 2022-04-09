#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *buffer;

	buffer = malloc(1024);
	if( buffer==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}
	puts("Memory allocated");

	free(buffer);
	puts("Memory freed");
	return(0);
}
