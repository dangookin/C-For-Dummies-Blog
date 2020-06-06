/* link with -lm on Linux */
#include <stdio.h>
#include <math.h>

int main()
{
	double e;
	unsigned long count = 4294967295L;

	e = pow( (1.0/(double)count + 1), (double)count );
	printf("The computer calculated %f for %f\n",
			e,
			M_E
		  );

	return(0);
}
