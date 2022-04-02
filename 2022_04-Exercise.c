#include <stdio.h>

double babylonian_sr(double root)
{
	double low,high;
	int x;
	const int precision = 7;

	low = 1.0;
	high = root;
	for( x=0; x<precision; x++ )
	{
		high = (high+low)/2.0;
		low = root/high;
	}
	return(low);
}

int main()
{
	double pv,sr;

	printf("Enter a positive value: ");
	scanf("%lf",&pv);
	if( pv <= 0 )
		return(1);
	sr = babylonian_sr(pv);
	printf("The square root of %.0f is %f\n",
			pv,
			sr
		  );

	return(0);
}
