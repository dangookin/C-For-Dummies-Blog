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

/* look in the current column `c` for a star */
int scan_column(char *g,int r,int c)
{
	int scandown;

	for( scandown=r+1; scandown<ROWS; scandown++ )
	{
		if( *(g+scandown*COLS+c) == '*' )
			return(scandown);
	}
	return(0);
}

int find_right(char *g,int r1,int c1,int r2)
{
	int f;

	for( f=c1+1; f<COLS; f++ )
	{
		if( *(g+r1*COLS+f)=='*' && *(g+r2*COLS+f)=='*' )
			return f;
	}
	return(0);
}

int main()
{
	char *grid;
	int row,col,r,c,count;

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

	count = 0;
	/* scan for two in a column */
	for( row=0; row<ROWS-1; row++ )
	{
		for( col=0; col<COLS; col++ )
		{
			/* find a star in the row */
			if( *(grid+row*COLS+col) == '*' )
			{
				/* look for a matching star in the same column */
				r = scan_column(grid,row,col);
				if(r)
				{
					c = find_right(grid,row,col,r);
					if(c)
					{
						count++;
						printf("%2d %02d:%02d - %02d:%02d\n",
								count,row,col,row,c);
						printf("   %02d:%02d - %02d:%02d\n",
								r,col,r,c);
					}
				}
			}
		}
	}

	return 0;
}
