#include <stdio.h>
#include <math.h>
#include <complex.h>

int main()
{
	double complex z;

	z = I * I;
	printf("I * I = %f + %.0fi\n",creal(z),cimag(z));

	return 0;
}
