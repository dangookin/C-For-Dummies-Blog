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
	char r;
	int x;

	/* check diagonals first */
		/* NW-SE */
	if( *(g+0)==*(g+4) && *(g+4)==*(g+8) )
	{
		r = *(g+0);
		if( r=='x' || r=='o' )
			return(r);
	}
		/* SW-NE */
	if( *(g+6)==*(g+4) && *(g+4)==*(g+2) )
	{
		r = *(g+6);
		if( r=='x' || r=='o' )
			return(r);
	}

	/* check columns */
	for( x=0; x<3; x++ )
	{
		if( *(g+0+x)==*(g+3+x) && *(g+3+x)==*(g+6+x) )	
		{
			r = *(g+0+x);
			if( r=='x' || r=='o' )
				return(r);
		}
	}

	/* check rows */
	for( x=0; x<3; x++ )
	{
		if( *(g+(3*x))==*(g+(3*x)+1) && *(g+(3*x)+1)==*(g+(3*x)+2) )
		{
			r = *(g+(3*x));
			if( r=='x' || r=='o' )
				return(r);
		}
	}

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
