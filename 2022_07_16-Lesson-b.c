#include <stdio.h>
#include <stdlib.h>

int main()
{
	const int range = 5;
	char *buffer = NULL;
	char *text[range];
	size_t size;
	int x;

	/* gather `range` lines of input */
	for( x=0; x<range; x++ )
	{
		printf("Line #%d/%d: ",x+1,range);		/* add one for humans */
		getline( &buffer, &size, stdin );
		text[x] = buffer;
	}

	/* output the text */
	for( x=0; x<range; x++ )
	{
		printf("%s",text[x]);
	}

	return(0);
}
