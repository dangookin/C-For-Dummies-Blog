#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 16
#define COLS ROWS*2
#define PROB 5

int main()
{
	char grid[ROWS][COLS];
	int row,col;

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );

	/* fill the grid */
	for( row=0; row<ROWS; row++ )
	{
		for( col=0; col<COLS; col++ )
		{
			if( rand() % PROB )
				grid[row][col] = '.';
			else
				grid[row][col] = '*';
			putchar(grid[row][col]);
		}
		putchar('\n');
	}

	return 0;
}
