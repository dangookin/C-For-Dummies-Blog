#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

int main()
{
	int knight,row,column;

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );

	/* pick a random square */
	knight = rand() % (SIZE*SIZE);
	printf("The knight is at square %d\n",knight);

	/* calculate row and column */
	column = knight % SIZE;
	row = (knight-column)/SIZE;
	printf("That's row %d, column %d\n",row,column);

	return(0);
}
