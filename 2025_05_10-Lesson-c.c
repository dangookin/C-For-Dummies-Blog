#include <stdio.h>
#include <math.h>
#include <complex.h>

int main()
{
	double complex z;

	z = csqrt(-4.0);
	printf("sqrt(-4.0) = %f + %.0fi\n",creal(z),cimag(z));

	return 0;
}
