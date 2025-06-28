#include <stdio.h>

#define BASE36_MAX 36
#define SIZE 10

int main()
{
	long b36_powers[SIZE];
	int x;

	/* build the powers table */
	for( x=0; x<SIZE; x++ )
		b36_powers[x] = x ? b36_powers[x-1]*BASE36_MAX : 1;

	/* output the powers table */
	for( x=0; x<SIZE; x++ )
		printf("36^%d = %ld\n",x,b36_powers[x]);

	/* clean-up */
	return 0;
}
