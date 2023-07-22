#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

char *token(char *s)
{
	static char space[] = " ";
	static char newline[] = "\n";
	static char tab[] = "\t";

	/* test for special strings */
	if( strcmp(s,"END")==0 )
		return(NULL);
	if( strcmp(s,"SP")==0 )
		return(space);
	if( strcmp(s,"NL")==0 )
		return(newline);
	if( strcmp(s,"TB")==0 )
		return(tab);

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
		s = realloc(s,strlen(s) + strlen(b));
		if( s==NULL )
		{
			fprintf(stderr,"Reallocation error\n");
			exit(1);
		}
		strcat(s,b);
	}

	/* output results */
	puts(s);

	return(0);
}
