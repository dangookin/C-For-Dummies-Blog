#include <stdio.h>
#include <stdlib.h>

/* concatenate two integer arrays */
int *intarrayadd(int *a, int asize, int *b, int bsize)
{
	int *c,larger,smaller,x;

	/* allocate for the larger array */
	larger = asize > bsize ? asize : bsize;
	/* and get the smaller size as well */
	smaller = larger > asize ? asize : bsize;

	/* allocate storage for new array */
	c = malloc( sizeof(int) * (larger) );

	/* add if the allocate in successfull */
	if( c!=NULL )
	{
		/* copy up to the size of the
		   smaller array */
		for( x=0; x<smaller; x++ )
			*(c+x) = *(a+x) + *(b+x);

		/* just copy over the remaining values
		   from the larger array */
		if( asize==larger )
		{
			/* use existing value of x */
			/* array 'a' is larger */
			for( ; x<larger; x++ )
				*(c+x) = *(a+x);
		}
		else
		{
			/* array 'b' is larger */
			for( ; x<larger; x++ )
				*(c+x) = *(b+x);
		}
	}

	return(c);
}

int main()
{
	int a[] = { 11, 22, 33, 44, 55 };
	int b[] = { 89, 78, 67, 56, 45, 1, 2, 3 };
	int as,bs,x,*add,larger;

	/* obtain array sizes */
	as = sizeof(a)/sizeof(int);
	bs = sizeof(b)/sizeof(int);

	/* show array a */
	printf("Array 'a':");
	for( x=0; x<as; x++ )
		printf(" %d",a[x]);
	putchar('\n');

	/* show array b */
	printf("Array 'b':");
	for( x=0; x<bs; x++ )
		printf(" %d",b[x]);
	putchar('\n');

	/* add the two arrays */
	add = intarrayadd(a,as,b,bs);
	if( add!=NULL )
	{
		larger = as > bs ? as : bs;
		printf("Result: ");
		for( x=0; x<larger; x++ )
			printf(" %d",*(add+x));
		putchar('\n');
	}
	else
	{
		puts("Array manipulation error");
	}

	return(0);
}

