#include <stdio.h>

int main()
{
	const int size = 10;
	int v[size];

	/* initialize array */
	for(int x = 0; x<size; x++ )
		v[x] = -1;

	/* output array */
	puts("Array Dump");
	for(int x = 0; x<size; x++ )
		printf("%2d: %d\n",x+1, v[x] );

	return(0);
}
