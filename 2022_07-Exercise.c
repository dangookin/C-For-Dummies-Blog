#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *leftpad(char *s, int width)
{
	int size,x;
	char *buffer;
	char *b;

	/* calculate the final string size */
	size = strlen(s) + width;
	
	/* allocate storage for the buffer */
	buffer = malloc( sizeof(char) * size + 1 );
	if( buffer==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	/* pad the left end with spaces */
	b = buffer;
	for( x=0; x<width; x++ )
	{
		*b = ' ';
		b++;
	}

	/* append the string */
	strcpy(b,s);

	/* return the result */
	return(buffer);
}

int main()
{
	const int count=5;
	char test_string[]="string";
	int pad[count] = { 5, 10, 0, -3, 1 };
	int x;

	for( x=0; x<count; x++ )
		printf("Pad %3d = %s\n",pad[x],leftpad(test_string,pad[x]) );

	return(0);
}
