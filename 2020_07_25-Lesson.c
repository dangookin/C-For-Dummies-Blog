#include <stdio.h>

double square_root(double x)
{
	double y;
	int p,square,c;

	/* find the surrounding perfect squares */
	p = 0;
	do
	{
		p++;
		square = (p+1) * (p+1);
	}
	while( x > square );

	/* process the root */
	y = (double)p;
	c = 0;
	while(c<10)
	{
		/* divide and average */
		y = (x/y + y)/2;
		/* test for success */
		if( y*y == x)
			return(y);
		c++;
	}
	return(y);
}

int main()
{
	double pv,sr;

	printf("Enter a positive value: ");
	scanf("%lf",&pv);
	if( pv <= 0 )
		return(1);
	sr = square_root(pv);
	printf("The square root of %.0f is %f\n",
			pv,
			sr
		  );

	return(0);
}
