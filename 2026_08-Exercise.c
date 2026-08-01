#include <stdio.h>
#include <math.h>

float root(float a,int count)
{
	while( count-- )
		return( sqrt(1.0+(a+1.0) * root(a+1.0,count)) );
	return(a);
}

int main()
{
	float a = 0.0;

	a = root(1.0,25);
	printf("%f\n",a);

	return 0;
}
