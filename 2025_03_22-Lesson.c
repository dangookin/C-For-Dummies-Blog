#include <stdio.h>

int main()
{
	const int count = 10;
	int x;

	/* prefixed */
	puts("Prefixed: ++x");
	x = 0;
	while( ++x<count )
		printf("%d\n",x);

	/* postfixed */
	puts("Postfixed: x++");
	x = 0;
	while( x++<count )
		printf("%d\n",x);

	return 0;
}
