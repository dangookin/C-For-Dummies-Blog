#include <stdio.h>

int main()
{
	char buffer[BUFSIZ];
	int x = 0;

	while( x<BUFSIZ )
	{
		buffer[x] = '\0';
		x++;
	}
	puts("Buffer initialized");

	return(0);
}
