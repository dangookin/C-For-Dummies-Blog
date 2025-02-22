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

	/* reverse the elements */
	for( x=0; x<(size/2); x++ )
	{
		save = a[x];
		a[x] = a[size-x-1];
		a[size-x-1] = save;
	}

	/* output the array */
	for( x=0; x<size; x++ )
		printf(" %d",a[x]);
	putchar('\n');

	return 0;
}
