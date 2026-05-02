#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 4
#define COL 3

int main()
{
	int values[ROW][COL];
	int x,y;
	int *a,*r,*c;

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );
	
	/* populate and output the grid */
	for( y=0; y<ROW; y++ )
	{
		for( x=0; x<COL; x++ )
		{
			values[y][x] = rand() % 100;
			printf("[%d][%d] = %2d\t",y,x,values[y][x]);
		}
		putchar('\n');
	}

	/* initialize and use pointer *a */
	a = &values[0][0];
	for( x=0; x<ROW*COL; x++ )
		printf("%2d ",*(a+x) );
	putchar('\n');

	/* nested loop with pointer *a */
	a = &values[0][0];
	for( y=0; y<ROW; y++ )
	{
		for( x=0; x<COL; x++ )
		{
			printf("[%d][%d] = %2d\t",y,x,*(a+(y*COL+x)));
		}
		putchar('\n');
	}

	putchar('\n');		/* visual spacing */

	/* nested loop with pointers *r and *c */
	r = &values[0][0];
	for( y=0; y<ROW; y++ )
	{
		c = r+y*COL;
		for( x=0; x<COL; x++ )
		{
			printf("[%d][%d] = %2d\t",y,x,*(c+x));
		}
		putchar('\n');
	}

	return 0;
}
