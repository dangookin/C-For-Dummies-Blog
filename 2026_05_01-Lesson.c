#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 4
#define COL 3

int main()
{
	int values[ROW][COL];
	int x,y;

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );
	
	/* populate and output the grid */
	for( y=0; y<ROW; y++ )
	{
		for( x=0; x<COL; x++ )
		{
			values[y][x] = rand() % 100;
			printf("[%d][%d] = %d\t",y,x,values[y][x]);
		}
		putchar('\n');
	}

	return 0;
}
