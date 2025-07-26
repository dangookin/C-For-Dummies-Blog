#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* rolling an 's' sided die */
int roll(int s)
{
	return( rand() % s + 1 );
}

int main()
{
	const int die = 6;
	/* d4, d6, d8, d12, d20, d100 */
	const int sides[] = {
		4, 6, 8, 12, 20, 100
	};
	int d[die],done[die];		/* six different die */
	int x,count,tally;

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );
	/* initialize the done[] array */
	for( x=0; x<die; x++ )
		done[x] = 0;

	/* show results */
	printf("%6s%5s%5s%5s%5s%5s%5s\n",
			" Count","D4","D6","D8","D12","D20","D100"
		  );
	/* throw dem bones! */
	count = 1;
	while(1)
	{
		printf("%5d:",count);
		for( x=0; x<die; x++ )
		{
			d[x] = roll( sides[x] );
			if( d[x]==sides[x] )
				done[x] = 1;
			printf("%5d", done[x] ? sides[x] : d[x] );
		}
		putchar('\n');

		/* test for completion */
		tally = 0;
		for( x=0; x<die; x++ )
			tally += done[x];
		if( tally==die )
			break;		/* end the loop */
		count++;
	}

	/* summary */
	printf("It took %d throws for each die to max out\n",count);

	return 0;
}
