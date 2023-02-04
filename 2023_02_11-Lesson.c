#include <stdio.h>
#include <stdlib.h>

/* concatenate two integer arrays */
int *intarraycat(int *a, int asize, int *b, int bsize)
{
	int *c,x;

	/* allocate storage for new array */
	c = malloc( sizeof(int) * (asize+bsize) );

	/* concatenate upon success */
	if( c!=NULL )
	{
		/* copy first array */
		for( x=0; x<asize; x++ )
			*(c+x) = *(a+x);
		/* copy second array */
		for( x=0; x<bsize; x++ )
			*(c+x+asize) = *(b+x);
	}

	return(c);
}

int main()
{
	int a[5] = { 11, 22, 33, 44, 55 };
	int b[6] = { 89, 78, 67, 56, 45, 1 };
	int as,bs,x,*cat;

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

	/* concatenate and output */
	cat = intarraycat(a,as,b,bs);
	if( cat!=NULL )
	{
		printf("Result: ");
		for( x=0; x<as+bs; x++ )
			printf(" %d",*(cat+x));
		putchar('\n');
	}
	else
	{
		puts("Concatenation error");
	}

	return(0);
}

