#include <stdio.h>

int main()
{
	int x;
	float t;

	t = 1.0;
	for( x=2; x<=1000; x++ )
	{
		t += 1.0 / (float)x;
	}
	printf("The sum of the harmonic series is %.4f\n",t);

	return(0);
}
