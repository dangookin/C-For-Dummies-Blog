#include <stdio.h>

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int size,x,save;

	/* obtain array size */
	size = sizeof(a)/sizeof(a[0]);

	/* output the array */
	for( x=0; x<size; x++ )
		printf(" %d",a[x]);
	putchar('\n');

	/* shuffle to the left */
		/* retain the first element */
	save = a[0];
		/* move over all remaining elements */
	for( x=0; x<size-1; x++ )
		a[x] = a[x+1];
		/* restore the first element to the last pos. */
	a[size-1] = save;

	/* output the array */
	for( x=0; x<size; x++ )
		printf(" %d",a[x]);
	putchar('\n');

	return 0;
}
