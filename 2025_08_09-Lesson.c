#include <stdio.h>
#include <math.h>

int main()
{
	int x;
	double b;

	for( x=0; x<64; x++ )
	{
		b = exp( (double)x/20.0 );
		printf("%f\n",b);
	}

	return 0;
}
