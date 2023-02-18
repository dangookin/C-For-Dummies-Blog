#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

int main()
{
	int x,y;
	int grid[SIZE][SIZE];

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );

	/* populate the grid */
	for( x=0; x<SIZE; x++ )
		for( y=0; y<SIZE; y++ )
			grid[x][y] = rand()%10 + 1;

	/* output the grid */
	for( x=0; x<SIZE; x++ )
	{
		for( y=0; y<SIZE; y++ )
			printf(" %d ",grid[x][y]);
		putchar('\n');
	}

	return(0);
}
