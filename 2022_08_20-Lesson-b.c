#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
	long d;
	int l,r;
	long value;

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );

	/* obtain the random value */
	value = rand();

	/* obtain a random value length */
	r = rand() % 11;

	/* truncate the value */
	value %= (int)pow(10,r);

	/*
		now count the digits, which will end
		up being the same value as 'r', but
		what-the-hey
	*/
	l=d=1;
	while( d<=10000000000 )
	{
		if( value<d )
		{
			printf("%ld is %d digits long\n",value,l-1);
			break;
		}
		d*=10;
		l++;
	}

	return(0);
}
