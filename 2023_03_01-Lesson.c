#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

/* merge function goes here */

int main()
{
	int x,a[SIZE],b[SIZE],*c;

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );

	/* populate the arrays, values 0 through 99 */
	for( x=0; x<SIZE; x++ )
	{
		a[x] = rand()%100;
		b[x] = rand()%100;
	}

	/* output the arrays */
	printf("Array 'a': ");
	for( x=0; x<SIZE; x++ )
		printf(" %2d",a[x]);
	putchar('\n');
	printf("Array 'b': ");
	for( x=0; x<SIZE; x++ )
		printf(" %2d",b[x]);
	putchar('\n');

	/* call the merge() function */
	/* output the merged arrays */

	return(0);
}
