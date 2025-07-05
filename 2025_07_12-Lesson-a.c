#include <stdio.h>

#define BASE36_MAX 36
#define SIZE 10

/* generate a base 36 value */
char *base36_string(int *v)
{
	static char b36_string[SIZE+1];
	int x,y;

	/* build base 36 string */
	y = SIZE-1;
	for( x=0; x<SIZE-1; x++ )
	{
		if( *(v+y)<10 )
			b36_string[x] = *(v+y)+'0';
		else
			b36_string[x] = *(v+y)+'A'-10;
		y--;
	}
	b36_string[x] = '\0';

	return(b36_string);
}

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

	/* output the result in base 36 */
	printf("%s\n",base36_string(b36_values));

	/* clean-up */
	return 0;
}
