#include <stdio.h>

int sign(int a)
{
	/* value is negative */
	if( a<0 ) return(-1);

	/* value is positive */
	if( a>0 ) return(1);

	/* value is zero */
	return(0);
}

int main()
{
	int values[20] = { -34, 27, 0, 48, -25, 28, -55,
		66, -17, -78, 0, -20, 40, -98, 63, -44, 59,
		6, 65, 90
	};
	int x;

	for( x=0; x<20; x++ )
	{
		printf("Sign of %3d is ", values[x] );
		switch( sign( values[x] ))
		{
			case -1:
				puts("negative");
				break;
			case 1:
				puts("positive");
				break;
			case 0:
				puts("zero");
				break;
			default:
				puts("unknown");
		}
	}

	return(0);
}
