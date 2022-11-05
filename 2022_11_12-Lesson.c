#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8
#define COLOR_WHITE "\x1b[30;47m"
#define COLOR_CYAN "\x1b[30;46m"
#define COLOR_OFF "\x1b[0m"

void chess_board(int k)
{
	char board[SIZE*SIZE];
	int x,row,col,pos;

	/* initialize the board and set the knight */
	for( x=0; x<SIZE*SIZE; x++ )
	{
		/* obtain knight's position and set */
		if( k == x )
			board[x] = 'K';
		else
			board[x] = ' ';
	}

	/* output the board */
	for( row=0; row<SIZE; row++ )
	{
		for( col=0; col<SIZE; col++ )
		{
			/* obtain the true offset */
			pos = row*SIZE + col;
			/* set the square character */
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

int main()
{
	int knight;

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );

	/* pluck out a random square
	   for the knight */
	knight = rand() % (SIZE*SIZE);

	/* output the board */
	chess_board(knight);

	return(0);
}
