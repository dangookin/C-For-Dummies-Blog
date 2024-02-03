#include <stdio.h>
#include <stdlib.h>

int main()
{
	puts("Search path:");
	printf("%s\n",getenv("PATH"));

	return 0;
}
