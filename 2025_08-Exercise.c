#include <stdio.h>
#include <ctype.h>

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

int main()
{
	char name[32];
	long r;
	int x;

	/* prompt for input */
	printf("Enter your name: ");
	fgets(name,32,stdin);
	/* remove newline and set to uppercase */
	x = 0;
	while(x<32)
	{
		if( name[x]=='\n' )
		{
			name[x] = '\0';
			break;
		}
		name[x] = toupper(name[x]);
		x++;
	}

	/* translate the b36 name into decimal */
	r = b36_decimal(name);
	printf("Base 36 %s in decimal is %ld\n",name,r);

	/* clean-up */
	return 0;
}
