#include <stdio.h>
#include <unistd.h>

int main()
{
#ifndef _POSIX_VERSION
	puts("This system is most likely not POSIX (Unix/Linux)");
#else
	printf("This system is POSIX standard %ld\n",_POSIX_VERSION);
#endif

	return(0);
}
