#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* generate random value 1, 2, 3 */
int input(void)
{
	return( rand() % 3 + 1 );
}

int main()
{
	int player,tally,pguess,cguess;

	/* title info */
	puts("21 Game!");
	puts("Whoever reaches 21 first wins");

	/* determine who goes first */
	srand( (unsigned)time(NULL) );
	player = rand() % 2;		/* 0 = computer, 1 = human */

	if( player )
		puts("You go first");
	else
		puts("I go first");

	/* run the game */
	tally = 0;
	cguess = 0;
	while( tally<21 )
	{
		printf("The tally is %d\n",tally);
		if( player )
		{
			printf("Enter 1, 2, or 3: ");
			scanf("%d",&pguess);
			if( pguess < 1 || pguess>3 )
			{
				printf("Out of range value. Let me guess for you: ");
				pguess = input();
				printf("+%d\n",pguess);
			}
			tally += pguess;
			player = 0;
		}
		else
		{
			if( tally>=18 )
				cguess = 21 - tally;
			else
				cguess = rand() % 3 + 1;
			printf("Me: +%d\n",cguess);
			tally += cguess;
			player = 1;
		}
	}
	/* conclusion */
	if( player )
		puts("I win!");
	else
		puts("You win!");

	return(0);
}
