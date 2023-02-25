#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

int main()
{
	int x,y,total;
	int grid[SIZE][SIZE];

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );

	/* populate the grid */
	for( x=0; x<SIZE; x++ )
		for( y=0; y<SIZE; y++ )
			grid[x][y] = rand()%10 + 1;

	/* output the grid and row totals */
	for( x=0; x<SIZE; x++ )
	{
		total = 0;
		for( y=0; y<SIZE; y++ )
		{
			total += grid[x][y];
			printf(" %2d ",grid[x][y]);
		}
		printf("%d\n",total);
	}
	/* output column totals */
	for( x=0; x<SIZE; x++ )
	{
		total = 0;
		for( y=0; y<SIZE; y++ )
			total += grid[y][x];
		printf(" %2d ",total);
	}
	putchar('\n');

	return(0);
}
