#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	extern char **environ;

	puts("Search path:");
	while( *environ )
	{
		if( strncmp(*environ,"PATH",4)==0 )
		{
			printf("%s\n",*environ);
			break;
		}
		environ++;
	}

	return 0;
}
