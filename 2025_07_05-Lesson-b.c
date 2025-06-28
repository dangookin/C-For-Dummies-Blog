#include <stdio.h>

#define BASE36_MAX 36
#define SIZE 10

int main()
{
	long b36_powers[SIZE];
	int b36_values[SIZE];
	int x,d;

	/* prompt for input */
	printf("Enter base 10 value: ");
	scanf("%d",&d);
	if( d<1 )
	{
		puts("Enter a value larger than zero");
		return 1;
	}

	/* build the powers table */
	for( x=0; x<SIZE; x++ )
		b36_powers[x] = x ? b36_powers[x-1]*BASE36_MAX : 1;

	/* translate the decimal value */
	for( x=SIZE-2; x>=0; x-- )
		b36_values[x+1] = ( d % b36_powers[x+1])/ b36_powers[x];

	/* output the values array */
	for( x=1; x<SIZE; x++ )
		printf("36^%d = %d\n",x,b36_values[x]);

	/* clean-up */
	return 0;
}
