#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

int main()
{
	char *b,*s;

	/* allocate/initialize buffers */
	b = malloc( SIZE * sizeof(char) );	/* input */
	s = malloc( sizeof(char) );			/* string */
	if( b==NULL || s==NULL )
	{
		fprintf(stderr,"Memory allocation error\n");
		exit(1);
	}
	/* initialize string storage */
	*b = *s = '\0';

	while(1)
	{
		/* fetch input */
		printf("Word: ");
		scanf("%s",b);
		if( strcmp(b,"END")==0 )
			break;
		/* copy the word */
			/* add two: space and null char */
		s = realloc(s,strlen(s) + strlen(b) + 2);
		if( s==NULL )
		{
			fprintf(stderr,"Reallocation error\n");
			exit(1);
		}
		strcat(s,b);
		strcat(s," ");
	}

	/* output results */
	puts(s);

	return(0);
}
