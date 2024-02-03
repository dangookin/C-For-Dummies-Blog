#include <stdio.h>
#include <stdlib.h>

int main()
{
	extern char **environ;

	while( *environ )
	{
		printf("%s\n",*environ);
		environ++;
	}

	return 0;
}
