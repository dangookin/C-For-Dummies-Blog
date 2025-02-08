#include <stdio.h>
#include <math.h>

int main()
{
	double p,i;

	p = modf(M_PI,&i);

	printf("%f is %f and %f\n",
			M_PI,
			i,
			p
		  );

	return 0;
}
