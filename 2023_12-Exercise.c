#include <stdio.h>
#include <math.h>

double tetrate(double a, int b)
{
	double c = 0.0;

	while(b--)
		return(c = pow(a,tetrate(a,b)));
	return(c);
}

int main()
{
	int b,e;
	double r;

	printf("Base: ");
	scanf("%d",&b);
	printf("Exponent: ");
	scanf("%d",&e);

	if( e<2 )
	{
		printf("Please specify a value larger than 2\n");
	}
	else
	{
		r = tetrate((double)b,e+1);
		printf("%d^^%d = %.f\n",b,e,r);
	}

	return(0);
}
