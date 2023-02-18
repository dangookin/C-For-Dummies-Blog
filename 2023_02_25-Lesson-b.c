#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

int main()
{
	int x;
	int *grid;

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );

	/* allocate the grid */
	grid = malloc( sizeof(int) * SIZE * SIZE );
	if( grid==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}

	/* populate the grid */
	for( x=0; x<SIZE*SIZE; x++ )
		*(grid+x) = rand()%10 + 1;

	/* output the grid */
	for( x=0; x<SIZE*SIZE; x++ )
	{
		printf(" %d ",*(grid+x));
		if( (x+1)%SIZE == 0 )
			putchar('\n');
	}

	free(grid);
	return(0);
}
