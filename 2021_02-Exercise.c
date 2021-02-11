#include <stdio.h>
#include <stdlib.h>

int main()
{
	char alpha[50], beta[50];
	int x;

	/* initialize the arrays */
	for( x=0; x<50; x++)
	{
		alpha[x] = x+1;
		beta[x] = x+51;
	}

	/* output results */
	for( x=0; x<50; x++)
		printf("%2d\t%2d\n",alpha[x],beta[x]);

	return(0);
}
