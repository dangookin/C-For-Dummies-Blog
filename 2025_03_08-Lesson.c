#include <stdio.h>

int main()
{
	char *a[] = { "alfa", "bravo", "charlie",
		"delta", "echo", "foxtrot", "golf",
		"hotel"
	};
	char *save;
	int size,x;

	/* obtain array size */
	size = sizeof(a)/sizeof(a[0]);

	/* output the array */
	for( x=0; x<size; x++ )
		printf(" %s",a[x]);
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
		printf(" %s",a[x]);
	putchar('\n');

	return 0;
}
