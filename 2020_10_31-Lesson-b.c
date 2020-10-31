#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main()
{
	int prime,x,isprime;

	prime = 2;
	while(prime<100)
	{
		isprime = TRUE;
		for( x=2; x<prime; x++ )
		{
			if( prime%x == 0 )
			{
				isprime=FALSE;
				break;
			}
		}

		if( isprime )
			printf(" %d",prime);

		prime++;
	}
	putchar('\n');

	return(0);
}
