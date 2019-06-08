#include <stdio.h>

int main()
{
	char string[] = "Of all the gin joints in the world...\n";
	int x;

	for( x=0; string[x]; x++)
	{
		putchar( string[x] );
	}

	return(0);
}

