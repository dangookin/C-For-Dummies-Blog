#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52

int main()
{
	int deck[CARDS];
	int x;

	/* seed the randomizer */
	srand((unsigned)time(NULL));

	/* initialize the deck */
		/* 0 = card not drawn
		   1 = card drawn */
	for( x=0; x<CARDS; x++)
		deck[x] = 0;

	return(0);
}
