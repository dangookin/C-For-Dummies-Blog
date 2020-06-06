/* link with -lm on Linux */
#include <stdio.h>
#include <math.h>

int main()
{
	long count;
	double e;

	count = 0;
	while(1)
	{
		count++;
		e = pow( (1.0/(double)count + 1), (double)count );
		if( e==M_E )
			break;
	}
	printf("The computer calculated %f after %ld loops\n",
			e,
			count
		  );

	return(0);
}
