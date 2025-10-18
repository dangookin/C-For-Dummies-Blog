#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* allocate storage for ten integers */
int *ten(void)
{
	int *iptr = NULL;

	iptr = malloc( sizeof(int) * 10 );

	return(iptr);
}

int main()
{
	int **tenint = NULL;
	int x,y;

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );

	/* allocate 10 sticks of 10 integers */
	for( y=0; y<10; y++ )
	{
		/* allocate first stick */
		if( tenint==NULL )
		{
			tenint = malloc( sizeof( int *) );
			if( tenint==NULL )
			{
				fprintf(stderr,"Unable to allocate storage\n");
				exit(1);
			}
		}
		else
		/* allocate additional sticks */
		{
			tenint = realloc(tenint, sizeof( int *) * (y+1) );
			if( tenint==NULL )
			{
				fprintf(stderr,"Unable to reallocate storage\n");
				exit(1);
			}
		}
		/* get the storage */
		*(tenint+y) = ten();
		if( *(tenint+y)==NULL )
		{
			fprintf(stderr,"Unable to allocate stick %d\n",y);
			exit(1);
		}
		printf("Stick %d allocated\n",y);

		/* assign the values */
		for( x=0; x<10; x++ )
			*(*(tenint+y)+x) = rand() % 10 + 10*(y+1);
	}

	/* output the results */
	for( y=0; y<10; y++ )
	{
		printf("Stick %d: ",y);
		for( x=0; x<10; x++ )
			printf("%3d ",*(*(tenint+y)+x) );
		putchar('\n');
	}

	/* clean-up */
	for( y=0; y<10; y++ )
		free( *(tenint+y) );
	free(tenint);
	puts("All sticks freed");
	return 0;
}
