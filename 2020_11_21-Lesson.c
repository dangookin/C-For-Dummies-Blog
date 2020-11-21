#include <stdio.h>

double phi(double p, int precision)
{
	while(precision)
		return( p + 1/phi(p, precision-1) );
	return(p);
}

int main()
{
	double gr;

	gr = phi(1.0,15);
	printf("The golden radio is %f\n",gr);

	return(0);
}
