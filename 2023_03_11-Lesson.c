#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

int main()
{
	int x,y;
	int a[SIZE][SIZE],b[SIZE][SIZE],c[SIZE][SIZE];

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );

	/* populate the grids */
	for( x=0; x<SIZE; x++ )
		for( y=0; y<SIZE; y++ )
		{
			a[x][y] = rand()%10 + 1;
			b[x][y] = rand()%10 + 1;
		}

	/* generate grid c */
	for( x=0; x<SIZE; x++ )
		for( y=0; y<SIZE; y++ )
			c[x][y] = a[x][y] + b[x][y];

	/* output the grids - side by side */
	for( x=0; x<SIZE; x++ )
	{
		/* grid a */
		for( y=0; y<SIZE; y++ )
			printf(" %2d ",a[x][y]);
		putchar('\t');

		/* grid b */
		for( y=0; y<SIZE; y++ )
			printf(" %2d ",b[x][y]);
		putchar('\t');

		/* grid c */
		for( y=0; y<SIZE; y++ )
			printf(" %2d ",c[x][y]);
		putchar('\n');
	}

	return(0);
}
