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
	int *tenint = NULL;
	int x;

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );

	/* get the storage */
	tenint = ten();
	if( tenint==NULL )
	{
		fprintf(stderr,"Unable to allocate\n");
		exit(1);
	}
	puts("Storage for 10 integers allocated");

	/* assign the values */
	for( x=0; x<10; x++ )
		*(tenint+x) = rand() % 10 + 10;

	/* output the results */
	for( x=0; x<10; x++ )
		printf("%d\n",*(tenint+x) );

	/* clean-up */
	free(tenint);
	return 0;
}
