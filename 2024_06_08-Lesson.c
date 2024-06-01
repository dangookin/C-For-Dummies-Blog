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

void output_grid(char *g,struct rect r)
{
	int row,col;

	for( row=0; row<ROWS; row++ )
	{
		for( col=0; col<COLS; col++ )
		{
			if(
					(row==r.top && (col>r.left && col<r.right) ) ||
					(row==r.bottom && (col>r.left && col<r.right) )
			  )
				putchar('-');
			else if(
					(col==r.left && (row>r.top && row<r.bottom) ) ||
					(col==r.right && (row>r.top && row<r.bottom) )
				   )
				putchar('|');
			else
				putchar( *(g+row*COLS+col) );
		}
		putchar('\n');
	}
}

/* look in the current column `c` for a star */
int scan_column(char *g,int top,int left)
{
	int scandown;

	for( scandown=top+1; scandown<ROWS; scandown++ )
	{
		if( *(g+scandown*COLS+left) == '*' )
			return(scandown);
	}
	return(0);
}

int find_right(char *g,int top,int left,int bottom)
{
	int right;

	for( right=left+1; right<COLS; right++ )
	{
		if( *(g+top*COLS+right)=='*' && *(g+bottom*COLS+right)=='*' )
			return right;
	}
	return(0);
}

int main()
{
	char *grid;
	int row,col,count;
	struct rect r;

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

	count = 0;
	/* scan for two in a column */
	for( r.top=0; r.top<ROWS-1; r.top++ )
	{
		for( r.left=0; r.left<COLS; r.left++ )
		{
			/* find a star in the row */
			if( *(grid+r.top*COLS+r.left) == '*' )
			{
				/* look for a matching star in the same column */
				r.bottom = scan_column(grid,r.top,r.left);
				if(r.bottom)
				{
					r.right = find_right(grid,r.top,r.left,r.bottom);
					if(r.right)
					{
						count++;
						printf("Rectangle %d:\n",count);
						output_grid(grid,r);
					}
				}
			}
		}
	}
	printf("Found %d rectangles\n",count);

	return 0;
}
