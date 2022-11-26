#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 8
#define KM 8
#define COLOR_WHITE "\x1b[30;47m"
#define COLOR_CYAN "\x1b[30;46m"
#define COLOR_OFF "\x1b[0m"

/* the chessboard */
int board[SIZE*SIZE];

/* output the chessboard */
void chess_board(void)
{
	int row,col,pos;
	const int vwidth = 3;	/* value width */
	char value[vwidth];		/* knight move number */

	/* output the board */
	for( row=0; row<SIZE; row++ )
	{
		for( col=0; col<SIZE; col++ )
		{
			/* obtain the true offset */
			pos = row*SIZE + col;
			if( board[pos]== -1 )
				strcpy(value,"  ");
			else
				snprintf(value,vwidth,"%2d",board[pos]);

			/* plot the square and color */
			if( row%2 )
			{
				if( col%2 )
					printf("%s%s",COLOR_WHITE,value);
				else
					printf("%s%s",COLOR_CYAN,value);
			}
			else
			{
				if( col%2 )
					printf("%s%s",COLOR_CYAN,value);
				else
					printf("%s%s",COLOR_WHITE,value);
			}
		}
		printf("%s",COLOR_OFF);
		putchar('\n');
	}
}

/* plot the knight moves
   k = position
   m[] = array to hold potential moves */
void moveto(int k, int m[])
{
	struct position {
		int row;
		int col;
	};
	/* offsets to move the knight */
	struct position pairs[KM] = {
		{ -2,-1 }, { -2, 1 }, { -1, -2 }, { -1, 2 },
		{ 1, -2 }, { 1, 2 }, { 2, -1 }, { 2, 1 }
	};
	int x,krow,kcol,r,c;

	/* calculate knight's row and column
	   to make later calculations more
	   readable */
	kcol = k % SIZE;
	krow = (k - kcol)/SIZE;
	/* plot the potential knight moves
	   up to KM (8) of them */
	for( x=0; x<KM; x++ )
	{
		/* find new square position */
		r = krow + pairs[x].row;
		c = kcol + pairs[x].col;
		/* check for valid moves */
		if( (r<0 || r>=SIZE) || (c<0 || c>=SIZE) )
		{
			/* square is out of bounds */
			m[x] = -1;
		}
		else
		{
			/* plot position */
			m[x] = r * SIZE + c;
			/* confirm that square hasn't
			   already been occupied */
			if( board[m[x]] > -1 )
				m[x] = -1;
		}
	}
}

/* count the valid moves
   m[] = array of move counts,
   -1 value for no move */
int movecount(int m[])
{
	int x,count;

	count = 0;
	/* scan the array and tally values
	   zero or greater (non -1) */
	for( x=0; x<KM; x++ )
	{
		if( m[x] >= 0 )
			count++;
	}

	return(count);
}

/* move the knight
   s = square to move to
   return the next square, the one
   with the least number of next-moves */
int knight_move(int s)
{
	int x,lowest,newpos;
	int moves[KM],next[KM],tally[KM];
	struct plot {
		int square;
		int count;
	} nextmove[KM];

	/* calculate where the piece can move */
	moveto(s,moves);
	/* calculate next moves */
	for( x=0; x<KM; x++ )
	{
		/* only plot valid moves */
		if( moves[x] != -1 )
		{
			moveto(moves[x],next);
			tally[x] = movecount(next);
		}
		else
		{
			/* copy over the -1 */
			tally[x] = moves[x];
		}
	}

	/* build the structure to determine
	   where to move next */
	for( x=0; x<KM; x++ )
	{
		nextmove[x].square = moves[x];
		nextmove[x].count = tally[x];
	}

	/* move the knight to the lowest ranking position */
	lowest = 8;			/* eight is the highest possible value */
	for( x=0; x<KM; x++ )
	{
		/* find the square with the lowest count */
		if( nextmove[x].count<lowest && nextmove[x].count!=-1 )
		{
			lowest = nextmove[x].count;
			newpos = nextmove[x].square;
		}
	}

	return(newpos);
}

/* perform the knight's tour */
int main()
{
	int x,c;

	/* initialize the board */
	for( x=0; x<SIZE*SIZE; x++ )
		board[x] = -1;

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );

	/* pluck out a random square
	   for the knight */
	c = rand() % (SIZE*SIZE);

	/* move around the chess board */
	for( x=0; x<SIZE*SIZE; x++ )
	{
		board[c] = x;
		c = knight_move(c);
		chess_board();
		getchar();
	}

	return(0);
}
