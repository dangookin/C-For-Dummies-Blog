#include <stdio.h>

#define COUNT 100
#define TRUE 1
#define FALSE 0

int main(void)
{
	int n,i,c,a,index,isprime;
	int primes[COUNT];
	
	printf("The first %d primes:\n\n",COUNT);

/* initialize */
	index = 0;						/* set index for array */
	primes[index] = 2;				/* start with 2 as the first prime */
	a = 1;							/* set counter */

/* calculate the first COUNT prime numbers */
	while(index<COUNT)
	{
		n = primes[index] + a;		/* next value after last known prime */
									/* is n prime? */
		isprime=TRUE;				/* Assume it is prime for now */

		for(i=0;i<index;i++)		/* divide n by all recorded primes */
		{
			c = n/primes[i];
			if(n == primes[i]*c)	/* if TRUE, n is not prime */
			{
				isprime=FALSE;
				break;				/* this saves time */
			}
			if(primes[i] > (n>>1))	/* Save time by eliminating divisors */
				break;				/* greater than n/2 */
		}

		if(isprime)					/* the value is prime */
		{
			index++;
			primes[index] = n;		/* add it to the array */
			a = 1;					/* set number scan to next number */
		}
		else
			a++;					/* jump to text next value */
									/* the value of a indicates the
									   space between primes. It will never be
									   <2 but can get quite large */
	}

/* display the results */
	for(i=0;i<COUNT;i++)
		printf("%5d\t",primes[i]);
	printf("\n\n");

	return 0;
}
