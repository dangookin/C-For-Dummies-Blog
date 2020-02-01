#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int main()
{
	int number,tries;
	int guess_current,guess_high,guess_low;

	/* initialize stuff */
		/* seed randomizer */
	srand( (unsigned)time(NULL) );
		/* try count */
	tries = 0;
		/* generate random value to guess */
	printf("Generating a random number 1 to %d...\n",MAX);
	number = rand() % MAX + 1;
		/* initialize frame */
	guess_high = MAX;
	guess_low = 1;

	printf("Try\tNumber\tGuess\tResult\n");
	while(1)
	{
		tries++;
		/* calculate current guess between the two previous
		   high/low guesses */
		guess_current = (guess_high-guess_low)/2 + guess_low;
		printf("#%d\t%d\t%d\t",
				tries,
				number,
				guess_current
			  );
		/* test for a win */
		if( number==guess_current )
		{
			puts("Correct");
			break;
		}
		/* output results if the guess is wrong */
		if( number < guess_current ) 
		{
			puts("^ high");
			/* adjust high value */
			guess_high = guess_current;
		}
		else
		{
			puts("v low");
			/* adjust low value */
			guess_low = guess_current;
		}
	}

	return(0);
}
