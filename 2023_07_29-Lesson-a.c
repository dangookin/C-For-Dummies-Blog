#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

char *token(char *s)
{
	/* test for special strings */
	if( strcmp(s,"END")==0 )
		return(NULL);

	return(s);
}

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

	/* fetch input */
	printf("Type some Text: ");
	while(1)
	{
		scanf("%s",b);
		b = token(b);
		if( !b )	/* NULL */
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
