#include <stdio.h>

/* calculate the factorial */
long factorial(long f)
{
	if( f==1 )
		return(f);
	else
		return(f * factorial(f-1));
}

/* calculate the cube */
long cube(long c)
{
	return( c*c*c );
}

int main()
{
	int x;
	float e = 0.0;

	for( x=1; x<50; x++ )
		e += (float)cube(x)/factorial(x);

	printf("%f\n",e/5.0);

	return 0;
}
