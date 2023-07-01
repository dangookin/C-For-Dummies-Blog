#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char buffer[16];
	char *s;

	scanf("%s",buffer);
	/* allocate buffer for word */
	s = malloc( strlen(buffer)+1 * sizeof(char) );
	if( s==NULL )
	{
		fprintf(stderr,"Memory allocation error\n");
		exit(1);
	}
	/* copy the word */
	strcpy(s,buffer);

	/* output results */
	puts(s);

	return(0);
}
