#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8
#define KM 8
#define COLOR_WHITE "\x1b[30;47m"
#define COLOR_CYAN "\x1b[30;46m"
#define COLOR_OFF "\x1b[0m"

/* output the chessboard
   k = knight's position
   m[] = squares for valid moves */
void chess_board(int k, int m[])
{
	char board[SIZE*SIZE];
	int x,row,col,pos;

	/* initialize the board and set knight */
	for( x=0; x<SIZE*SIZE; x++ )
	{
		/* obtain knight's position and set */
		if( k == x )
			board[x] = 'K';
		else
			board[x] = ' ';
	}
	/* set the potential moves */
	for( x=0; x<KM; x++ )
	{
		if( m[x] != -1 )
		{
			/* set a * where the knight can move */
			board[m[x]] = '*';
		}
	}

	/* output the board */
	for( row=0; row<SIZE; row++ )
	{
		for( col=0; col<SIZE; col++ )
		{
			/* obtain the true offset */
			pos = row*SIZE + col;
			/* plot the square and color */
			if( row%2 )
			{
				if( col%2 )
					printf("%s %c",COLOR_WHITE,board[pos]);
				else
					printf("%s %c",COLOR_CYAN,board[pos]);
			}
			else
			{
				if( col%2 )
					printf("%s %c",COLOR_CYAN,board[pos]);
				else
					printf("%s %c",COLOR_WHITE,board[pos]);
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
		}
	}
}

/* set the knight at a random location */
int main()
{
	int knight;
	int moves[KM];

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );

	/* pluck out a random square
	   for the knight */
	knight = rand() % (SIZE*SIZE);

	/* calculate where the piece can move */
	moveto(knight,moves);

	/* output the board */
	chess_board(knight,moves);

	return(0);
}
