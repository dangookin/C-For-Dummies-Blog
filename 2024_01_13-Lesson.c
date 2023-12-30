#include <stdio.h>

int main()
{
	int a[5] = {};

	for( int x=0; x<5; x++ )
		printf("a[%d] = %d\n",x,a[x]);

	return 0;
}
