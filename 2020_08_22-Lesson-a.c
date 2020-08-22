#include <stdio.h>

int main()
{
	const int size = 10;
	float v[size] = { 0.0 };

	puts("Array Dump");
	for(int x = 0; x<size; x++ )
		printf("%2d: %f\n",x+1, v[x] );

	return(0);
}
