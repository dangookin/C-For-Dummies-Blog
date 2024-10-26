#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 0
#endif

int main()
{
	int x;

	
	if( _POSIX_C_SOURCE >= 200112L )
	{
		srandom( (unsigned)time(NULL) );
		puts("The random() function:");
		for( x=0; x<10; x++ )
			printf("%ld\n",random());
	}
	else
	{
		srand( (unsigned)time(NULL) );
		puts("The rand() function:");
		for( x=0; x<10; x++ )
			printf("%d\n",rand());
	}

	return 0;
}
