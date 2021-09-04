#include <stdio.h>

int main()
{
	int *p;

	p = (int *)malloc( 1024 );
	if( p==NULL )
		printf("malloc() failed\n");
	else
		printf("malloc() succeeded\n");

	return(0);
}
