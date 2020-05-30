#include <stdio.h>

int main()
{
	const int base = 3;
	int powers[11];
	int x;

	/* create the powers table */
	powers[0] = 1;
	for(x=1;x<11;x++)
	{
		powers[x] = powers[x-1]*base;
	}

	for(x=0;x<11;x++)
		printf("%d^%d = %d\n",base,x,powers[x]);

	return(0);
}
