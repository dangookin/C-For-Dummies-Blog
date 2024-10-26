#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int x;

#ifdef _POSIX_C_SOURCE	
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
#else
	srand( (unsigned)time(NULL) );
	puts("The rand() function:");
	for( x=0; x<10; x++ )
		printf("%d\n",rand());
#endif	

	return 0;
}
