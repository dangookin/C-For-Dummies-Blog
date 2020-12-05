#include <stdio.h>

int main()
{
	int x,i,s,n,t,max;
	int nuggets[100];

	/* initialize array */
	for( x=0; x<100; x++ )
		nuggets[x] = 1;

	/* find the McNuggets number */
	i = 0;
	while( i<100 )
	{
		/* loop through sixes first */
		for( s=0; s*6<i; s++ )
		{
			if( s*6 == i )
				nuggets[i] = 0;
			/* nines loop */
			for( n=0; n*9<i; n++ )
			{
				if( s*6 + n*9 == i )
					nuggets[i] = 0;
				/* twenties loop */
				for( t=0; t*20<i; t++ )
				{
					if( s*6 + n*9 + t*20 == i )
						nuggets[i] = 0;
				}
			}
		}
		i++;
	}

	/* find largest value McNuggets number */
	max = 0;
	for( x=0; x<100; x++ )
	{
		if( nuggets[x]==1 )
			max = x;
	}
	printf("Maximum non-McNuggets number is %d\n", max);

	return(0);
}
