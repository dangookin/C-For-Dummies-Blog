#include <stdio.h>

#define SIZE 1000

int main()
{
	int factors[SIZE];
	int v,x,max;

	/* determine the factors */
	v = 1;
	while(v<SIZE)
	{
		factors[v] = 1;
		for( x=1; x<v; x++ )
		{
			if( v%x == 0 )
			{
				factors[v]++;
			}
		}
		v++;
	}

	/* obtain the greatest factor */
	max = 0;
	for( x=1; x<SIZE; x++ )
	{
		if( factors[x]>max )
			max = factors[x];
	}

	/* Show the highest factors */
	/* This also accounts for multiple values */
	for( x=1; x<SIZE; x++ )
	{
		if( factors[x]==max )
			printf("%d has %d factors\n",x,max);
	}

	return(0);
}
