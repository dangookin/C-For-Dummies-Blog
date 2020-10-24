#include <stdio.h>

int main()
{
	int prime,x,count;

	prime = 2;
	while(prime<100)
	{
		/* find factors */
		count = 0;
		printf("%d:",prime);
		for( x=2; x<prime; x++ )
		{
			if( prime%x == 0 )
			{
				count++;
			}
		}
		printf("%d\n",count);
		prime++;
	}

	return(0);
}
