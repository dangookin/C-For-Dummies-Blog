#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int guess,number,tries;

	/* intialize stuff */
	srand( (unsigned)time(NULL) ); 	/* seed the randomizer */
	tries = 6;
	number = rand() % 100 + 1;		/* range is 1 to 100 */

	/* loop to process input */
	while( tries )
	{
		printf("You have %d tries left\n",tries);
		printf("Guess the number, 1 to 100: ");
		scanf("%d",&guess);
		/* check for winning condition */
		if( guess==number )
		{
			printf("%d was the number! You won!\n",number);
			break;
		}
		/* update the user */
		if( guess < number )
			printf("%d is too low\n",guess);
		else
			printf("%d is too high\n",guess);
		/* update the exit condition */
		tries--;
	}
	/* if the user lost, inform them */
	if( tries==0 )
	{
		printf("Too bad! You lost\n");
		printf("The number was %d\n",number);
	}

	return(0);
}
