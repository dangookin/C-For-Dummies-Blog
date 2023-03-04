#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

int *merge(int *a, int *b, int s)
{
	int *r,offset,index;

	/* allocate maximum stroage */
	r = malloc( sizeof(int) * s * 2 );

	if( r!=NULL )
	{
		offset = index = 0;
		while( offset<s*2 )
		{
			r[offset++] = *(a+index);
			r[offset++] = *(b+index);
			index++;
		}
	}
	return(r);
}

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

	c = merge(a,b,SIZE);
	printf("Merged: ");
	for( x=0; x<SIZE*2; x++ )
		printf(" %2d",c[x]);
	putchar('\n');
	return(0);
}
