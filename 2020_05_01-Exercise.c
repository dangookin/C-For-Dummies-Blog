#include <stdio.h>

/* generate the tic-tac-toe grid */
void output_grid( char *g )
{
	int row;

	for( row=0; row<3; row++)
	{
		printf(" %c %c %c\n",
				*(g+(3*row)),
				*(g+(3*row)+1),
				*(g+(3*row)+2)
			  );
	}
}

/* determine whether the game was won */
char is_winner( char *g )
{
	return(' ');
}

int main()
{
	char *game[6] = {
		"xxoooxxox",
		"o x xox  ",
		"xx oxxooo",
		"o xooox x",
		" xo ox  o",
		"x oxo xox"
	};
	int x,r;

	/* examine all five game results */
	for( x=0; x<6; x++ )
	{
		output_grid( game[x] );
		printf("Game %d: ",x+1);
		r = is_winner( game[x] );
		switch(r)
		{
			case ' ':
				puts("No winner\n");
				break;
			case 'x':
				puts("X wins!\n");
				break;
			case 'o':
				puts("O wins!\n");
				break;
			default:
				puts("Unknown value\n");
		}
	}

	return(0);
}
