#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52

int draw(int d[]);

int main()
{
	int deck[CARDS];
	int x,c;

	/* seed the randomizer */
	srand((unsigned)time(NULL));

	/* initialize the deck */
		/* 0 = card not drawn
		   1 = card drawn */
	for( x=0; x<CARDS; x++)
		deck[x] = 0;

	c = draw(deck);
	printf("You drew the %d\n",c);

	return(0);
}

int draw(int d[])
{
	int r;
	/* search for an available card */
	while(1)
	{
		r = rand() % CARDS;
		if( d[r] == 0 )
			break;
	}

	d[r] = 1;
	
	return(r);
}
