#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 9
#define CENTER 4

struct location {
	int x;
	int y;
};

/* output the grid */
	/* no array is used. Instead, the grid is output
	   based on the SIZE value and marking the king's
	   location */
void show_grid(int t, struct location m)
{
	int x,y;

	if( t == 0 )
		puts("Start!");
	else
		printf("Turn %d:\n",t);

	for(x=0;x<SIZE;x++)
	{
		for(y=0;y<SIZE;y++)
		{
			if( x==m.x && y==m.y )
				printf(" X ");
			else
				printf(" . ");
		}
		putchar('\n');
	}
}

/* Generate one of three direction options: 1, 0, or -1 */
int direction(void)
{
	int r;

	r = rand() % 3;
	/* get to -1, 0, and 1 */
	r--;
	return(r);
}

int main()
{
	int turn;
	enum { FALSE, TRUE };
	struct location king = { CENTER, CENTER };

/* initialization */
	/* seed the randomizer */
	srand( (unsigned)time(NULL) );
	/* start with turn zero */
	turn = 0;

	/* show the starting grid */
	show_grid(turn,king);
	/* loop until the king wanders out */
	while(1)
	{
		turn++;
		king.x += direction();
		king.y += direction();
		if( king.x<0 || king.x>SIZE || king.y<0 || king.y>SIZE)
			break;
		show_grid(turn,king);
	}
	printf("The king wandered out after %d turns\n",turn);

	return(0);
}
