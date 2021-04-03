#include <stdio.h>

int main()
{
	float n,p,z;

	n = -0.0;
	p = +0.0;
	z = 0.0;

	if( z==z )
		printf("%.3f is equal to zero\n",z);
	if( z==n )
		printf("%.3f is equal to negative zero\n",z);
	if( z==p )
		printf("%.3f is equal to positive zero\n",z);

	return(0);
}
