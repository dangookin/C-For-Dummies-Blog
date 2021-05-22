#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *filename;

	if( argc > 1 )
	{
		filename = argv[1];
	}
	else
	{
		fprintf(stderr,"Filename argument required\n");
		exit(1);
	}
	
	printf("The filename is %s\n",filename);

	return(0);
}
