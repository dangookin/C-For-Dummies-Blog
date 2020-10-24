#include <stdio.h>

int main()
{
	int prime,x;

	prime = 2;
	while(prime<100)
	{
		/* find factors */
		printf("%d:",prime);
		for( x=2; x<prime; x++ )
		{
			if( prime%x == 0 )
			{
				printf(" %d",x);
			}
		}
		prime++;
		putchar('\n');
	}

	return(0);
}
