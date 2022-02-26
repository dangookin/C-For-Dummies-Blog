#include <stdio.h>

int main()
{
	const int size = 7;
	int numerator[size] = { 28, 13, 14, 1, 9, 276, 4 };
	int denominator[size] = { 42, 52, 91, 50, 15, 23, 100 };
	int x;

	for( x=0; x<size; x++ )
	{
		/* output the original fraction */
		printf("%d/%d\n",numerator[x],denominator[x]);
	}

	return(0);
}
