#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 16
#define COLS ROWS*2
#define SIZE COLS*ROWS
#define PROB 5

struct rect {
	int top;
	int bottom;
	int left;
	int right;
};

int main()
{
	char grid[ROWS][COLS];
	int row,col,count,x;
	struct rect r,all[SIZE];

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );

	/* fill and show the grid */
	puts("Original grid:");
	for( row=0; row<ROWS; row++ )
	{
		for( col=0; col<COLS; col++ )
		{
			if( rand() % PROB )
				putchar( grid[row][col] = '.');
			else
				putchar( grid[row][col] = '*');
		}
		putchar('\n');
	}

	count = 0;
	/* scan for two in a column */
	for( r.top=0; r.top<ROWS-1; r.top++ )
	{
		for( r.left=0; r.left<COLS; r.left++ )
		{
			/* find a star in the row */
			if( grid[r.top][r.left] == '*' )
			{
				/* look for a matching star in the same column */
				for( r.bottom=r.top+1; r.bottom<ROWS; r.bottom++ )
				{
					if( grid[r.bottom][r.left] == '*' )
					{
						for( r.right=r.left+1; r.right<COLS; r.right++ )
						{
							if( grid[r.top][r.right]=='*' && grid[r.bottom][r.right]=='*' )
							{
								/* add the grid to the array */
								all[count] = r;
								count++;
							}
						}
					}
				}
			}
		}
	}

	/* build the full grid */
	for( x=0; x<count; x++ )
	{
		for( row=0; row<ROWS; row++ )
		{
			for( col=0; col<COLS; col++ )
			{
				if(
						(row==all[x].top && (col>all[x].left && col<all[x].right) ) ||
						(row==all[x].bottom && (col>all[x].left && col<all[x].right) )
				  )
					if( grid[row][col] == '.' )
						grid[row][col] = '-';
				if(
						(col==all[x].left && (row>all[x].top && row<all[x].bottom) ) ||
						(col==all[x].right && (row>all[x].top && row<all[x].bottom) )
					   )
					if( grid[row][col] == '.' )
						grid[row][col] = '|';
			}
		}
	}

	/* output the final grid */
	printf("Found %d rectangles\n",count);
	for( row=0; row<ROWS; row++ )
	{
		for( col=0; col<COLS; col++ )
			putchar( grid[row][col] );
		putchar('\n');
	}

	return 0;
}
