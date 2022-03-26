#include <stdio.h>

double babylonian_sr(double root)
{
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
