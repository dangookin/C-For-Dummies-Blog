#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 16
#define COLS ROWS*2
#define SIZE COLS*ROWS
#define PROB 5

void output_grid(char *g)
{
	int r,c;

	for( r=0; r<ROWS; r++ )
	{
		for( c=0; c<COLS; c++ )
		{
			putchar( *(g+r*COLS+c) );
		}
		putchar('\n');
	}

}

int main()
{
	char *grid;
	int row,col;

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );

	/* allocate grid */
	grid = malloc( sizeof(char) * SIZE );
	if( grid==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	/* fill the grid */
	for( row=0; row<ROWS; row++ )
	{
		for( col=0; col<COLS; col++ )
		{
			if( rand() % PROB )
				*(grid+row*COLS+col) = '.';
			else
				*(grid+row*COLS+col) = '*';
		}
	}

	/* output the grid */
	output_grid(grid);

	/* close it up */
	free(grid);
	return 0;
}
