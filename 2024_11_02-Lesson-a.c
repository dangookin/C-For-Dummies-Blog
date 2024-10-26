#include <stdio.h>
#include <stdlib.h>

#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 0
#endif

int main()
{
	/* test for presence of random() function */

	if( _POSIX_C_SOURCE >= 200112L )
		puts("The random() function is available");
	else
		puts("The random() function is not available");

	return 0;
}
