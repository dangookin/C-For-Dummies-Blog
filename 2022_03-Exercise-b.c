#include <stdio.h>
#include <stdlib.h>

int main()
{
	const int size = 7;
	int numerator[size] = { 28, 13, 14, 1, 9, 276, 4 };
	int denominator[size] = { 42, 52, 91, 50, 15, 23, 100 };
	int x,diff,larger,smaller;

	for( x=0; x<size; x++ )
	{
		/* output the original fraction */
		printf("%d/%d ",numerator[x],denominator[x]);

		/* calculate differences between the larger and smaller values */
		larger = numerator[x]>denominator[x] ? numerator[x] : denominator[x];
		smaller = numerator[x]<denominator[x] ? numerator[x] : denominator[x];
		diff = larger-smaller;
		/* keep calculating until the common denominator is found */
		while( diff!=larger )
		{
			larger = smaller>diff ? smaller : diff;
			smaller = smaller==larger ? diff : smaller;
			diff = larger-smaller;
		}

		/* if the difference is more than 1, the fraction can be reduced */
		if( diff>1 )
		{
			printf("is simplified to %d/%d\n",
					numerator[x]/diff,
					denominator[x]/diff
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
