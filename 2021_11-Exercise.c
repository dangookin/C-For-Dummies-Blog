#include <stdio.h>
#include <math.h>

int main()
{
	int a,b;

	for( a=0; a<7; a++ )
	{
		for( b=1; b<=5; b++ )
		{
			printf("%d^%d = %4.0f\t",a,b,pow(a,b));
		}
		putchar('\n');
	}

	return(0);
}
