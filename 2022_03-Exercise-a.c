#include <stdio.h>
#include <stdlib.h>

#define BUFFER_LIMIT 100

/* build an array of factors for value 'v' */
void factors(int *f,int v)
{
	int x,offset;

	/* loop through values 2 through 'v' */
	offset = 0;
	for( x=2; x<=v; x++ )
	{
		/* save a factor (divides evenly) */
		if( v%x == 0 )
		{
			*(f+offset) = x;
			offset++;
			/* halt upon overflow */
			if( offset==BUFFER_LIMIT )
			{
				fprintf(stderr,"Buffer overflow\n");
				exit(1);
			}
		}
	}
	/* cap the last item in the array */
	*(f+offset) = 0;
}

/* return the largest value shared between arrays 'n' and 'd' */
int maxfactor(int *n, int *d)
{
	int max,x,y;

	max = 0;
	x = 0;
	while( *(n+x) )
	{
		y = 0;
		while( *(d+y) )
		{
			if( *(n+x) == *(d+y) )
			{
				if( *(n+x) > max )
					max = *(n+x);
			}
			y++;
		}
		x++;
	}

	return(max);
}

int main()
{
	const int size = 7;
	int numerator[size] = { 28, 13, 14, 1, 9, 276, 4 };
	int denominator[size] = { 42, 52, 91, 50, 15, 23, 100 };
	int numerator_factors[BUFFER_LIMIT];
	int denominator_factors[BUFFER_LIMIT];
	int x,m;

	for( x=0; x<size; x++ )
	{
		/* output the original fraction */
		printf("%d/%d ",numerator[x],denominator[x]);

		/* obtain factors for the numerator and denominator */
		factors(numerator_factors,numerator[x]);
		factors(denominator_factors,denominator[x]);

		/* obtain the maximum common factor */
		m = maxfactor(numerator_factors,denominator_factors);

		if( m )
		{
			/* reduce the fraction */
			printf("is simplified to %d/%d\n",
					numerator[x]/m,
					denominator[x]/m
				  );
		}
		else
		{
			/* the fraction cannot be reduced */
			puts("cannot be simplified");
		}
	}

	return(0);
}
