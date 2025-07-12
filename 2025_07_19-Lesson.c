#include <stdio.h>

#define BASE36_MAX 36
#define SIZE 10

/* build the base 36 powers table */
long *base36_powers(void)
{
	static long b36_powers[SIZE];
	int x;

	for( x=0; x<SIZE; x++ )
		b36_powers[x] = x ? b36_powers[x-1]*BASE36_MAX : 1;

	return(b36_powers);
}

/* return decimal value for base 36 string v */
long b36_decimal(char *v)
{
	long *powers,result;
	int x,y,digit;

	/* obtain the powers table */
	powers = base36_powers();

	/* must process the string backwards */
	x = 0;
	while( *(v+x) != '\0' )		/* locate the string's end */
		x++;
	x--;						/* backup to 1's position */

	/* process the digits (x) and powers (y) */
	result = 0;
	y = 0;
	while(x>=0)
	{
		/* translate digit */
		if( *(v+x)>='0' && *(v+x)<='9' )
			digit = *(v+x) - '0';
		else
			digit = *(v+x) - 'A' + 10;
		/* fetch power value */
		result += digit * *(powers+y);
		x--;
		y++;
	}

	return(result);
}

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

	/* eliminate leading zeros */
	while( b36_string[0]=='0' )
	{
		for( x=0; x<SIZE-1; x++ )
			b36_string[x] = b36_string[x+1];
	}

	return(b36_string);
}

int main()
{
	long *powers,r;
	char *b36;
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

	/* fetch the powers table */
	powers = base36_powers();

	/* translate the decimal value */
	for( x=SIZE-2; x>=0; x-- )
		b36_values[x+1] = ( d % *(powers+x+1))/ *(powers+x);

	/* output the result in base 36 */
	b36 = base36_string(b36_values);
	printf("%d in base 36 is %s\n",d,b36);

	/* translate the value back into decimal */
	r = b36_decimal(b36);
	printf("%s in decimal is %ld\n",b36,r);

	/* clean-up */
	return 0;
}
