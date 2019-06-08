#include <stdio.h>

int main()
{
	char string[] = "Of all the gin joints in the world...\n";
	int x;

	x = 0;
	while( string[x] )
	{
		putchar( string[x] );
		x++;
	}

	return(0);
}

