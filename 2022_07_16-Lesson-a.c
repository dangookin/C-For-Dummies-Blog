#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *buffer = NULL;
	size_t size;
	int r;

	/* repeat until a blank line is input */
	do
	{
		/* prompt and gather input */
		printf("Type: ");
		r = getline( &buffer, &size, stdin );

		/* show input */
		printf("You typed (%d): %s",r,buffer);

	} while( r>1 );

	return(0);
}
