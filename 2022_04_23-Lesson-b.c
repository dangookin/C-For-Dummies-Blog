#include <stdio.h>
#include <stdlib.h>

void memory(void)
{
	char *p;

	p = malloc(1024*1024*1024);		/* 1GB */
	if( p==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}
	free(p);
}

int main()
{
	int x;

	for( x=0; x<1024; x++ )
	{
		printf("%4d - Allocating memory: ",x);
		memory();
		printf("done!\n");
	}

	return(0);
}
