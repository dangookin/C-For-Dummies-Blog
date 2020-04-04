#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { LEGAL, DIVIDEDBY, NINE };

int no_nine(int n)
{
	char number[16];
	int r,t;

	t = LEGAL;		/* it's zero */

	/* is the number divisible by nine? */
	if( n % 9 == 0 )
		t += DIVIDEDBY;

	/* convert the number into a string */
	r = snprintf(number,16,"%d",n);
		/* test for overflow, though the size 16 is
		   beyond the range of a standard int value */
	if( r > 16 )
	{
		fprintf(stderr,"Number overflow\n");
		exit(1);
	}

	/* does the digit 9 appear in the number? */
	if( strchr(number,'9') != NULL )
		t += NINE;

	/* no nines found */
	return(t);
}

int main()
{
	int x,r;

	for( x=1; x<=100; x++ )
	{
		r = no_nine(x);

		if( r == LEGAL )
			printf("%3d is legal\n",x);
		else
		{
			printf("%3d is illegal - ",x);
			if( r == DIVIDEDBY+NINE )
				printf("divisible by 9 and contains '9'\n");
			else if ( r == DIVIDEDBY )
				printf("divisible by 9\n");
			else
				printf("contains '9'\n");
		}
	}

	return(0);
}
