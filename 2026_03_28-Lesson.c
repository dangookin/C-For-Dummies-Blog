#include <stdio.h>
#include <stdlib.h>

int main()
{
	float decimal;
	int numerator,denominator,diff,larger,smaller;

	/* obtain and validate input */
	printf("Enter decimal value: ");
	scanf("%f",&decimal);
	if( decimal > 1.0 || decimal < 0.0 )
	{
		puts("Please input a value less than 1.0");
		puts("and greater than zero");
		return 1;
	}

	/* configure the numerator and denominator
	   use 100000 based on 'float' precision */
	denominator = 100000;
	numerator = decimal*denominator;

	/*
	   Use Euclid's algorithm to find the least common
	   denomniator and reduce the fraction
	   https://c-for-dummies.com/blog/?p=5235
	 */
	/* calculate differences between the larger and smaller values */
	larger = numerator>denominator ? numerator : denominator;
	smaller = numerator<denominator ? numerator : denominator;
	diff = larger-smaller;
	/* keep calculating until the common denominator is found */
	while( diff!=larger )
	{
		larger = smaller>diff ? smaller : diff;
		smaller = smaller==larger ? diff : smaller;
		diff = larger-smaller;
	}

	printf("%f is the fraction %d/%d\n",
			decimal,
			numerator/diff,
			denominator/diff
		  );

	return 0;
}
