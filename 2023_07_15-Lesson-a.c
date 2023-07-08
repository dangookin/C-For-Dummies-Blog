#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

int main()
{
	char *b,*s;

	/* allocate/initalize buffers */
	b = malloc( SIZE * sizeof(char) );	/* input */
	s = malloc( SIZE * sizeof(char) );	/* string */
	if( b==NULL || s==NULL )
	{
		fprintf(stderr,"Memory allocation error\n");
		exit(1);
	}
	/* initialize string storage */
	*b = *s = '\0';

	/* fetch input */
	printf("Word: ");
	scanf("%s",b);
	/* copy the word */
	strcpy(s,b);

	/* output results */
	puts(s);

	return(0);
}
